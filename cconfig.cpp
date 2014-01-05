#include "cconfig.h"

CConfig::CConfig()
{
}

QList<QString> CConfig::getConfig(QString ConfigFilePath)
{
    QFile file(ConfigFilePath);
    QList<QString> conf;
    QString line;
    if(!file.exists())
    {
        return conf;
    }

    bool ok = file.open(QIODevice::ReadOnly | QIODevice::Text);

    if(!ok)
    {
        return conf;
    }

    line = file.readLine();
    if(line.startsWith("apiid="))
    {
        conf.push_back(line.mid(line.indexOf('=') + 1).trimmed());
    }

    line = file.readLine();
    if(line.startsWith("num="))
    {
        conf.push_back(line.mid(line.indexOf('=') + 1).trimmed());
    }
    return conf;
}
