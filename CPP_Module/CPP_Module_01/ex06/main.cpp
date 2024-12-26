#include <iostream>
#include "Harl.hpp"

int main(int argc, char **argv){
    if (argc != 2)
        return 1;
    std :: string levels = argv[1];
    Harl harl;
    harl.complain(levels);
    return 0;
}
