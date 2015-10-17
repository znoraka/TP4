#ifndef PLYENTITY_H
#define PLYENTITY_H

#include <QVector>
#include <QString>
#include <QtCore>
#include <QtGui>
#include <QFile>
#include <QDebug>
#include <QtGui/QOpenGLFunctions>

#include <iostream>

#include "utils.h"

class PlyEntity
{
public:
    static PlyEntity *load(QString filePath);
    void draw(float delta);
    void update(float delta);
    void setPosition(float x, float y, float z);
    void setScale(float scale);

private:
    PlyEntity(QStringList list);
    QVector<point> vertices;
    QVector<QVector<int>> indexes;
    float x, y, z, scale;
};

#endif // PLYENTITY_H
