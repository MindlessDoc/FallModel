#include "physicalbody.h"
#include "graphicrect.h"

PhysicalBody::PhysicalBody(double x, double y, double speed)
    : _x(x)
    , _y(y)
    , _speed(speed)
{
    _avatar = new GraphicRect(this);
}

//void PhysicalBody::SetAvatar(QGraphicsItem* avatar)
//{
//    _avatar = avatar;
//}

QGraphicsItem* PhysicalBody::GetAvatar()
{
    return _avatar;
}

void PhysicalBody::SetX(double x) { _x = x; }
void PhysicalBody::SetY(double y) { _y = y; }

void PhysicalBody::SetSpeed(double speed) { _speed = speed; }

double PhysicalBody::GetX() { return _x; }
double PhysicalBody::GetY() { return _y; }

double PhysicalBody::GetSpeed() { return _speed; }
