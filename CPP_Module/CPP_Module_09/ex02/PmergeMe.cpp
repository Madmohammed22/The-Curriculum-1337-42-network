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

void swapPairs_lv3(std::pair<
                        std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                        >, 
                        std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                        >
                    > &ai_bi)
{
    std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi = ai_bi.first;
    std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi = ai_bi.second;
    if (sub1_ai_bi.second > sub2_ai_bi.second){
        std::pair<std::pair<int, int>, std::pair<int, int> > temp = ai_bi.first;
        ai_bi.first = ai_bi.second;
        ai_bi.second = temp; 
    }
}

std::vector<std::pair<int, int> > 
PmergeMe::ft_PmergeMe_Recursion(const std::vector<int>& vec, int n) 
{
    std::vector<std::pair<int, int> > pairwise_comparison;
    if (n <= 0)
        return pairwise_comparison; 
    // if (!(n % 2) && n <= 1) 
    //     return pairwise_comparison;
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
std::vector<std::pair<
            std::pair<
                std::pair<int, int>, 
                std::pair<int, int>
            >, 
            std::pair<
                std::pair<int, int>, 
                std::pair<int, int>
            >
        > > ft_PmergeMe_recussion_lv3(std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > >  sub_comparisons, int n)
{

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

    std::vector<std::pair<
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >, 
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >
            > >pair_of_pairs_of_pairs;

    for (int i = 0; i < n; i++){
        ai_bi.first = sub_comparisons[i];
        ai_bi.second = sub_comparisons[i + 1];
        swapPairs_lv3(ai_bi);
        pair_of_pairs_of_pairs.push_back(ai_bi);
    }
    return pair_of_pairs_of_pairs;    
}

//     b1       a1        b2       a2
// [[2,11], [[0,17]] [[8,16], [[6,15]]
std::vector<int> PmergeMe::ft_PmergeMe(std::vector<int> vec)
{
    if (vec.size() % 2){
        std::vector<std::pair<int, int> > return_pair_lv1 = ft_PmergeMe_Recursion(vec, vec.size() - 2);
        for (size_t i = 0; i < return_pair_lv1.size(); i++)
            std::cout << "[" << return_pair_lv1[i].first << "," << return_pair_lv1[i].second << "]" << " | " << std::ends;
        std::vector<int>::iterator last = vec.end();
        std::cout << *last << " | " << std::endl;
        std::cout << "----------------------------" << std::endl;
        
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > return_pair_lv2
            = ft_PmergeMe_recussion_lv2(return_pair_lv1, return_pair_lv1.size() - 2);
        for (size_t i = 0; i < return_pair_lv2.size(); i++){
            std::pair<int, int> ai = return_pair_lv2[i].first;
            std::pair<int, int> bi = return_pair_lv2[i].second;
            std::cout << "[" << ai.first << "," << ai.second << "]" << ", " << "[" << bi.first << "," << bi.second << "]" << " | " << std::ends;
        }
        for (size_t i = return_pair_lv1.size() - 1; i <= return_pair_lv1.size() - 1; i++){
            std::cout << "[" << return_pair_lv1[i].first << ", " << return_pair_lv1[i].second << "]" << std::ends; 
            std::cout << "I was here" << std::endl;
        }
        std::cout << "" << std::endl;
    }
    else{
        std::vector<std::pair<int, int> > return_pair_lv1 = ft_PmergeMe_Recursion(vec, vec.size() - 1);
        for (size_t i = 0; i < return_pair_lv1.size(); i++)
            std::cout << "[" << return_pair_lv1[i].first << "," << return_pair_lv1[i].second << "]" << " | " << std::ends;
        std::cout << "" << std::endl;
        std::cout << "----------------------------" << std::endl;

        std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > return_pair_lv2
            = ft_PmergeMe_recussion_lv2(return_pair_lv1, return_pair_lv1.size() - 1);
        for (size_t i = 0; i < return_pair_lv2.size(); i++){
            std::pair<int, int> ai = return_pair_lv2[i].first;
            std::pair<int, int> bi = return_pair_lv2[i].second;
            std::cout << "[" << ai.first << "," << ai.second << "]" << ", " << "[" << bi.first << "," << bi.second << "]" << " | " << std::ends;
        }
        
        std::cout << "" << std::endl;
    }



    // if (return_pair_lv1.size() % 2){
    //     std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > return_pair_lv2
    //         = ft_PmergeMe_recussion_lv2(return_pair_lv1, return_pair_lv1.size() - 2);
    //     for (size_t i = 0; i < return_pair_lv2.size(); i++){
    //         std::pair<int, int> ai = return_pair_lv2[i].first;
    //         std::pair<int, int> bi = return_pair_lv2[i].second;
    //         std::cout << "[" << ai.first << "," << ai.second << "]" << ", " << "[" << bi.first << "," << bi.second << "]" << " | " << std::ends;
    //     }

    //     std::cout << "" << std::endl;
        
    // }
    // else
    // {
    //     std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > return_pair_lv2
    //         = ft_PmergeMe_recussion_lv2(return_pair_lv1, return_pair_lv1.size() - 1);
    //     for (size_t i = 0; i < return_pair_lv2.size(); i++){
    //         std::pair<int, int> ai = return_pair_lv2[i].first;
    //         std::pair<int, int> bi = return_pair_lv2[i].second;
    //         std::cout << "[" << ai.first << "," << ai.second << "]" << ", " << "[" << bi.first << "," << bi.second << "]" << " | " << std::ends;
    //     }
        
    //     std::cout << "" << std::endl;
    // }
    
    // std::vector<std::pair<int, int> >::iterator return_pair_lv1 = 
    // std::cout << "[" << " " << std::endl;

    // std::cout << "----------------------------" << std::endl;
    // std::vector<std::pair<
    //         std::pair<
    //             std::pair<int, int>, 
    //             std::pair<int, int>
    //         >, 
    //         std::pair<
    //             std::pair<int, int>, 
    //             std::pair<int, int>
    //         >
    //     > > return_pair_lv3 = ft_PmergeMe_recussion_lv3(return_pair_lv2, return_pair_lv2.size() - 2);
    // for (size_t i = 0; i < return_pair_lv3.size(); i++){
    //     std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi = return_pair_lv3[i].first;
    //     std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi = return_pair_lv3[i].second;
    //     std::pair<int, int> ai = sub1_ai_bi.first;
    //     std::pair<int, int> bi = sub1_ai_bi.second;
    //     std::pair<int, int> ai_2 = sub2_ai_bi.first;
    //     std::pair<int, int> bi_2 = sub2_ai_bi.second;


    //     std::cout << "[ " << "[" << "[" << ai.first << " " << ai.second << " " << bi.first << " " << bi.second << "]" << " "
    //         << "[" << ai_2.first << " " << ai_2.second << " " << bi_2.first << " " << bi_2.second << "]" << "]" << " " << "]" << std::ends;
    // }
    // std::cout << "" << std::endl;

    return vec;
}