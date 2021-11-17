#pragma once

//#include <QGraphicsItem>
#include "graphicrect.h"

class PhysicalBody
{
public:
    PhysicalBody(double x = 0, double y = 0, double speed = 0);

    void Init(double x, double y, double speed,
                  QLabel* labelSpeed, QLabel* labelX, QLabel* labelY);

    //void SetAvatar(QGraphicsItem* avatar);
    GraphicRect* GetAvatar();

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

    GraphicRect* _avatar = nullptr;
};

