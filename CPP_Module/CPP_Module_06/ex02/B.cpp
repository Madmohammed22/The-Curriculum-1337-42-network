#include "B.hpp"

void B::function()
{
    std::cout << "From B class" << std::endl;
}

B::~B()
{
    std::cout << "[B] distructor is called" << std::endl;
}