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
    if (this != &Init)
        return *this;
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
    if (ai_bi.first < ai_bi.second) 
    {
        int temp = ai_bi.first;
        ai_bi.first = ai_bi.second;
        ai_bi.second = temp;
    }
}

void insertion_sort(std::vector<std::pair<int, int> >&ai_bi, int n) {
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while (j > 0 && ai_bi[j - 1].first > ai_bi[j].first) {
            std::pair<int, int> temp = ai_bi[j - 1];
            ai_bi[j - 1] = ai_bi[j];
            ai_bi[j] = temp;
            j--;
        }
    }
}

std::vector<std::pair<int, int> > 
PmergeMe::ft_PmergeMe_Recursion_lv1(const std::vector<int>& vec, int n) 
{
    std::vector<std::pair<int, int> > pairwise_comparison;
    
    if (n <= 0){
        if (vec.size() % 2 != 0){
            std::pair<int, int> ai_bi;
            ai_bi.first = vec[n];
            ai_bi.second = -1;
            pairwise_comparison.push_back(ai_bi); 
            return pairwise_comparison;
        }
        return pairwise_comparison;
    }
    std::pair<int, int> ai_bi(vec[n], vec[n - 1]);
    swapPairs_lv1(ai_bi); 
    pairwise_comparison.push_back(ai_bi); 
    std::vector<std::pair<int, int> > sub_comparisons = ft_PmergeMe_Recursion_lv1(vec, n - 2); 
    pairwise_comparison.insert(pairwise_comparison.end(), sub_comparisons.begin(), sub_comparisons.end()); 
    return pairwise_comparison;
}

void Jacobsthal(int n, std::vector<int>&sequence)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
        if (dp[i] >= n){
            sequence.push_back(dp[i]);
            return;
        }
        sequence.push_back(dp[i]);
    }
}

// 1 3 5 11 

bool insert_if_not_exist(std::vector<int> sequence, int target){
    if (sequence.empty())
        return true;
    
    for (size_t i = 0; i < sequence.size(); i++){
        if (sequence[i] == target)
            return false;
    }
    return true;
}

std::vector<int> sequence_index(std::vector<int>Jacobsthal){
    std::vector<int> sequence;
    for (size_t i = 0; i < Jacobsthal.size(); i++){
        sequence.push_back(Jacobsthal[i]);
        if ((Jacobsthal[i + 1] - Jacobsthal[i]) >= 0){ // 3 - 1 == 2 | 3 2
            for (size_t t = 0; t <= (size_t)(Jacobsthal[i + 1] - Jacobsthal[i]); t++){
                sequence.push_back(Jacobsthal[i + 1]--);
            }
        }
    }

    std::vector<int> real_sequence;
    for (size_t i = 0; i < sequence.size(); i++){
        if (insert_if_not_exist(real_sequence, sequence[i]) == true)
            real_sequence.push_back(sequence[i]);
    }
    return real_sequence;
}

std::vector<int> insertVector_lv1(std::vector<std::pair<int, int> > return_pair_lv1, int last_element, int flag){

    std::vector<int> buffer;
    for (size_t i = 0; i < return_pair_lv1.size(); i++){
        buffer.push_back(return_pair_lv1[i].first);
        buffer.push_back(return_pair_lv1[i].second);
    }
    if (flag == 0){
        buffer.push_back(last_element);
    }
    return buffer;
}

std::vector<int> PmergeMe::ft_PmergeMe(std::vector<int> vec)
{
    std::vector<std::pair<int, int> > return_pair_lv1 = ft_PmergeMe_Recursion_lv1(vec, vec.size() - 1);
    for (size_t i = 0; i < return_pair_lv1.size(); i++)
        std::cout << "[" << return_pair_lv1[i].first << "," << return_pair_lv1[i].second << "]" << " | " << std::ends;
    std::cout << "" << std::endl;
    std::cout << "----------------------------" << std::endl;
    vec = insertVector_lv1(return_pair_lv1, vec.front(), 1);
    displayNumber(vec);
    std::cout << "----------------------------" << std::endl;
    insertion_sort(return_pair_lv1, return_pair_lv1.size() - 1);
    std::vector<int> ai;
    std::vector<int> bi;
    for (size_t i = 0; i < return_pair_lv1.size(); i++){
        ai.push_back(return_pair_lv1[i].first);
        bi.push_back(return_pair_lv1[i].second);
    }

    for (size_t i = 0; i < ai.size(); i++){
        std::cout << ai[i] << " " << std::ends;
    }
    std::cout << "" << std::endl;

    for (size_t i = 0; i < bi.size(); i++){
        std::cout << bi[i] << " " << std::ends;
    }
    std::cout << "" << std::endl;
    std::cout << "----------------------" << std::endl;
    
    std::vector<int> sequence;
    Jacobsthal(bi.size(), sequence);
    for (size_t i = 0; i < sequence.size(); i++){
        std::cout << sequence[i] << " " << std::ends;
    }
    std::cout << "" << std::endl;

    std::vector<int> _index = sequence_index(sequence);
    for (size_t i = 0; i < _index.size(); i++){
        std::cout << _index[i] - 1 << " " << std::ends;
    }
    std::cout << "" << std::endl;
    return vec;
}
