#include "easyfind.hpp"
int main(){
    int buffer[] = {1, 2, 3,4, -2, 22, 12};
    int target = 41;
    try
    {
        std::cout << ::easyfind(buffer, target) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return EXIT_SUCCESS;
}