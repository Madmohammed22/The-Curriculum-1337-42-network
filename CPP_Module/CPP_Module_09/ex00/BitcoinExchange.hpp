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
    int from_large_number;
    int was_negative_number;
    int wrong_format;
    std::list<std::string> data_input_csv;
    std::vector<int> contains_year_month_day;
    std::vector<int> contains_value;
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
    double proccess_correct_data(std::string line);
};

#endif