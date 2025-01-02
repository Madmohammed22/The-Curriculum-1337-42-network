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

void PmergeMe::swapPairs_lv2(std::pair<std::pair<int, int>, std::pair<int, int> > &ai_bi)
{
    std::pair<int, int> sub1_ai_bi = ai_bi.first;
    std::pair<int, int> sub2_ai_bi = ai_bi.second;
    if (sub1_ai_bi.second > sub2_ai_bi.second){
        std::pair<int,int> temp = ai_bi.first;
        ai_bi.first = ai_bi.second;
        ai_bi.second = temp; 
    }
}

// void PmergeMe::swapPairs_lv3(std::pair<std::pair<int, int>, std::pair<int, int> >
// , std::pair<std::pair<int, int>, std::pair<int, int> >& ai_bi)
// {
//     std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi = ai_bi.first;
//     std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi = ai_bi.second;
//     if (sub1_ai_bi.second > sub2_ai_bi.second){
//         std::pair<int,int> temp = ai_bi.first;
//         ai_bi.first = ai_bi.second;
//         ai_bi.second = temp; 
//     }
// }

std::vector<std::pair<int, int> > 
PmergeMe::ft_PmergeMe_Recursion(const std::vector<int>& vec, int n) 
{
    std::vector<std::pair<int, int> > pairwise_comparison;
    if (n % 2 && n <= 0)
        return pairwise_comparison; 
    if (!(n % 2) && n <= 1) 
        return pairwise_comparison;
    std::pair<int, int> ai_bi(vec[n - 1], vec[n]); 
    if (ai_bi.first > ai_bi.second)
        swapPairs(ai_bi); 
    pairwise_comparison.push_back(ai_bi); 
    std::vector<std::pair<int, int> > sub_comparisons = ft_PmergeMe_Recursion(vec, n - 2); 
    pairwise_comparison.insert(pairwise_comparison.end(), sub_comparisons.begin(), sub_comparisons.end()); 

    return pairwise_comparison;
}
std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > 
PmergeMe::ft_PmergeMe_recussion_lv2(std::vector<std::pair<int, int> >sub_comparisons, int n){
    
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > pair_of_pairs;
    std::pair<std::pair<int, int>, std::pair<int, int> > ai_bi;
    for (int i = 0; i < n; i += 2){
        ai_bi.first = sub_comparisons[i];
        ai_bi.second = sub_comparisons[i + 1];
        swapPairs_lv2(ai_bi);
        pair_of_pairs.push_back(ai_bi);
    }
    return pair_of_pairs;
}

//             b1       a1        b2       a2
// [[[2,11] [0,17] [8,16] [6,15]], [[2,11] [0,17] [8,16] [6,15]] ]
std::vector<std::pair<std::pair<int, int>, std::pair<int, int> >, std::pair<std::pair<int, int>, std::pair<int, int> >> 

PmergeMe::ft_PmergeMe_recussion_lv3(std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > >  sub_comparisons, int n){

    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> >, std::pair<std::pair<int, int>, std::pair<int, int> > > pair_of_pairs_of_pairs;

    std::pair<
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >, 
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >
            > ai_bi;


    std::vector< std::pair<
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >, 
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >
            > >ai_bi_vec;

    
std::vector<std::pair<std::pair<int, int>, std::pair<int, int> >, std::pair<std::pair<int, int>, std::pair<int, int> >> pair_of_pairs_of_pairs; 
        pair_of_pairs_of_pairs;

    std::pair<std::pair<std::pair<int, int>, std::pair<int, int> >,
    std::pair<std::pair<int, int>, std::pair<int, int> > > var1;
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> >,
    std::pair<std::pair<int, int>, std::pair<int, int> > >pair_of_pairs_of_pairs;
    // std::pair<std::pair<int, int>, std::pair<int, int> >,
    // std::pair<std::pair<int, int>, std::pair<int, int> > > test;
    std::pair<std::pair<std::pair<int, int>, std::pair<int, int> >, std::pair<std::pair<int, int>, std::pair<int, int> > >var3;
    
    for (int i = 0; i < n; i += 2){
        ai_bi.first = sub_comparisons[i];
        ai_bi.second = sub_comparisons[i + 1];
        // swapPairs_lv3v(ai_bi);
        pair_of_pairs_of_pairs.pop_back();
        // pair_of_pairs_of_pairs.push_back(var1);
    }
    // s.pop_back()
    return pair_of_pairs_of_pairs;
}


//     b1       a1        b2       a2
// [[2,11], [[0,17]] [[8,16], [[6,15]]
std::vector<int> PmergeMe::ft_PmergeMe(std::vector<int> vec)
{
    std::vector<std::pair<int, int> > return_recurssion = ft_PmergeMe_Recursion(vec, vec.size() - 1);   
    for (size_t i = 0; i < return_recurssion.size(); i++)
        std::cout << "[" << return_recurssion[i].first << " " << return_recurssion[i].second << "]" << " " << std::ends;
    std::cout << "" << std::endl;

    std::cout << "----------------------------" << std::endl;

    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > return_lv
        = ft_PmergeMe_recussion_lv2(return_recurssion, return_recurssion.size() - 1);
    for (size_t i = 0; i < return_lv.size(); i++){
        std::pair<int, int> ai = return_lv[i].first;
        std::pair<int, int> bi = return_lv[i].second;
        std::cout << "[" << "[" << ai.first << "," << ai.second << "]" << ", " << "[" << "[" << bi.first << "," << bi.second << "]" << "]" << " " << std::ends;
    }
    std::cout << "" << std::endl;
    return vec;
}