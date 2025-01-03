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

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <time.h>
#include <exception>    

#include <algorithm>
#include <cassert>
#include <cctype>
#include <complex>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class BitcoinExchange
{

public:
    int was_int;
    int was_float;
    int from_large_number;
    int was_negative_number;
    int wrong_format;
    int scan_date;
    int current_day;
    int current_month;
    int current_year;
    std::string curret_time_as_string;
    std::string time_when_bitcoin_was_released;
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
    bool AddContenetFileIfValid(std::string file_data, BitcoinExchange *scalar, std::string seprator);
    void DisplayDataCSV(std::list<std::string> data_csv);
    bool scanString(std::string str, BitcoinExchange *scalar, int flag);
    bool KeepTruckOfString(std::string split_data_file, int target, BitcoinExchange *scalar, int flag);
    float proccess_correct_data(std::string line);
    void resetFlags(BitcoinExchange *scalar);
    std::string to_string(float nunber); 
    bool check_accurency(std::string str, BitcoinExchange *scalar);
};

inline std::string trim(std::string &str)
{
    str.erase(str.find_last_not_of(' ') + 1);
    str.erase(0, str.find_first_not_of(' '));
    return str;
}

inline bool isnonnum(char c) {
	return !((c >= '0' && c <= '9') || c == '.');
}

inline void BitcoinExchange::DisplayDataCSV(std::list<std::string> data_csv_txt)
{
    std::list<std::string>::iterator first = data_csv_txt.begin();
    std::list<std::string>::iterator end = data_csv_txt.end();
    while (first != end)
    {
        std::cout << *first << std::endl;
        first++;
    }
}

#endif