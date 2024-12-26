#include "Point.hpp"

// Area = (1/2) [x1 (y2 – y3) + x2 (y3 – y1) + x3 (y1 – y2)]
float area(Point const a, Point const b, Point const c)
{
    float A = a.Get_x() * (b.Get_y() - c.Get_y());
    float B = b.Get_x() * (c.Get_y() - a.Get_y());
    float C = c.Get_x() * (a.Get_y() - b.Get_y());
    return 0.5 * abs(A + B + C);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    float SumArea = area(a, b, c);
    float bc_bp = area(b, c, point);
    float ba_bp = area(b, a, point);
    float ac_ap = area(a, c, point);
    if (SumArea == (bc_bp + ba_bp + ac_ap))
        return true;
    return false;
}