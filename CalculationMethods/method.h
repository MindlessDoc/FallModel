#pragma once
#include "Functions/function.h"


class Method
{
public:
    Method(double deltaT, Function* function);

    virtual double GetY(const double prev_way, const double prev_speed) = 0;
    virtual double GetSpeed(const double prev_speed) = 0;

protected:
    double _deltaT;
    Function* _function;
};
