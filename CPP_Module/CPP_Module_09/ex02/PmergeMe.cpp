#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &Init)
{
    (void)Init;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &Init)
{
    (void)Init;
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::displayNumber(std::vector<int> vec)
{
    std::vector<int>::iterator begin = vec.begin();
    std::vector<int>::iterator end = vec.end();
    while (begin != end)
    {
        std::cout << *begin << " " << std::ends;
        begin++;
    }
    std::cout << "" << std::endl;
}

void PmergeMe::swapPairs(std::pair<int, int> &ai_bi)
{
    int temp = ai_bi.first;
    ai_bi.first = ai_bi.second;
    ai_bi.second = temp;
}

std::vector<std::pair<int, int> > PmergeMe::ft_PmergeMe_recussion(std::vector<int> vec)
{

    std::vector<std::pair<int, int> > pairwise_comparison;
    std::pair<int, int> ai_bi;
    size_t n = vec.size() - 1;
    if (n == 0)
    {
        return pairwise_comparison;
    }
    else
    {
        ai_bi.first = vec[n];
        ai_bi.second = vec[n - 1];
        if (ai_bi.first > ai_bi.second)
            swapPairs(ai_bi);
        pairwise_comparison.push_back(ai_bi);
        n -= 2;
    }
    std::cout << "I was at stage 3 { " << pairwise_comparison.size() << std::endl;
    return pairwise_comparison;
}


// std::vector<std::pair<int, int> > PmergeMe::ft_PmergeMe_recussion(std::vector<int> vec) {
//     std::vector<std::pair<int, int> > pairwise_comparison;

//     if (vec.size() <= 1) {
//         std::cout << "I was here at the base case" << std::endl;
//         return pairwise_comparison;
//     }

//     size_t mid = vec.size() / 2;
//     std::vector<int> left(vec.begin(), vec.begin() + mid);
//     std::vector<int> right(vec.begin() + mid, vec.end());

//     std::vector<std::pair<int, int> > left_pairs = ft_PmergeMe_recussion(left);
//     std::vector<std::pair<int, int> > right_pairs = ft_PmergeMe_recussion(right);

//     // Merge the results from the left and right halves 
//     // (Implementation of merging logic depends on your specific requirements)

//     pairwise_comparison.insert(pairwise_comparison.end(), left_pairs.begin(), left_pairs.end());
//     pairwise_comparison.insert(pairwise_comparison.end(), right_pairs.begin(), right_pairs.end());

//     return pairwise_comparison;
// }

std::vector<int> PmergeMe::ft_PmergeMe(std::vector<int> vec)
{

    std::vector<std::pair<int, int> > pairwise_comparison;
    std::pair<int, int> ai_bi;

    if (vec.size() == 1)
        return vec;

    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (vec.size() % 2 && i == vec.size() - 1)
        {
            ai_bi.first = vec[i];
            pairwise_comparison.push_back(ai_bi);
        }
        ai_bi.first = vec[i];
        ai_bi.second = vec[i + 1];
        if (ai_bi.first > ai_bi.second)
            swapPairs(ai_bi);
        pairwise_comparison.push_back(ai_bi);
    }
    if (ft_PmergeMe_recussion(vec).size() == 0){
        std::cout << "I was here " << std::endl;
    }
    std::vector<std::pair<int, int> > return_recurssion = ft_PmergeMe_recussion(vec);
    for (size_t i = 0; i < return_recurssion.size(); i++)
        std::cout << "[" << return_recurssion[i].first << " " << return_recurssion[i].second << "]" << " " << std::ends;
    std::cout << "" << std::endl;
    return vec;
}