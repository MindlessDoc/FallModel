#include "midpointmethod.h"

MidPointMethod::MidPointMethod(double deltaT, Function* function)
    : Method(deltaT, function)
{

}

double MidPointMethod::GetSpeed(const double prev_speed)
{
    return prev_speed + _deltaT *
            _function->GetValue(prev_speed + (_deltaT / 2) * _function->GetValue(prev_speed));
}

double MidPointMethod::GetY(const double prev_way, const double prev_speed)
{
    return prev_way + _deltaT * prev_speed;
}
