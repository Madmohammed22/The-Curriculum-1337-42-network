#include "server.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "correct input : ./main [configuration file]" << std::endl;
        return EXIT_FAILURE;
    }

    Reader *read = new Reader();
    if (read->TheBalancedParentheses(argv[1]) == true)
        std::cout << "OK" << std::endl;
    else
        std::cout << "ERROR" << std::endl;
         
}