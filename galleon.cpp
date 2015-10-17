#include "galleon.h"

Galleon::Galleon(QImage *image)
{
    this->entity = PlyEntity::load("../TP4/galleon.ply");
    this->entity->setScale(0.0001f);
    this->speed = 0.05f;
    this->angle = qrand() % 360;
    this->image = image;
}

void Galleon::update(float delta)
{
    if(waterHeight > 0.01) {
        float x = cos(angle * 0.0174533f) * speed * delta;
        float y = sin(angle * 0.0174533f) * speed * delta;

        this->entity->setPosition(x + this->entity->getX(), y + this->entity->getY(), waterHeight);

        int x1 = (this->entity->getX() + 0.5) * this->image->width();
        int y1 = (this->entity->getY() + 0.5) * this->image->height();

        if(x < -0.5 || y < -0.5 || x > 0.5 || y > 0.5 || qGray(this->image->pixel(x1, y1)) * 0.0008 > this->waterHeight) {
            this->angle += 5;
            if(angle > 360) angle = 0;
        }
        this->entity->setAngle(angle + 90);
    }
}

void Galleon::draw()
{
    entity->draw(0);
}

void Galleon::setWaterHeight(float waterHeight)
{
    this->waterHeight = waterHeight;
}
