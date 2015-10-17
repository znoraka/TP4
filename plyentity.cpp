#include "plyentity.h"

PlyEntity *PlyEntity::load(QString filePath)
{
    QFile file( filePath );
    if(file.size() < 10) return nullptr;
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        return new PlyEntity(stream.readAll().split("\n"));
    }

}

void PlyEntity::draw(float delta)
{
    glColor3f(1, 1, 1);
    for (int i = 0; i < indexes.size(); ++i) {
        QVector<int> v = indexes[i];
        if(v.size() == 3) {
            glBegin(GL_TRIANGLES);
        } else {
            glBegin(GL_QUADS);
        }

        qDebug() << vertices.size();
        for (int j = 0; j < v.size(); ++j) {
            point p = vertices[v[j] * 2];
            point n = vertices[v[j] * 2 + 1];
//            qDebug() << p.x * scale + x << ", " << p.y * scale + y << ", " << p.z * scale + z;
            glVertex3f(p.x * scale + x, p.y * scale + y, p.z * scale + z);
            glNormal3f(n.y, n.z, n.x);
        }

        glEnd();
    }
}

void PlyEntity::update(float delta)
{

}

void PlyEntity::setPosition(float x, float y, float z)
{
    this->x = x; this->y = y; this->z = z;
}

void PlyEntity::setScale(float scale)
{
    this->scale = scale;
}

PlyEntity::PlyEntity(QStringList list)
{
    this->scale = 1;
    if(!list.at(0).compare("ply") == 0) {
        qDebug() << "bad file";
        return;
    }
    int vertexCount = 0, faceCount = 0;
    int cpt = 0;

    while(vertexCount == 0) {
        if(list.at(cpt).startsWith("element vertex")) {
            vertexCount = list.at(cpt).split(" ").last().toInt();
        }
        cpt++;
    }

    while(faceCount == 0) {
        if(list.at(cpt).startsWith("element face")) {
            faceCount = list.at(cpt).split(" ").last().toInt();
        }
        cpt++;
    }

    while(list.at(cpt++).compare("end_header") != 0);

    for (int i = cpt; i < vertexCount + cpt; ++i) {
        QStringList l = list.at(i).split(" ");
        point p, n;
        p.x = l.at(0).toFloat();
        p.y = l.at(1).toFloat();
        p.z = l.at(2).toFloat();
        n.x = l.at(3).toFloat();
        n.y = l.at(4).toFloat();
        n.z = l.at(5).toFloat();
        vertices.push_back(p);
        vertices.push_back(n);
    }

    qDebug() << "vertices ok";

    for (int i = cpt + vertexCount; i < cpt + vertexCount + faceCount; ++i) {
        QVector<int> v;
        QStringList faces = list.at(i).split(" ");
        for (int j = 1; j < faces.size(); ++j) {
            v.push_back(faces.at(j).toInt());
        }
        indexes.push_back(v);
    }
}
