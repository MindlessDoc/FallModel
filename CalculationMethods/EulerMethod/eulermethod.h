#pragma once

#include "../method.h"


class EulerMethod : public Method
{
public:
    EulerMethod(double deltaT, Function* function);

    virtual double GetY(const double prev_way, const double prev_speed) override;
    virtual double GetSpeed(const double prev_speed) override;
};

