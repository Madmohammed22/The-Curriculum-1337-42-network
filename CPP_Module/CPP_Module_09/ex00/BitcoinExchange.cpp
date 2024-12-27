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

bool ft_keep_truck(char *split_data_file, int target){

    std::vector<int> data;
    int j = 0;
    int k = 0;
    std::string str;
    if (target == 0){
        for (size_t i = 0; i < strlen(split_data_file); i++){
            if (split_data_file[i] == '-'){
                str = strdup(split_data_file);
                data.push_back(atoi(str.substr(j, i - 1).c_str()));
                j = i + 1;
                k++;
            }
            if (k == 2){
                data.push_back(atoi(str.substr(i + 1, strlen(str.c_str())).c_str()));
                break;
            }
        }
    }
    // std::cout << "----------> " << j << " " << str << std::endl;
    // std::cout << "----------" << std::endl;
    // std::cout << "-> " << str.substr(j, strlen(split_data_file) - 1) << std::endl;
    // data.push_back(atoi(str.substr(j, strlen(split_data_file)).c_str()));

    std::vector<int>::iterator first = data.begin();
    std::vector<int>::iterator end = data.end();
    int i = 0;
    while (first != end)
    {
        if (i == 2)
            break;
        std::cout << *first << std::endl;
        first++;
        i++;
    }

    return true;
}

bool BitcoinExchange::AddContenetFile_IfValid(std::string data_file){
    char *dest = NULL;
    bool keep_truck = false;
    dest = strdup(data_file.c_str());
    char *split_data_file = std::strtok(dest, ",");
    if (ft_keep_truck(split_data_file, 0) == true)
        keep_truck = true;
    split_data_file =  std::strtok(NULL, ",");
    if (ft_keep_truck(split_data_file, 1) == true && keep_truck == true)
        keep_truck = true;
    return keep_truck;
}

std::list<std::string> BitcoinExchange::ReadFileCSV(std::string file_csv){

    std::ifstream file(file_csv.c_str());
    std::list<std::string> data_csv;
    if (!file.is_open()){
        std::cout << "Error opening the fil e!" << std::endl;
        _Exit(1);
    }
    std::string data;
    while (std::getline(file, data)){
        AddContenetFile_IfValid(data);
        data_csv.push_back(data);
    }
    data_csv.remove("date,exchange_rate");
    file.close();
    return data_csv;
}

void BitcoinExchange::DisplayDataCSV(std::list<std::string> data_csv){
    std::list<std::string>::iterator first = data_csv.begin();
    std::list<std::string>::iterator end = data_csv.end();
    
    while (first != end)
    {
        // std::cout<< *first << std::endl;
        first++;
    }
}