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
    switch (hashit(level))
    {
    case 1:
        std::cout << "[ DEBUG ]" << std::endl;
        debug();
        std :: cout << std :: endl;
    case 2:
        std::cout << "[ INFO ]" << std::endl;
        info();
        std :: cout << std :: endl;
    case 3:
        std::cout << "[ WARNING ]" << std::endl;
        warning();
        std :: cout << std :: endl;
    case 4:
        std::cout << "[ ERROR ]" << std::endl;
        error();
        std :: cout << std :: endl;
        break;
    case 5:
        std::cout << "Probably complaining about insignificant problems" << std::endl;
        break;
    }
}

