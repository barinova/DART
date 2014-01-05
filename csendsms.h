#ifndef CSENDSMS_H
#define CSENDSMS_H

#include <QString>
#include <QNetworkAccessManager>
#include <QTimer>
#include <QEventLoop>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
class CSendSms
{
    QString URL;
public:
    CSendSms();
    int sendSms(const QString &phoneNumber, QString text, const QString &app_id);
};

#endif // CSENDSMS_H
