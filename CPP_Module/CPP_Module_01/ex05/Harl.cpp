#include <iostream>
#include "Harl.hpp"

using namespace std; 

void Harl::debug()
{
    std ::cout << "I love having extra bacon for my " << std ::ends
               << "7XL-double-cheese-triple-pickle-specialketchup burger." << std ::ends
               << " I really do!" << std ::endl;
}

void Harl::info()
{

    std ::cout << "I cannot believe adding extra bacon costs" << std ::ends
               << " more money. You didn’t put enough bacon in my burger!" << std ::ends
               << " If you did, I wouldn’t be asking for more!" << std ::endl;
}

void Harl::warning()
{
    std ::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for" << std ::ends
               << " years whereas you started working here since last month." << std ::ends
               << std ::endl;
}

void Harl::error()
{
    std ::cout << "This is unacceptable! I want to speak to the manager now." << std ::endl;
}

int hashit (std::string const& inString) {
    int i = 0;
    std::string stringArray[5] = {"DEBUG", "INFO", "WARNING", "ERROR", ""};
    while (inString != stringArray[i] && !stringArray[i].empty())
        i++;
    return i + 1;
};

void Harl::complain(std::string level)
{
    void (Harl::*ptr)() = NULL;
    switch (hashit(level))
    {
    case 1:
        ptr = &Harl::debug;
        break;
    case 2:
        ptr = &Harl::info;
        break;
    case 3:
        ptr = &Harl::warning;
        break;
    case 4:
        ptr = &Harl::error;
        break;
    case 5:
        std::cout << "Invalid level" << std::endl;
        return;
    }

    if (ptr != NULL)
    {
        (this->*ptr)();
    }
}
