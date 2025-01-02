#include "PmergeMe.hpp"

int main(int argc, char **argv){
    if (argc < 2)
        return EXIT_FAILURE;
    PmergeMe *pmergeMe = new PmergeMe;
    for (int i = 1; i < argc; i++){
        int number = atoi(argv[i]);
        pmergeMe->vec.push_back(number);
    }
    // pmergeMe->displayNumber(pmergeMe->vec);
    pmergeMe->ft_PmergeMe(pmergeMe->vec);
    delete pmergeMe;
}
