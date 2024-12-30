#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : was_int(0), was_float(0), from_large_number(0), wrong_format(0), scan_date(0)
{
    char buf[100];
    time_t t;
    struct tm *timeptr, result;

    setlocale(LC_ALL, "/QSYS.LIB/EN_US.LOCALE");
    t = time(NULL);
    timeptr = localtime(&t);
    strftime(buf, sizeof(buf), "%a %m/%d/%Y %r", timeptr);
    if (strptime(buf, "%a %m/%d/%Y %r", &result) == NULL)
        printf("\nstrptime failed\n");
    else
    {
        this->current_year = result.tm_year + 1900;
        this->current_month = result.tm_mon;
        this->current_day = result.tm_mday;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &Init) : was_int(Init.was_int), was_float(Init.was_float), from_large_number(Init.from_large_number), wrong_format(Init.wrong_format), scan_date(Init.scan_date)
{
    this->current_year = Init.current_year;
    this->current_month = Init.current_month;
    this->current_day = Init.current_day;
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

float return_result_data_exchange(std::string s1, std::string s2)
{
    float amount = atof(s1.substr(s1.find("|") + 1, s1.length()).c_str());
    float exchange_rate = atof(s2.substr(s2.find(",") + 1, s2.length()).c_str());
    return amount * exchange_rate;
}

float closestNumbers(std::list<std::string> vec, int number, std::string save_from_input)
{
    std::pair<int, std::string> closest_numbers;
    closest_numbers.first = number;
    closest_numbers.second = "";
    std::list<std::string>::iterator start = vec.begin();
    std::list<std::string>::iterator last = vec.end();
    while (start != last)
    {
        std::string save = *start;
        std::string current = *start;
        current = current.substr(0, current.find(","));
        current.erase(remove(current.begin(), current.end(), '-'), current.end());
        if (atoi(current.c_str()) == number)
        {
            closest_numbers.first = atoi(current.c_str());
            closest_numbers.second = save;
            return return_result_data_exchange(trim(save_from_input), trim(closest_numbers.second));
        }
        if (atoi(current.c_str()) < number &&
            (atoi(current.c_str()) > closest_numbers.first || closest_numbers.first == number))
        {
            closest_numbers.first = atoi(current.c_str());
            closest_numbers.second = save;
        }
        start++;
    }
    return return_result_data_exchange(trim(save_from_input), trim(closest_numbers.second));
}

void BitcoinExchange::resetFlags(BitcoinExchange *scalar)
{
    scalar->was_int = 0;
    scalar->was_float = 0;
    scalar->from_large_number = 0;
    scalar->was_negative_number = 0;
    scalar->wrong_format = 0;
    scalar->scan_date = 0;
}

int count_underscores(std::string s)
{
    int count = 0;

    for (size_t i = 0; i < s.size(); i++)
        if (s[i] == '-')
            count++;

    return count;
}

bool BitcoinExchange::scanString(std::string str, BitcoinExchange *scalar, int flag)
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
                        return false;
                    scalar->was_float = 1;
                }

                if (str.at(i) == 'f' && str[i + 1] != '\0')
                {
                    if ((isdigit(str.at(i - 1)) && str.at(i) == 'f' && str[i + 1] == '\0') || (str.at(i - 1) == '.' && str.at(i) == 'f' && str[i + 1] == '\0'))
                        return scalar->was_float = 1, true;
                    return scalar->was_float = 0, false;
                }
                else if (str.at(i) != '.' && (str.at(i) != 'f' && !isdigit(str.at(i))))
                    return scalar->was_float = 0, false;
            }
            catch (const std::exception &e)
            {
                return false;
            }
            if (str.at(i) != '.')
            {
                number = 10 * number + str.at(i) - '0';
                if (number > INT_MAX || number < INT_MIN)
                    return this->from_large_number = 1, false;
            }
            else
                number = 0;
        }
    }
    else
        return false;

    scalar->was_int = 1;
    if (scalar->was_float == 1 && flag == 0)
        return scalar->was_float = 0, scalar->was_int = 0, scalar->wrong_format = 1, false;
    if (scalar->was_float == 1)
        scalar->was_int = 0;
    if (atoi(str.c_str()) < 0)
        return was_negative_number = 1, false;
    return true;
}
std::string get_str_between_two_str(const std::string &s,
                                    const std::string &start_delim,
                                    const std::string &stop_delim)
{
    unsigned first_delim_pos = s.find(start_delim);
    unsigned end_pos_of_first_delim = first_delim_pos + start_delim.length();
    unsigned last_delim_pos = s.rfind(stop_delim);
    return s.substr(end_pos_of_first_delim, last_delim_pos - end_pos_of_first_delim);
}

