#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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
#include <bits/stdc++.h>
#include <fstream>
#include <string>

class BitcoinExchange
{

private:
    int was_int;
    int was_float;
    std::list<std::string> data_input_csv;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &Init);
    BitcoinExchange &operator=(const BitcoinExchange &Init);
    ~BitcoinExchange();

public:
    std::list<std::string> ReadFileCSV(std::string file_csv, BitcoinExchange *scalar);
    bool AddContenetFile_IfValid(std::string file_data, BitcoinExchange *scalar, std::string seprator);
    void DisplayDataCSV(std::list<std::string> data_csv);
    bool scanString(std::string str, BitcoinExchange *scalar);
    bool KeepTruckOfString(char *split_data_file, int target, BitcoinExchange *scalar);
};

#endif