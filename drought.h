#ifndef DROUGHT_H
#define DROUGHT_H

#include <QtGui/QOpenGLFunctions>
#include <QDebug>

#include "resourcemanager.h"

class Drought
{
public:
    Drought();
    void update(float delta);
    float getYellow() const;
    float getSnowHeightModifier() const;
    void setActive(bool active);

    QVector<data *> attributes();

private:
    float yellow;
    float snowHeight;
    bool isActive;
};

#endif // DROUGHT_H
