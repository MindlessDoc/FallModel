#pragma once

#include <iostream>

double func_1(double x, double k)
{
    return -9.8 - k * x;
}

double MethodEuler(const double prev_speed, const double delta_t)
{
    return prev_speed + delta_t * func_1(prev_speed, 0.2);
}

double MethodEuler_2(const double prev_way, const double prev_speed, const double delta_t)
{
    //speed[i] = MethodEuler(delta_t, i);
    return prev_way + delta_t * prev_speed;
}
