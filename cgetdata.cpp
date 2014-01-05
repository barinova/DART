#include "cgetdata.h"

CGetData::CGetData()
{
}

void CGetData::networkConnection(QObject *obj)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    manager->get(QNetworkRequest(QUrl("http://www.ndbc.noaa.gov/data/realtime2/21418.dart")));
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), obj, SLOT(getData(QNetworkReply*)));
}


void CGetData::getInfoFromURL(QNetworkReply *reply)
{
    std::string stringData(reply->readAll());
    parseData(stringData);
}

void CGetData::singleState(std::string yr, std::string mo, std::string dy,
                           std::string hr, std::string mn, std::string s, std::string HEIGHT)
{
    QDateTime time;
    resultData entity;
    QString str;
    str.append(yr.c_str());
    str.append(mo.c_str());
    str.append(dy.c_str());
    str.append(s.c_str());
    str.append(mn.c_str());
    str.append(hr.c_str());
    time = QDateTime::fromString(str, "yyyyMMddhhmmss");
    entity.time = time;
    entity.HEIGHT = ::atof(HEIGHT.c_str());
    data.insert(std::make_pair(data.size(), entity));
}

void CGetData::parseData(std::string stringData)
{
    std::string line;
    int i(0);
    std::istringstream linestream(stringData);

    while(i++ != 3)
    {
        std::getline(linestream, line);
    }

    do
    {
         QRegExp rx("(\\ |\\n)");
         QStringList query = QString(line.c_str()).split(rx);
         singleState(query.at(0).toStdString(), query.at(1).toStdString(), query.at(2).toStdString(),
                     query.at(3).toStdString(), query.at(4).toStdString(), query.at(5).toStdString(),
                     query.at(7).toStdString());
    }while(std::getline(linestream, line));
}

