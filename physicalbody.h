#pragma once

#include <QGraphicsItem>

class PhysicalBody
{
public:
    PhysicalBody(double x = 0, double y = 0, double speed = 0);

    //void SetAvatar(QGraphicsItem* avatar);
    QGraphicsItem* GetAvatar();

    void SetX(double x);
    void SetY(double y);

    void SetSpeed(double speed);

    double GetX();
    double GetY();

    double GetSpeed();

private:
    double _x;
    double _y;

    double _speed;

    QGraphicsItem* _avatar;
};

