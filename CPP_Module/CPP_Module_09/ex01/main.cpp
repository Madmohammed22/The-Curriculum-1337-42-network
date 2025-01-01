#include "RPN.hpp"

int main(int argc, char **argv){
    if (argc < 2)
        return EXIT_FAILURE;

    std::string expression = argv[1];
    RPN rpn;

    std::cout << rpn.resultRPN(expression) << std::endl;
    return EXIT_SUCCESS;
}