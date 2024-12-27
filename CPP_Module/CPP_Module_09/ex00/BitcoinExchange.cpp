#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::cout << "[BitcoinExchange] Default constructor is created" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& Init){
    (void)Init;
    std::cout << "[BitcoinExchange] Copy constructor is created" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& Init){
    if (this == &Init)
        return *this;
    std::cout << "[BitcoinExchange] Assingment operator constructor is created" << std::endl;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){
    std::cout << "[BitcoinExchange] Distructor is created" << std::endl;
}

std::list<std::string> BitcoinExchange::ReadFileCSV(std::string file_csv){

    std::ifstream file(file_csv.c_str());
    std::list<std::string> data_csv;
    if (!file.is_open()){
        std::cout << "Error opening the file!" << std::endl;
        _Exit(1);
    }
    std::string data;
    while (std::getline(file, data))
        data_csv.push_back(data);
    data_csv.remove("date,exchange_rate");
    file.close();
    return data_csv;
}

void BitcoinExchange::DisplayDataCSV(std::list<std::string> data_csv){
    std::list<std::string>::iterator first = data_csv.begin();
    std::list<std::string>::iterator end = data_csv.end();
    
    while (first != end)
    {
        std::cout<< *first << std::endl;
        first++;
    }
}