#include "PmergeMe.hpp"

int main(int argc, char **argv){
    if (argc < 2)
        return EXIT_FAILURE;
    PmergeMe *pmergeMe = new PmergeMe;
    int i = argc - 1;
    while (i > 0){
        int number = atoi(argv[i]);
        pmergeMe->vec.push_back(number);
        i--;
    }
    pmergeMe->displayNumber(pmergeMe->vec);
    pmergeMe->ft_PmergeMe(pmergeMe->vec);
    delete pmergeMe;
}
