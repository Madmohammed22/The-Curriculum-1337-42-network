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
    std::reverse(vec.begin(), vec.end());
    std::cout << "Before:   " << std::ends;
    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " " << std::ends;
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

std::vector<std::pair<int, int> > insertion_sort(std::vector<std::pair<int, int> > ai_bi, int n) {
    for (int i = 0; i <= n ; i++) {
        int j = i;
        while (j > 0 && ai_bi[j - 1].first > ai_bi[j].first) {
            std::pair<int, int> temp = ai_bi[j - 1];
            ai_bi[j - 1] = ai_bi[j];
            ai_bi[j] = temp;
            j--;
        }
    }
    return ai_bi;
}


std::vector<std::pair<int, int> > 
PmergeMe::ft_PmergeMe_Recursion_lv1(const std::vector<int>& vec, int n) 
{
    std::vector<std::pair<int, int> > pairwise_comparison;
    
    if (n <= 0){
        if (vec.size() % 2 != 0){
            std::pair<int, int> ai_bi;
            ai_bi.second = -1;
            ai_bi.first = vec[n];
            pairwise_comparison.push_back(ai_bi); 
            return pairwise_comparison;
        }
        return pairwise_comparison;
    }
    std::pair<int, int> ai_bi(vec[n - 1], vec[n]);
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

void increment(std::vector<std::pair<int, int> > s){
    for (size_t i = 0; i < s.size(); i++){
        s[i].second = s[i].second + 1;
    }
}

void searchInsert(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return;
        }

        if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (target != -1)
        nums.insert(nums.begin() + low, target);
    return ;
}

std::vector<int> PmergeMe::ft_PmergeMe(std::vector<int> vec)
{
    std::vector<std::pair<int, int> > return_pair_lv1 = ft_PmergeMe_Recursion_lv1(vec, vec.size() - 1);
    return_pair_lv1 = insertion_sort(return_pair_lv1, return_pair_lv1.size() - 1);
    std::vector<int> ai;
    std::vector<int> bi;
    for (size_t i = 0; i < return_pair_lv1.size(); i++){ 
        ai.push_back(return_pair_lv1[i].first);
        bi.push_back(return_pair_lv1[i].second);
    }
    if (bi.front() != -1)
        ai.insert(ai.begin(), bi.front());
    std::vector<int> sequence;
    Jacobsthal(bi.size(), sequence);
    std::vector<int> _index = sequence_index(sequence);
    int target_as_data;
    for (size_t i = 0; i < _index.size(); i++){
        if (!((size_t)(_index[i] - 1) > bi.size() - 1)){
            target_as_data = bi[_index[i] - 1]; 
            searchInsert(ai, target_as_data);
        }
    }

    std::cout << "after :   " << std::ends;
    for (size_t i = 0; i < ai.size(); i++){
        std::cout << ai[i] << " " <<  std::ends;
    }
    std::cout << "" << std::endl;
    return ai;
}
