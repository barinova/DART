#include "csendsms.h"

CSendSms::CSendSms()
{
    URL = "http://sms.ru/sms/send?api_id=%1&to=%2&text=%3";
}

int CSendSms::sendSms(const QString &phoneNumber, QString text, const QString &app_id)
{

    bool ok;
    int errorCode;
    QEventLoop loop;

    QNetworkAccessManager manager;

    text.replace(' ', '+');

    const QString request = URL.arg(app_id, phoneNumber, text);

    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()) );

    QNetworkReply * reply = manager.get(QNetworkRequest(QUrl(request)));

    loop.exec();

    if(!reply->isFinished())
    {
        reply->abort();
        reply->deleteLater();
        return -1;
    }

    QByteArray response = reply->readAll();

    int len = response.indexOf("\n");
    if(len < 0 && !response.isEmpty())
    {
        len = response.length();
    }

    errorCode = response.left(len).toInt(&ok);
    if(!ok) return -1;

    return errorCode;
}
