#include "physicalbody.h"
#include "Graphic/graphicrect.h"

PhysicalBody::PhysicalBody(double x, double y, double speed)
    : _x(x)
    , _y(y)
    , _speed(speed)
{
    //_avatar = new GraphicRect(this);
}

void PhysicalBody::Init(double x, double y, double speed,
                        QLabel* labelSpeed, QLabel* labelX, QLabel* labelY)
{
    _x = x; _y = y; _speed = speed;
    _avatar = new GraphicRect(this);

    _avatar->SetLabelSpeed(labelSpeed);
    _avatar->SetLabelX(labelX);
    _avatar->SetLabelY(labelY);
}

GraphicRect* PhysicalBody::GetAvatar()
{
    return _avatar;
}

void PhysicalBody::SetX(double x) { _x = x; }
void PhysicalBody::SetY(double y) { _y = y; }

void PhysicalBody::SetSpeed(double speed) { _speed = speed; }

double PhysicalBody::GetX() { return _x; }
double PhysicalBody::GetY() { return _y; }

double PhysicalBody::GetSpeed() { return _speed; }
