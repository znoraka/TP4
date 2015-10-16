#include "resourcemanager.h"

QString ResourceManager::serialize(QVector<data> vec)
{
    QString s = "";
    for (int i = 0; i < vec.size(); ++i) {
        s += vec[i].toString();
    }
    return s;
}

data ResourceManager::FLOAT(float *value)
{
    data d;
    d.valuePtr = value;
    d.toString = [=]() {
        QString s = "FLOAT:";
        return  s + QString::number(*value) + ";";
    };
    return d;
}

data ResourceManager::INT(int *value)
{
    data d;
    d.valuePtr = value;
    d.toString = [=]() {
        QString s = "INT:";
        return  s + QString::number(*value) + ";";
    };
    return d;
}

data ResourceManager::BOOL(bool *value)
{
    data d;
    d.valuePtr = value;
    d.toString = [=]() {
        QString s = "BOOL:";
        return  s + ((*value) ? "true" : "false") + ";";
    };
    return d;
}
