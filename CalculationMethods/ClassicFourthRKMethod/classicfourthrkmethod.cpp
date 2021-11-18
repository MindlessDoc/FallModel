#include "classicfourthrkmethod.h"
#include <iostream>

ClassicFourthRKMethod::ClassicFourthRKMethod(double deltaT, Function* function)
    : Method(deltaT, function)
{

}

double ClassicFourthRKMethod::GetSpeed(const double prev_speed)
{
    return prev_speed + _deltaT *
            (k_1(prev_speed) / 6 + k_2(prev_speed) / 3 + k_3(prev_speed)/ 3 + k_4(prev_speed) / 6);

}

double ClassicFourthRKMethod::GetY(const double prev_way, const double prev_speed)
{
    return prev_way + _deltaT * prev_speed;
}

double ClassicFourthRKMethod::k_1(double prev_count)
{
    return _function->GetValue(prev_count);
}

double ClassicFourthRKMethod::k_2(double prev_count)
{
    return _function->GetValue(prev_count + (_deltaT / 2) * k_1(prev_count));
}


double ClassicFourthRKMethod::k_3(double prev_count)
{
    return _function->GetValue(prev_count + (_deltaT / 2) * k_2(prev_count));
}


double ClassicFourthRKMethod::k_4(double prev_count)
{
    return _function->GetValue(prev_count + _deltaT * k_3(prev_count));
}

