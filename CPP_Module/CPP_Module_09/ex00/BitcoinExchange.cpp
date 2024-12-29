#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : was_int(0), was_float(0), from_large_number(0), wrong_format(0), scan_date(0)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &Init) : was_int(Init.was_int), was_float(Init.was_float), from_large_number(Init.from_large_number), wrong_format(Init.wrong_format), scan_date(Init.scan_date)
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
    if (scalar->scan_date == 1)
        return false;
    // if (scalar->was_int == 1 && this->scan_date == 1 && scalar->was_float == 1)
    // {
    //     this->scan_date = 0;
    //     scalar->was_float = 0;
    //     scalar->was_int = 0;
    //     return false;
    // }

    if (atoi(str.c_str()) < 0)
    {
        was_negative_number = 1;
    }
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
                if (scanString(str.substr(j, i - j), scalar) == true){
                    // if (scalar->was_float == 1)
                    //     return this->wrong_format = 1, false;
                    data.push_back(atoi(str.substr(j, i - j).c_str()));
                }
                else
                {
                    this->wrong_format = 1;
                    return false;
                }
                j = i + 1;
            }
        }
        if (scanString(str.substr(j, strlen(split_data_file) - 1), scalar) == true)
            data.push_back(atoi(str.substr(j, strlen(split_data_file) - 1).c_str()));
        else
        {
            this->wrong_format = 1;
            return false;
        }
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
            return scalar->wrong_format = 1, false;
        char *split_data_file = std::strtok(dest, "|");
        if (KeepTruckOfString(split_data_file, 0, scalar) == true)
            keep_truck = true;
        split_data_file = std::strtok(NULL, "|");
        if (keep_truck == true && KeepTruckOfString(split_data_file, 1, scalar) == true)
            keep_truck = true;
        else{
            // scalar->wrong_format = 0;
            return false;
        }
    }

    if (seprator.compare(",") == 0)
    {
        if (data_file.find(",") == std::string::npos)
            return false;
        char *split_data_file = std::strtok(dest, ",");
        if (KeepTruckOfString(split_data_file, 0, scalar) == true)
            keep_truck = true;
        split_data_file = std::strtok(NULL, ",");
        if (KeepTruckOfString(split_data_file, 1, scalar) == true && keep_truck == true)
            keep_truck = true;
        else
            keep_truck = false;
    }

    return keep_truck;
}

int closestNumbers(std::list<std::string> vec, int number)
{
    std::pair<int, int> closest_numbers;
    closest_numbers.first = number;
    closest_numbers.second = number;
    std::list<std::string>::iterator start = vec.begin();
    std::list<std::string>::iterator last = vec.end();
    // // Find closest below.
    while (start != last)
    {
        std::string current = *start;
        current = current.substr(0, current.find(","));
        current.erase(remove(current.begin(), current.end(), '-'), current.end());
        if (atoi(current.c_str()) == number)
            closest_numbers.first = atoi(current.c_str());
        if (atoi(current.c_str()) < number &&
            (atoi(current.c_str()) > closest_numbers.first || closest_numbers.first == number))
        {
            closest_numbers.first = atoi(current.c_str());
        }
        start++;
    }
    // // Find closest above.

    start = vec.begin();
    last = vec.end();

    while (start != last)
    {
        std::string current = *start;
        current = current.substr(0, current.find(","));
        current.erase(remove(current.begin(), current.end(), '-'), current.end());
        if (atoi(current.c_str()) > number &&
            (atoi(current.c_str()) < closest_numbers.second || closest_numbers.second == number))
        {
            closest_numbers.second = atoi(current.c_str());
        }
        start++;
    }
    int result = closest_numbers.first;
    return result;
}

int BitcoinExchange::proccess_correct_data(std::string line)
{

    line = line.substr(0, line.find(" "));
    line.erase(remove(line.begin(), line.end(), '-'), line.end());
    int target_to_search = atoi(line.c_str());
    this->data_input_csv.sort();
    std::list<std::string>::iterator start = this->data_input_csv.begin();
    std::list<std::string>::iterator last = this->data_input_csv.end();
    while (start != last)
    {
        std::string save = *start;
        std::string current = *start;
        current = current.substr(0, current.find(","));
        current.erase(remove(current.begin(), current.end(), '-'), current.end());
        if (target_to_search == atoi(current.c_str()))
            return target_to_search;
        else
        {
            return closestNumbers(this->data_input_csv, target_to_search);
        }
        start++;
    }
    return target_to_search;
}

std::list<std::string> BitcoinExchange::ReadFileCSV(std::string file_txt, BitcoinExchange *scalar)
{

    std::ifstream file(file_txt.c_str());
    std::string filename = "Result.txt";
    std::ofstream outputFile(filename.c_str());
    std::list<std::string> data_csv_txt;

    std::ifstream data_base("data.csv");

    if (!file.is_open() || !data_base.is_open() || !outputFile.good())
    {
        std::cout << "Error: could not open file." << std::endl;
        _Exit(1);
    }
    std::string line;

    while (std::getline(data_base, line))
    {
        if (line.compare("date,exchange_rate") != 0)
        {
            line = trim(line);
            if (AddContenetFile_IfValid(line, scalar, ",") == true)
                this->data_input_csv.push_back(line);
        }
    }
    scalar->wrong_format = 0;
    line.clear();
    while (std::getline(file, line))
    {
        line = trim(line);
        if (line.compare("date | value") != 0)
        {

            if (AddContenetFile_IfValid(line, scalar, "|") == true && scalar->was_negative_number != 1 && scalar->from_large_number != 1 && scalar->wrong_format != 1)
            {
                std::cout << "proccess_correct_data : " << proccess_correct_data(line) << std::endl;
                outputFile << line.substr(0, line.find("|") - 1) + " =>" + line.substr(line.find("|") + 1, line.length()) + " = " + "\n";
            }
            else
            {
                if (scalar->from_large_number == 1)
                    outputFile << "Error: too large a number.\n";
                if (scalar->was_negative_number == 1)
                    outputFile << "Error: not a positive number.\n";
                if (scalar->wrong_format == 1)
                    outputFile << "Error: bad input => " + line + "\n";
                scalar->wrong_format = 0;
                scalar->was_negative_number = 0;
                scalar->from_large_number = 0;
            }
        }
    }
    outputFile.close();
    line.clear();
    data_csv_txt.clear();
    std::ifstream inputFile(filename.c_str());
    while (std::getline(inputFile, line))
        data_csv_txt.push_back(line);

    inputFile.close();
    file.close();
    data_base.close();
    return data_csv_txt;
}

void BitcoinExchange::DisplayDataCSV(std::list<std::string> data_csv_txt)
{

    std::list<std::string>::iterator first = data_csv_txt.begin();
    std::list<std::string>::iterator end = data_csv_txt.end();
    std::cout << "------------------" << std::endl;
    while (first != end)
    {
        std::cout << *first << std::endl;
        first++;
    }
}