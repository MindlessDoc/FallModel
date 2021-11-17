#include "eulermethod.h"

EulerMethod::EulerMethod(double deltaT, Function* function)
    : Method(deltaT, function)
{

}

double EulerMethod::GetSpeed(const double prev_speed)
{
    return prev_speed + _deltaT * _function->GetValue(prev_speed);
}

double EulerMethod::GetY(const double prev_way, const double prev_speed)
{
    return prev_way + _deltaT * prev_speed;
}
