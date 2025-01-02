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

    for (size_t i = 0; i < pairwise_comparison.size(); i++)
        std::cout << "[" << pairwise_comparison[i].first << " " << pairwise_comparison[i].second << "]" << " " <<   std::ends;
    std::cout << "" << std::endl;
    return vec;
}