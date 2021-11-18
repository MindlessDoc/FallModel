#pragma once

#include "../method.h"

class ClassicFourthRKMethod : public Method
{
public:
    ClassicFourthRKMethod(double deltaT, Function* function);

    virtual double GetY(const double prev_way, const double prev_speed) override;
    virtual double GetSpeed(const double prev_speed) override;

private:
    double k_1(double prev_count);
    double k_2(double prev_count);
    double k_3(double prev_count);
    double k_4(double prev_count);
};
