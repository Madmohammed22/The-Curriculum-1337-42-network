// #include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(int argc, char **argv){
    
    if (argc < 2 ){
        std::cout << "<convert> put some data to convert" << argv[1] <<  std::endl;
        return EXIT_FAILURE;
    }
    
    {
        // Base *base = new Base;
        Base *base = base->generate();
        // base = base->generate();
        base->identify(base);
        delete base;
    }

    std::cout << "-----------------------" << std::endl;

    {
        Base base;
        Base* base_test = base.generate();
        base.identify(*(&base_test));
        delete base_test;
    }
    return EXIT_SUCCESS;
}