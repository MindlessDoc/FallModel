#pragma once

class Function
{
public:
    Function(double k);

    double GetValue(double x);

private:
    const double _k;
    const double _g = -9.8;
};
