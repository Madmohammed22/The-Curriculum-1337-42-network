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

void PmergeMe::swapPairs_lv1(std::pair<int, int> &ai_bi)
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
        ai_bi.first = sub2_ai_bi;
        ai_bi.second = sub1_ai_bi; 
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
    std::pair<int, int> sub1_ai_bi_v1 = sub1_ai_bi.second;
    std::pair<int, int> sub2_ai_bi_v1 = sub2_ai_bi.second;
    if (sub1_ai_bi_v1.second > sub2_ai_bi_v1.second){
        std::pair<std::pair<int, int>, std::pair<int, int> > temp = ai_bi.first;
        ai_bi.first = ai_bi.second;
        ai_bi.second = temp; 
    }
}

void swapPairs_lv4(
                    std::pair<std::pair<
                            std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >, std::pair<
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >
                    >ai_bi)
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
            > sub1_ai_bi = ai_bi.first;
    
    std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi_v1 = sub1_ai_bi.second;
    std::pair<int, int> sub1_ai_bi_v2 = sub1_ai_bi_v1.second;
    // sub1_ai_bi_v2.second // 17
    // std::cout << "--> " << sub1_ai_bi_v2.second << " <----" << std::endl;
    std::pair<
                std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                        >, 
                std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                >
            > sub2_ai_bi = ai_bi.second;
    std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi_v1 = sub2_ai_bi.second;
    std::pair<int, int> sub2_ai_bi_v2 = sub2_ai_bi_v1.second;
    // sub2_ai_bi_v2.second // 21;
    // std::cout << "--> " << sub2_ai_bi_v2.second << " <----" << std::endl;

    if (sub1_ai_bi_v2.second > sub2_ai_bi_v2.second){
        // std::cout << "I was here " << std::endl;
            std::pair<
                std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                        >, 
                std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                >
            > temp = ai_bi.first;
        ai_bi.first = ai_bi.second;
        ai_bi.second = temp;
    }
}

std::vector<std::pair<int, int> > 
PmergeMe::ft_PmergeMe_Recursion_lv1(const std::vector<int>& vec, int n) 
{
    std::vector<std::pair<int, int> > pairwise_comparison;
    if (n <= 0)
        return pairwise_comparison;
    std::pair<int, int> ai_bi(vec[n], vec[n - 1]);
    if (ai_bi.first > ai_bi.second)
        swapPairs_lv1(ai_bi); 
    pairwise_comparison.push_back(ai_bi); 
    std::vector<std::pair<int, int> > sub_comparisons = ft_PmergeMe_Recursion_lv1(vec, n - 2); 
    pairwise_comparison.insert(pairwise_comparison.end(), sub_comparisons.begin(), sub_comparisons.end()); 
    return pairwise_comparison;
}

std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > 
PmergeMe::ft_PmergeMe_recursion_lv2(std::vector<std::pair<int, int> > sub_comparisons, int n){
    
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > pair_of_pairs;
    if (n <= 0)
        return pair_of_pairs;
    std::pair<std::pair<int, int>, std::pair<int, int> > ai_bi(sub_comparisons[n], sub_comparisons[n - 1]);
    swapPairs_lv2(ai_bi);
    pair_of_pairs.push_back(ai_bi);
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > lv2_pair_of_pairs = ft_PmergeMe_recursion_lv2(sub_comparisons, n - 2);
    pair_of_pairs.insert(pair_of_pairs.end(), lv2_pair_of_pairs.begin(), lv2_pair_of_pairs.end());
    return pair_of_pairs;
}

std::vector<std::pair<
                        std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                        >, 
                        std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                        >
        > > ft_PmergeMe_recursion_lv3(std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > >  sub_comparisons, int n)
{


    std::vector<std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
            > >pair_of_pair_of_pairs;

    if (n <= 0){
        return pair_of_pair_of_pairs;
    }
    
    std::pair<
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >, 
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >
            > ai_bi(sub_comparisons[n], sub_comparisons[n - 1]);
    
    swapPairs_lv3(ai_bi);
    pair_of_pair_of_pairs.push_back(ai_bi);
    std::vector<std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
            > >lv3_pair_of_pairs_of_pairs = ft_PmergeMe_recursion_lv3(sub_comparisons, n - 2);
    pair_of_pair_of_pairs.insert(pair_of_pair_of_pairs.end(), lv3_pair_of_pairs_of_pairs.begin(),lv3_pair_of_pairs_of_pairs.end());
    return pair_of_pair_of_pairs;    
}

std::vector<int> insertVector_lv1(std::vector<std::pair<int, int> > return_pair_lv1, int last_element, int flag){

    std::vector<int> buffer;
    for (size_t i = 0; i < return_pair_lv1.size(); i++){
        buffer.push_back(return_pair_lv1[i].first);
        buffer.push_back(return_pair_lv1[i].second);
    }
    if (flag == 0)
        buffer.push_back(last_element);
    return buffer;
}

