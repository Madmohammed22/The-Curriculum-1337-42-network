#include "ScalarConverter.hpp"

int main(int argc, char **argv){
    
    if (argc < 2 ){
        std::cout << "<convert> put some data to convert" << std::endl;
        return EXIT_FAILURE;
    }
    ScalarConverter* scalar = new ScalarConverter();
    scalar->convert(argv[1]);
    return EXIT_SUCCESS;
}