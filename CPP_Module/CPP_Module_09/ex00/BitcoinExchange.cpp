#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    was_int = 0;
    was_float = 0;
    std::cout << "[BitcoinExchange] Default constructor is created" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &Init) : was_int(Init.was_int), was_float(Init.was_float)
{
    std::cout << "[BitcoinExchange] Copy constructor is created" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &Init)
{
    if (this == &Init)
        return *this;
    this->was_float = Init.was_float;
    this->was_int = Init.was_int;
    std::cout << "[BitcoinExchange] Assingment operator constructor is created" << std::endl;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "[BitcoinExchange] Distructor is created" << std::endl;
}

bool BitcoinExchange::scanString(std::string str, BitcoinExchange *scalar)
{
    double number = 0;
    if (((str.at(0) == '-' || str.at(0) == '+') && isdigit(str.at(1))) || isdigit(str.at(0)))
    {
        size_t start = 0;
        if (!isdigit(str.at(0)))
            start = 1;
        for (size_t i = start; i < str.length(); i++)
        {
            try
            {
                if (str.at(i) == '.')
                {
                    if (!(isdigit(str.at(i - 1)) && (str.at(i + 1) == 'f' || isdigit(str.at(i + 1)))))
                    {
                        return false;
                    }
                    scalar->was_float = 1;
                }

                if (str.at(i) == 'f' && str[i + 1] != '\0')
                {
                    if ((isdigit(str.at(i - 1)) && str.at(i) == 'f' && str[i + 1] == '\0') || (str.at(i - 1) == '.' && str.at(i) == 'f' && str[i + 1] == '\0'))
                    {
                        scalar->was_float = 1;
                        return true;
                    }

                    scalar->was_float = 0;
                    return false;
                }
                else if (str.at(i) != '.' && (str.at(i) != 'f' && !isdigit(str.at(i))))
                {
                    scalar->was_float = 0;
                    return false;
                }
            }
            catch (const std::exception &e)
            {
                return false;
            }
            if (str.at(i) != '.')
            {
                number = 10 * number + str.at(i) - '0';
                if (number > INT_MAX || number < INT_MIN)
                    return false;
            }
            else
                number = 0;
        }
    }
    else
        return false;

    scalar->was_int = 1;

    if (scalar->was_float == 1)
        scalar->was_int = 0;
    return true;
}

bool BitcoinExchange::KeepTruckOfString(char *split_data_file, int target, BitcoinExchange *scalar)
{
    std::vector<int> data;
    std::string str;
    int j = 0;

    if (target == 0)
    {
        str = strdup(split_data_file);
        for (size_t i = 0; i < strlen(split_data_file); i++)
        {
            if (split_data_file[i] == '-')
            {
                if (scanString(str.substr(j, i - j), scalar) == true)
                    data.push_back(atoi(str.substr(j, i - j).c_str()));
                else
                    return false;
                j = i + 1;
            }
        }
        if (scanString(str.substr(j, strlen(split_data_file) - 1), scalar) == true)
            data.push_back(atoi(str.substr(j, strlen(split_data_file) - 1).c_str()));
        else
            return false;
    }
    else if (target == 1)
    {
        str = strdup(split_data_file);
        if (scanString(str.substr(str.find(",") + 1, str.length()), scalar) == true)
        {
            if (scalar->was_int == 1 && was_float == 0)
                data.push_back(atoi(str.substr(str.find(",") + 1, str.length()).c_str()));
            else
            {
                std::cout << atof(str.substr(str.find(",") + 1, str.length()).c_str()) << std::endl;
                data.push_back(atof(str.substr(str.find(",") + 1, str.length()).c_str()));
            }
        }
        else
            return false;
    }

    std::vector<int>::iterator first = data.begin();
    std::vector<int>::iterator end = data.end();
    while (first != end)
    {
        // std::cout << *first << std::endl;
        first++;
    }
    std::cout << "--------------" << std::endl;
    return true;
}

bool BitcoinExchange::AddContenetFile_IfValid(std::string data_file, BitcoinExchange *scalar)
{
    char *dest = NULL;
    bool keep_truck = false;
    dest = strdup(data_file.c_str());
    char *split_data_file = std::strtok(dest, ",");
    if (KeepTruckOfString(split_data_file, 11, scalar) == true)
        keep_truck = true;
    split_data_file = std::strtok(NULL, ",");
    if (KeepTruckOfString(split_data_file, 1, scalar) == true && keep_truck == true)
        keep_truck = true;
    return keep_truck;
}

std::list<std::string> BitcoinExchange::ReadFileCSV(std::string file_csv, BitcoinExchange *scalar)
{

    std::ifstream file(file_csv.c_str());
    std::list<std::string> data_csv;
    if (!file.is_open())
    {
        std::cout << "Error opening the fil e!" << std::endl;
        _Exit(1);
    }
    std::string data;
    while (std::getline(file, data))
    {
        if (AddContenetFile_IfValid(data, scalar) == true)
            data_csv.push_back(data);
    }
    data_csv.remove("date,exchange_rate");
    file.close();
    return data_csv;
}

void BitcoinExchange::DisplayDataCSV(std::list<std::string> data_csv)
{
    std::list<std::string>::iterator first = data_csv.begin();
    std::list<std::string>::iterator end = data_csv.end();

    while (first != end)
    {
        std::cout<< *first << std::endl;
        first++;
    }
}