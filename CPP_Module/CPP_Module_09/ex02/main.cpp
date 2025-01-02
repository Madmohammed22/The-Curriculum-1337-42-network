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
    // pmergeMe->displayNumber(pmergeMe->vec);
    pmergeMe->ft_PmergeMe(pmergeMe->vec);
    delete pmergeMe;
}

/*
    // std::vector<std::pair<int, int> > pairwise_comparison;
    // std::pair<int, int> ai_bi;

    // if (vec.size() == 1)
    //     return vec;

    // for (size_t i = 0; i < vec.size(); i += 2)
    // {
    //     if (vec.size() % 2 && i == vec.size() - 1)
    //     {
    //         ai_bi.first = vec[i];
    //         pairwise_comparison.push_back(ai_bi);
    //     }
    //     ai_bi.first = vec[i];
    //     ai_bi.second = vec[i + 1];
    //     if (ai_bi.first > ai_bi.second)
    //         swapPairs(ai_bi);
    //     pairwise_comparison.push_back(ai_bi);
    // } 
 */