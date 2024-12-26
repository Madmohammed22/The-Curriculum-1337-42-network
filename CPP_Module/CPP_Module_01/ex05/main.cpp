#include "Harl.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 1)
        return 1;
    Harl harl;
    harl.complain("INFO");
    return 0;
}
