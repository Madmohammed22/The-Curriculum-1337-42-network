#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : was_int(0), was_float(0)
{
    // std::cout << "[ScalarConverter] Default constructor is called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &s)
{
    this->was_int = s.was_int;
    this->was_float = s.was_float;
    // std::cout << "[ScalarConverter] Copy constructor is called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this == &other)
        return *this;
    // std::cout << "[ScalarConverter] Assignment operator constructor is called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    // std::cout << "[ScalarConverter] Distructor is called" << std::endl;
}

int countAppearcanceOfChar(std::string s, char c)
{
    int count = 0;

    for (size_t i = 0; i < s.length(); i++)
        if (s[i] == c)
        {
            for (size_t j = i + 1; j < s.length(); j++)
            {
                if (isdigit(s.at(j)))
                    count++;
            }
            break;
        }
    return count;
}

bool ScalarConverter::scanString(std::string str, ScalarConverter *scalar)
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
                if ((str.at(i) == '.'))
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

void ScalarConverter::displayChar(std::string str, ScalarConverter *scalar)
{
    if (scalar->was_float)
    {
        std::cout << "char: '*'" << std::endl;
        return;
    }

    if (str.length() != 1)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = str[0] - 48;
    if (c >= 0 && c <= 32)
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: " << c << std::endl;
}

void ScalarConverter::displayInt(std::string str, ScalarConverter *scalar)
{
    if (!std::strcmp(str.c_str(), "+inff"))
    {
        displayChar(str, scalar);
        int infinity = std::numeric_limits<int>::max();
        std::cout << "int: " << infinity << std::endl;
        return;
    }
    else if (!std::strcmp(str.c_str(), "-inff"))
    {
        displayChar(str, scalar);
        int infinity = std::numeric_limits<int>::min();
        std::cout << "int: " << infinity << std::endl;
        return;
    }
    if (!scalar->scanString(str, scalar))
    {
        displayChar(str, scalar);
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        displayChar(str, scalar);
        std::cout << "int: " << atoi(str.c_str()) << std::endl;
    }
}

void ScalarConverter::displayFloat(std::string str, ScalarConverter *scalar)
{
    if (!std::strcmp(str.c_str(), "+inff"))
    {
        // std::cout << std::fixed;
        std::cout << std::setprecision(4);
        float infinity = std::numeric_limits<float>::max();
        std::cout << "float: " << infinity << std::endl;
        return;
    }
    else if (!std::strcmp(str.c_str(), "-inff"))
    {
        // std::cout << std::fixed;
        std::cout << std::setprecision(4);
        float infinity = std::numeric_limits<float>::min();
        std::cout << "float: " << infinity << std::endl;
        return;
    }
    if (!std::strcmp(str.c_str(), "nan") || !std::strcmp(str.c_str(), "nanf"))
    {
        std::cout << "float: " << "nan" << "f" << std::endl;
        return;
    }
    if (!scalar->scanString(str, scalar))
        std::cout << "float: impossible" << std::endl;
    else
    {
        if (scalar->was_float)
        {
            std::cout << std::fixed;
            std::cout << std::setprecision(countAppearcanceOfChar(str, '.'));
            if (countAppearcanceOfChar(str, '.') == 0){
                std::cout << std::fixed;
                std::cout << std::setprecision(1);
                std::cout << "float: " << atof(str.c_str()) << std::endl;
                return;
            }
            else
                std::cout << "float: " << atof(str.c_str()) << "f" << std::endl;
        }
        if (scalar->was_int)
        {
            std::cout << std::fixed;
            std::cout << std::setprecision(1);
            std::cout << "float: " << atof(str.c_str()) << "f" << std::endl;
        }
    }
}

void ScalarConverter::displayDouble(std::string str, ScalarConverter *scalar)
{
    if (!std::strcmp(str.c_str(), "+inf"))
    {
        // std::cout << std::fixed;
        std::cout << std::setprecision(4);
        double infinity = std::numeric_limits<double>::max();
        std::cout << "double: " << infinity << std::endl;
        return;
    }
    else if (!std::strcmp(str.c_str(), "-inf"))
    {
        // std::cout << std::fixed;
        std::cout << std::setprecision(4);
        double infinity = std::numeric_limits<double>::min();
        std::cout << "double: " << infinity << std::endl;
        return;
    }

    if (!std::strcmp(str.c_str(), "nan") || !std::strcmp(str.c_str(), "nanf"))
    {
        std::cout << "double: " << "nan" << std::endl;
        return;
    }
    if (!scalar->scanString(str, scalar))
        std::cout << "double: impossible" << std::endl;
    else
    {
        if (scalar->was_float)
        {
            std::cout << std::fixed;
            std::cout << std::setprecision(countAppearcanceOfChar(str, '.'));
            if (countAppearcanceOfChar(str, '.') == 0)
            {
                std::cout << std::fixed;
                std::cout << std::setprecision(1);
                std::cout << "doubl: " << atof(str.c_str()) << std::endl;
                return;
            }
            std::cout << "doubl: " << atof(str.c_str()) << std::endl;
        }

        if (scalar->was_int)
        {
            std::cout << std::fixed;
            std::cout << std::setprecision(1);
            std::cout << "doubl: " << atof(str.c_str()) << std::endl;
        }
    }
}

void ScalarConverter::convert(std::string str)
{
    // some Instruction mast be perform, with that said use function with
    // flag to specify sertain dissision. fi9 m3ana asat
    ScalarConverter *scalar = new ScalarConverter();
    displayInt(str, scalar);
    displayFloat(str, scalar);
    displayDouble(str, scalar);
    delete scalar;
}