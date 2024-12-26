#include "Point.hpp"

int main()
{
    Point obj1(2.00, 2.00);
    Point obj2(2.00, 1.00);
    Point obj3(1.00, 1.00);
    Point point(1.85393,0.96697);
    if (bsp(obj1, obj2, obj3 ,point) == true)
        std ::cout << "Inside" << std ::endl;
    else
        std ::cout << "Outside" << std ::endl;

    return 0;
}