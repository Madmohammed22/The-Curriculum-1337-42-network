#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"
#include <math.h>
using namespace std;

class Point
{
private:
    Fixed const x;
    Fixed const y;

public:
    Point();

    Point(const float x, const float y);

    Point(const Point &c);

    Point &operator=(Point &p);
    ~Point();

public:
    float Get_x() const ;
    float Get_y() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
float area(Point  a, Point  b, Point  c);

#endif