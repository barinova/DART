#ifndef CGETDATA_H
#define CGETDATA_H
#include <QtNetwork>
#include <QObject>
#include <map>
#include <cstdlib>
#include <math.h>
#include <sstream>
//#include <time.h>
#include <ctime>

struct resultData
{
    QDateTime time;
    float HEIGHT;
};

class CGetData
{
public:
    std::map<int,resultData> data;
    CGetData();
    void networkConnection(QObject *obj);
    void getInfoFromURL(QNetworkReply *reply);
    void singleState(std::string yr, std::string  mo, std::string dy,
                     std::string hr, std::string mn, std::string  s, std::string HEIGHT);
    void parseData(std::string stringData);
};

#endif // CGETDATA_H