std::vector<int> insertVector_lv2(std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > return_pair_lv2, std::pair<int, int> last_element, int flag){

    std::vector<int> buffer;
    for (size_t i = 0; i < return_pair_lv2.size(); i++){
        std::pair<int, int> ai = return_pair_lv2[i].first;
        std::pair<int, int> bi = return_pair_lv2[i].second;
        buffer.push_back(ai.first);
        buffer.push_back(ai.second);
        buffer.push_back(bi.first);
        buffer.push_back(bi.second);
    }

    if (flag == 0){

        buffer.push_back(last_element.first);
        buffer.push_back(last_element.second);
    }
    return buffer;
}

std::vector<std::pair<std::pair<
                                    std::pair<
                                        std::pair<int, int>, 
                                        std::pair<int, int>
                                    >, 
                                    std::pair<
                                        std::pair<int, int>, 
                                        std::pair<int, int>
                                    >
                            >, std::pair<
                                    std::pair<
                                        std::pair<int, int>, 
                                        std::pair<int, int>
                                    >, 
                                    std::pair<
                                        std::pair<int, int>, 
                                        std::pair<int, int>
                                    >
                            >
                        >
>ft_PmergeMe_recursion_lv4(
            std::vector<std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                        >
        >sub_comparisons, int n)
{
    std::vector<std::pair<std::pair<
                            std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >, std::pair<
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >
                    >    
            >pair_of_pair_of_pairs;
    if (n <= 0){
        return pair_of_pair_of_pairs;
    }

    std::pair<std::pair<
                            std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >, std::pair<
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >
                    >ai_bi(sub_comparisons[n], sub_comparisons[n - 1]);
    
    swapPairs_lv4(ai_bi);
    pair_of_pair_of_pairs.push_back(ai_bi);
    std::vector<std::pair<std::pair<
                        std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                    >, std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                    >
                >    
        >lv4_pair_of_pair_of_pairs = ft_PmergeMe_recursion_lv4(sub_comparisons, n - 2);
    pair_of_pair_of_pairs.insert(pair_of_pair_of_pairs.end(), lv4_pair_of_pair_of_pairs.begin(), lv4_pair_of_pair_of_pairs.end());
    return pair_of_pair_of_pairs;
}
std::vector<int> insertVector_lv3(
    std::vector<std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                        > 
                > return_pair_lv3, std::pair<std::pair<int, int>, std::pair<int, int> > last_element
                    , std::pair<int, int> last_element_v1,  int flag){

    std::vector<int> buffer;
    for (size_t i = 0; i < return_pair_lv3.size(); i++){
        std::pair<std::pair<int, int>, std::pair<int, int> > ai = return_pair_lv3[i].first;
        std::pair<std::pair<int, int>, std::pair<int, int> > bi = return_pair_lv3[i].second;
        std::pair<int, int> ai_v1 = ai.first;
        std::pair<int, int> bi_v1 = ai.second;
        std::pair<int, int> ai_v2 = bi.first;
        std::pair<int, int> bi_v2 = bi.second;
        buffer.push_back(ai_v1.first);
        buffer.push_back(ai_v1.second);
        buffer.push_back(bi_v1.first);
        buffer.push_back(bi_v1.second);
        buffer.push_back(ai_v2.first);
        buffer.push_back(ai_v2.second);
        buffer.push_back(bi_v2.first);
        buffer.push_back(bi_v2.second);
    }

    if (flag == 0){
        std::pair<int, int> lai = last_element.first;
        std::pair<int, int> lbi = last_element.second;
        buffer.push_back(lai.first);
        buffer.push_back(lai.second);
        buffer.push_back(lbi.first);
        buffer.push_back(lbi.second);
        buffer.push_back(last_element_v1.first);
        buffer.push_back(last_element_v1.second);
    }
    return buffer;
}



