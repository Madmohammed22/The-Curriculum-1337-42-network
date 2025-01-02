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
};



#endif