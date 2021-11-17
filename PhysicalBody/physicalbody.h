#pragma once

//#include <QGraphicsItem>
#include "Graphic/graphicrect.h"
#include "../CalculationMethods/EulerMethod/eulermethod.h"
#include "../CalculationMethods/AnalyticMethods/analyticmethod.h"

class PhysicalBody
{
public:
    PhysicalBody(Method* method = nullptr, double x = 0, double y = 0, double speed = 0);

    void InitValues(double x, double y, double speed,
                  QLabel* labelSpeed, QLabel* labelX, QLabel* labelY);

    //void SetAvatar(QGraphicsItem* avatar);
    GraphicRect* GetAvatar();

    void UpdateValues();

    void InitMethod(Method* method);

//    void SetX(double x);
//    void SetY(double y);

//    void SetSpeed(double speed);

    double GetX();
    double GetY();

    double GetSpeed();

private:
    double _x;
    double _y;

    double _speed;

    GraphicRect* _avatar = nullptr;

    Method* _method;
};

