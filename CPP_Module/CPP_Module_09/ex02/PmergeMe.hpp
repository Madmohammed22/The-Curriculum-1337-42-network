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
#include <set>
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
    std::vector<int> sorted_inpput;
    void displayNumber(std::vector<int> vec);
    void swapPairs_lv1(std::pair<int, int> &ai_bi);
    std::vector<int> ft_PmergeMe(std::vector<int> vec);
    std::vector<std::pair<int, int> > ft_PmergeMe_Recursion_lv1(const std::vector<int>& vec, int n);
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > ft_PmergeMe_recussion_lv2(std::vector<std::pair<int, int> > sub_comparisons, int n);
    void swapPairs_lv2(std::pair<std::pair<int, int>, std::pair<int, int> > &ai_bi);
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > 
    ft_PmergeMe_recursion_lv2(std::vector<std::pair<int, int> > sub_comparisons, int n);
};



#endif