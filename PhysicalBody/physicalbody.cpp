#include "physicalbody.h"
#include "Graphic/graphicrect.h"

PhysicalBody::PhysicalBody(Method* method, double x, double y, double speed)
    : _x(x)
    , _y(y)
    , _speed(speed)
    , _method(method)
{
    //_avatar = new GraphicRect(this);
}

void PhysicalBody::InitValues(double x, double y, double speed,
                        QLabel* labelSpeed, QLabel* labelX, QLabel* labelY)
{
    _x = x; _y = y; _speed = speed;
    _avatar = new GraphicRect(this);

    _avatar->SetLabelSpeed(labelSpeed);
    _avatar->SetLabelX(labelX);
    _avatar->SetLabelY(labelY);
}


void PhysicalBody::InitMethod(Method* method)
{
    delete _method;
    _method = method;
}
GraphicRect* PhysicalBody::GetAvatar()
{
    return _avatar;
}

void PhysicalBody::UpdateValues()
{
    double additional_speed = _speed;
    _speed = _method->GetSpeed(_speed);
    _y = _method->GetY(_y, additional_speed);

    if(_y < 0)
    {
        _speed *= -1;
    }

    _avatar->UpdateLabels();
}

//void PhysicalBody::SetX(double x) { _x = x; }
//void PhysicalBody::SetY(double y) { _y = y; }

//void PhysicalBody::SetSpeed(double speed) { _speed = speed; }

double PhysicalBody::GetX() { return _x; }
double PhysicalBody::GetY() { return _y; }

double PhysicalBody::GetSpeed() { return _speed; }
