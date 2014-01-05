#ifndef CCONFIG_H
#define CCONFIG_H

#include <QFile>

class CConfig
{
public:
    CConfig();
    QList<QString> getConfig(QString ConfigFilePath);
};

#endif // CCONFIG_H
