#include "function.h"

Function::Function(double k)
    : _k(k)
{

}

double Function::GetValue(double x)
{
    return _g - _k * x;
}
