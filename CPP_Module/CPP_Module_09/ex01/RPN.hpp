#ifndef RPN_HPP
#define RPN_HPP

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

class RPN{

    public:
        RPN();
        RPN(const RPN& Init);
        RPN& operator=(const RPN& Init);
        ~RPN();

    public:
        int resultRPN(std::string expression);
        
};

#endif