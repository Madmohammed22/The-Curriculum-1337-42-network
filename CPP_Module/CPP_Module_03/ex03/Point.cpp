#include "Point.hpp"

Point::Point() : x(0), y(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Point ::Point(const float x, const float y) : x(x), y(y)
{
    // std::cout << "Parameterize constructor called" << std::endl;
}

Point ::Point(const Point &c) : x(c.Get_x()), y(c.Get_y())
{

    // std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(Point &other)
{
    if (this != &other)
    {
        (void)other;
    }
    return *this;
}

Point ::~Point()
{
    // std ::cout << "Destructor called" << std ::endl;
}

float Point::Get_x() const
{
    return x.toFloat();
}

float Point::Get_y() const
{
    return y.toFloat();
}