std::vector<int> PmergeMe::ft_PmergeMe(std::vector<int> vec)
{
    if (vec.size() % 2 != 0){
        std::vector<std::pair<int, int> > return_pair_lv1 = ft_PmergeMe_Recursion_lv1(vec, (vec.size() - 1));
        std::cout << "odd : " << std::ends;
        for (size_t i = 0; i < return_pair_lv1.size(); i++)
            std::cout << "[" << return_pair_lv1[i].first << "," << return_pair_lv1[i].second << "]" << " | " << std::ends;
        std::cout << "" << std::endl;
        std::cout << "----------------------------" << std::endl;
        vec = insertVector_lv1(return_pair_lv1, vec.front(), 0);
        displayNumber(vec);
        return vec;
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
        }
        std::cout << "" << std::endl;
    }
    else{
        std::vector<std::pair<int, int> > return_pair_lv1 = ft_PmergeMe_Recursion_lv1(vec, vec.size() - 1);
        for (size_t i = 0; i < return_pair_lv1.size(); i++)
            std::cout << "[" << return_pair_lv1[i].first << "," << return_pair_lv1[i].second << "]" << " | " << std::ends;
        std::cout << "" << std::endl;
        std::cout << "----------------------------" << std::endl;
        vec = insertVector_lv1(return_pair_lv1, vec.front(), 1);
        displayNumber(vec);
        std::cout << "----------------------------" << std::endl;

        std::reverse(return_pair_lv1.begin(), return_pair_lv1.end());
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > return_pair_lv2
            = ft_PmergeMe_recursion_lv2(return_pair_lv1, return_pair_lv1.size() - 1);
        vec = insertVector_lv2(return_pair_lv2, return_pair_lv1.front(), 0);

        for (size_t i = 0; i < return_pair_lv2.size(); i++){
            std::pair<int, int> ai = return_pair_lv2[i].first;
            std::pair<int, int> bi = return_pair_lv2[i].second;
            std::cout << "[" << ai.first << "," << ai.second << "]" << ", " << "[" << bi.first << "," << bi.second << "]" << " | " << std::ends;
        }
        std::cout << "" << std::endl;
        std::cout << "----------------------------" << std::endl;
        displayNumber(vec);
        std::cout << "----------------------------" << std::endl;
        std::reverse(return_pair_lv2.begin(), return_pair_lv2.end());
        std::vector<std::pair<
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >, 
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >
            > > return_pair_lv3 = ft_PmergeMe_recursion_lv3(return_pair_lv2, return_pair_lv2.size() - 1);
        for (size_t i = 0; i < return_pair_lv3.size(); i++){
            std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi = return_pair_lv3[i].first;
            std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi = return_pair_lv3[i].second;
            std::pair<int, int> ai = sub1_ai_bi.first;
            std::pair<int, int> bi = sub1_ai_bi.second;
            std::pair<int, int> ai_2 = sub2_ai_bi.first;
            std::pair<int, int> bi_2 = sub2_ai_bi.second;


            std::cout << "[" << ai.first << " " << ai.second << " " << bi.first << " " << bi.second << "]" << ", "
                << "[" << ai_2.first << " " << ai_2.second << " " << bi_2.first << " " << bi_2.second << "]" << " | " << std::ends;
        }
        std::cout << "" << std::endl;
        std::cout << "----------------------------" << std::endl;
        vec = insertVector_lv3(return_pair_lv3, return_pair_lv2.front(),return_pair_lv1.front(), 0);
        displayNumber(vec);
        std::cout << "----------------------------" << std::endl;
        std::reverse(return_pair_lv3.begin(), return_pair_lv3.end());
        std::vector<std::pair<std::pair<
                        std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                    >, std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                    >
                >    
        >return_pair_lv4 = ft_PmergeMe_recursion_lv4(return_pair_lv3, return_pair_lv3.size() - 1);
        std::reverse(return_pair_lv4.begin(), return_pair_lv4.end());
        for (size_t i = 0; i < return_pair_lv4.size() ; i++)
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
            > sub1_ai_bi = return_pair_lv4[i].first;

            std::pair<
                    std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                    std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                    >
            > sub2_ai_bi = return_pair_lv4[i].second;
            std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi_v1 = sub1_ai_bi.first;
            std::pair<int, int> v1 = sub1_ai_bi_v1.first;
            std::pair<int, int> v2 = sub1_ai_bi_v1.second;
            std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi_v1 = sub1_ai_bi.second;
            std::pair<int, int> V1 = sub2_ai_bi_v1.first;
            std::pair<int, int> V2 = sub2_ai_bi_v1.second; 
            std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi_v2 = sub2_ai_bi.first;
            std::pair<int, int> l1 = sub1_ai_bi_v2.first;
            std::pair<int, int> l2 = sub1_ai_bi_v2.second; 
            std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi_v2 = sub2_ai_bi.second;
            std::pair<int, int> L1 = sub2_ai_bi_v2.first;
            std::pair<int, int> L2 = sub2_ai_bi_v2.second;
            std::cout << "[" << " [" << "[" << v1.first << " " << v1.second << " " << v2.first << " " << v2.second << "] " <<
                        "[" << V1.first << " " << V1.second  << " " << V2.first << " " << V2.second << "]" << "]" << " , " 
                    << "[" << "[" << l1.first << " " << l1.second << " " << l2.first << " " << l2.second << "], " << 
                    "[" << L1.first << " " << L1.second << " " << L2.first << " " <<  L2.second << "]" << "]" << " ]" << std::ends;
        }
        
        std::cout << "" << std::endl;
        std::cout << "----------------------------" << std::endl;
    }
    return vec;
}