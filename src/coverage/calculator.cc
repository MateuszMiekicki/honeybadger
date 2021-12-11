#include <calculator.hh>

int calculator::add(int a, int b) const
{
    return a + b;
}

int calculator::div(int a, int b)
{
    if(b==0)
    {
        return -1;
    }
    return a / b;
}

int calculator::multiple(int a, int b) const noexcept
{
    return a * b;
}
