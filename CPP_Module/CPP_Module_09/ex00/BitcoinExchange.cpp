#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : was_int(0), was_float(0), from_large_number(0), wrong_format(0)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &Init) : was_int(Init.was_int), was_float(Init.was_float), from_large_number(Init.from_large_number), wrong_format(Init.wrong_format)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &Init)
{
    if (this == &Init)
        return *this;
    this->was_float = Init.was_float;
    this->was_int = Init.was_int;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
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
                {
                    this->from_large_number = 1;
                    return false;
                }
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
    if (atoi(str.c_str()) < 0)
        was_negative_number = 1;
    return true;
}

inline std::string trim(std::string &str)
{
    str.erase(str.find_last_not_of(' ') + 1);
    str.erase(0, str.find_first_not_of(' '));
    return str;
}

bool BitcoinExchange::KeepTruckOfString(char *split_data_file, int target, BitcoinExchange *scalar)
{

    std::string save = split_data_file;
    save = trim(save);
    split_data_file = strdup(save.c_str());
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
                {
                    return false;
                }
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
                data.push_back(atof(str.substr(str.find(",") + 1, str.length()).c_str()));
            }
        }
        else
            return false;
    }
    return true;
}

bool BitcoinExchange::AddContenetFile_IfValid(std::string data_file, BitcoinExchange *scalar, std::string seprator)
{
    char *dest = NULL;
    bool keep_truck = false;
    dest = strdup(trim(data_file).c_str());
    if (seprator.compare("|") == 0)
    {
        if (data_file.find("|") == std::string::npos)
            return scalar->wrong_format = 1,  false;
        char *split_data_file = std::strtok(dest, "|");
        if (KeepTruckOfString(split_data_file, 0, scalar) == true)
            keep_truck = true;
        split_data_file = std::strtok(NULL, "|");
        if (keep_truck == true && KeepTruckOfString(split_data_file, 1, scalar) == true)
            keep_truck = true;
        else
            keep_truck = false;
    }

    if (seprator.compare(",") == 0)
    {
        if (data_file.find(",") == std::string::npos)
            return false;
        char *split_data_file = std::strtok(dest, ",");
        if (KeepTruckOfString(split_data_file, 0, scalar) == true)
        {
            keep_truck = true;
        }
        split_data_file = std::strtok(NULL, ",");
        if (KeepTruckOfString(split_data_file, 1, scalar) == true && keep_truck == true)
        {
            keep_truck = true;
        }
    }
    return keep_truck;
}

std::list<std::string> BitcoinExchange::ReadFileCSV(std::string file_txt, BitcoinExchange *scalar)
{

    std::ifstream file(file_txt.c_str());
    std::ofstream outputFile("outputFile.txt");
    std::list<std::string> data_csv_txt;
    std::ifstream data_base_as_file("data.csv");
    if (!file.is_open() || !data_base_as_file.is_open() || !outputFile.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        _Exit(1);
    }
    std::string data;
    while (std::getline(file, data))
    {
        if (data.compare("date | value") != 0)
        {

            if (AddContenetFile_IfValid(data, scalar, "|") == true && scalar->was_negative_number != 1 
            && scalar->from_large_number != 1 && scalar->wrong_format != 1)
            {
                data = trim(data);
                data_csv_txt.push_back(data);
                outputFile << data.substr(0, data.find("|") - 1) + " =>" + data.substr(data.find("|") + 1, data.length()) +  "\n";
            }
            else
            {
                if (scalar->from_large_number == 1){
                    scalar->from_large_number = 0;
                    outputFile << "Error: too large a number.\n";
                }
                if (scalar->was_negative_number == 1){
                    scalar->was_negative_number = 0;
                    outputFile << "Error: not a positive number.\n";
                }
                if (scalar->wrong_format == 1)
                {
                    scalar->wrong_format = 0;
                    outputFile << "Error: bad input => " + data + "\n";
                }
            }
        }
    }
    data.clear();
    while (std::getline(data_base_as_file, data))
    {
        if (data.compare("date,exchange_rate") != 0)
        {
            data = trim(data);
            if (AddContenetFile_IfValid(data, scalar, ",") == true)
                this->data_input_csv.push_back(data);
        }
    }

    file.close();
    data_base_as_file.close();
    return data_csv_txt;
}

void BitcoinExchange::DisplayDataCSV(std::list<std::string> data_csv_txt)
{
    std::list<std::string>::iterator first = data_csv_txt.begin();
    std::list<std::string>::iterator end = data_csv_txt.end();

    while (first != end)
    {
        std::cout << *first << std::endl;
        first++;
    }
}