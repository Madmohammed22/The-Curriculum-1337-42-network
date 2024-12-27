#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <stack>
#include <list>
#include <map>
#include <unistd.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <deque>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

class BitcoinExchange{

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& Init);
        BitcoinExchange& operator=(const BitcoinExchange& Init);
        ~BitcoinExchange();

    public:
        std::list<std::string> ReadFileCSV(std::string file_csv);
        bool AddContenetFile_IfValid(std::string file_data);
        void DisplayDataCSV(std::list<std::string> data_csv);
};

#endif