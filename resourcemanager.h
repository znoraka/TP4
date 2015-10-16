#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <QString>
#include <QVector>
#include <functional>

struct data {
    void *valuePtr;
    std::function<QString()> toString;
};

class ResourceManager
{
public:
    static QString serialize(QVector<data> vec);
    static data FLOAT(float *value);
    static data INT(int *value);
    static data BOOL(bool *value);
};

#endif // RESOURCEMANAGER_H