bool BitcoinExchange::KeepTruckOfString(char *split_data_file, int target, BitcoinExchange *scalar, int flag)
{
    std::string save = split_data_file;
    save = trim(save);
    split_data_file = strdup(save.c_str());
    std::vector<int> data;
    std::string str;
    int j = 0;

    if (target == 0 && flag == 0)
    {
        str = strdup(split_data_file);
        if (count_underscores(str) != 2 || str.find("-") == 0)
            return wrong_format = 1, false;
        for (size_t i = 0; i < strlen(split_data_file); i++)
        {
            if (split_data_file[i] == '-')
            {
                if (scanString(str.substr(j, i - j), scalar, 0) == true)
                {
                    data.push_back(atoi(str.substr(j, i - j).c_str()));
                    was_float = 0;
                }
                else
                    return this->wrong_format = 1, false;
                j = i + 1;
            }
        }
        if (atoi(get_str_between_two_str(str, "-", "-").c_str()) > 31)
            return this->wrong_format = 1, false;
        if (scanString(str.substr(j, strlen(split_data_file) - 1), scalar, 0) == true)
            data.push_back(atoi(str.substr(j, strlen(split_data_file) - 1).c_str()));
        else
            return this->wrong_format = 1, false;
        if (scalar->was_float == 1)
            return scalar->wrong_format = 1, false;
        resetFlags(scalar);
    }

    else if (target == 1 && flag == 1)
    {
        str = strdup(split_data_file);
        if (scanString(str.substr(str.find(",") + 1, str.length()), scalar, 1) == true)
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

        if (scalar->was_negative_number == 1)
            return false;
    }
    return true;
}

bool BitcoinExchange::AddContenetFileIfValid(std::string data_file, BitcoinExchange *scalar, std::string seprator)
{
    if (data_file.empty())
        return false;
    char *dest = NULL;
    bool keep_truck = false;
    dest = strdup(trim(data_file).c_str());
    if (seprator.compare("|") == 0)
    {
        if (data_file.find("|") == std::string::npos)
            return scalar->wrong_format = 1, false;
        char *split_data_file = std::strtok(dest, "|");
        if (KeepTruckOfString(split_data_file, 0, scalar, 0) == true)
            keep_truck = true;
        resetFlags(scalar);
        split_data_file = std::strtok(NULL, "|");
        if (keep_truck == true && KeepTruckOfString(split_data_file, 1, scalar, 1) == true)
            keep_truck = true;
        else
        {
            scalar->wrong_format = 1;
            return false;
        }
        resetFlags(scalar);
    }

    if (seprator.compare(",") == 0)
    {
        if (data_file.find(",") == std::string::npos)
            return false;
        char *split_data_file = std::strtok(dest, ",");
        if (KeepTruckOfString(split_data_file, 0, scalar, 0) == true)
            keep_truck = true;
        split_data_file = std::strtok(NULL, ",");
        if (KeepTruckOfString(split_data_file, 1, scalar, 1) == true && keep_truck == true)
            keep_truck = true;
        else
            keep_truck = false;
    }

    return keep_truck;
}

float BitcoinExchange::proccess_correct_data(std::string line)
{
    std::string send = line;
    line = line.substr(0, line.find(" "));
    line.erase(remove(line.begin(), line.end(), '-'), line.end());
    int target_to_search = atoi(line.c_str());
    this->data_input_csv.sort();
    std::list<std::string>::iterator start = this->data_input_csv.begin();
    std::list<std::string>::iterator last = this->data_input_csv.end();
    while (start != last)
    {
        std::string current = *start;
        current = current.substr(0, current.find(","));
        current.erase(remove(current.begin(), current.end(), '-'), current.end());
        if (target_to_search != atoi(current.c_str()))
            return closestNumbers(this->data_input_csv, target_to_search, send);
        start++;
    }
    return target_to_search;
}
std::string BitcoinExchange::to_string(float number)
{
    std::ostringstream ss;
    ss.precision(2);
    ss << std::fixed << number;
    std::string s(ss.str());
    return s;
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
            this->data_input_csv.push_back(trim(line));
    }
    line.clear();
    while (std::getline(file, line))
    {
        line = trim(line);
        if (line.compare("date | value") != 0)
        {
            if (AddContenetFileIfValid(line, scalar, "|") == true && scalar->was_negative_number != 1 && scalar->from_large_number != 1 && scalar->wrong_format != 1)
            {
                std::string float_strin = to_string(proccess_correct_data(line));
                outputFile << line.substr(0, line.find("|") - 1) + " =>" + line.substr(line.find("|") + 1, line.length()) + " = " + to_string(proccess_correct_data(line)) + "\n";
                resetFlags(scalar);
            }
            else
            {
                if (scalar->from_large_number == 1)
                {
                    outputFile << "Error: too large a number.\n";
                    resetFlags(scalar);
                }

                if (scalar->was_negative_number == 1)
                {
                    outputFile << "Error: not a positive number.\n";
                    resetFlags(scalar);
                }
                if (scalar->wrong_format == 1)
                {
                    outputFile << "Error: bad input => " + line + "\n";
                    resetFlags(scalar);
                }
            }
        }
    }
    resetFlags(scalar);
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
    while (first != end)
    {
        std::cout << *first << std::endl;
        first++;
    }
}