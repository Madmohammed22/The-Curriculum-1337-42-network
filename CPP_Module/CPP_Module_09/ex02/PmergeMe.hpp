#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <map>
#include <list>

//-----------
#include <complex>
#include <iostream>
#include <stack>
#include <list>
#include <map>
#include <unistd.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <deque>
#include <fstream>

#include <iomanip>
#include <sstream>
#include <ctime>
#include <time.h>
#include <exception>    

#include <cassert>
#include <cctype>
#include <string_view>
//-------------

class PmergeMe
{
private:
    
public:
    PmergeMe();
    PmergeMe(const PmergeMe& Init);
    PmergeMe& operator=(const PmergeMe& Init);
    ~PmergeMe();

public:
    std::vector<int> vec;
    void displayNumber(std::vector<int> vec);
    void swapPairs(std::pair<int, int> &ai_bi);
    std::vector<int> ft_PmergeMe(std::vector<int> vec);
    std::vector<std::pair<int, int> > ft_PmergeMe_Recursion(const std::vector<int>& vec, int n);
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > ft_PmergeMe_recussion_lv2(std::vector<std::pair<int, int> > sub_comparisons, int n);
    void swapPairs_lv2(std::pair<std::pair<int, int>, std::pair<int, int> > &ai_bi);
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> >, std::pair<std::pair<int, int>, std::pair<int, int> > > 
    ft_PmergeMe_recussion_lv3(std::pair<std::pair<int, int>, std::pair<int, int> > sub_comparisons, int n);
};



#endif