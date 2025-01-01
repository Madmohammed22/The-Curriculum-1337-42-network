#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &Init)
{
    (void)Init;
}

RPN &RPN::operator=(const RPN &Init)
{
    (void)Init;
    return *this;
}

RPN::~RPN()
{
}

int RPN::resultRPN(std::string expression)
{
    std::stack<int> mstack;
    int first_operands;
    int second_operands;
    if (expression.empty())
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());
    for (size_t i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        if (isdigit(c))
        {
            std::string operands(1, expression[i]);
            int number = atoi(operands.c_str());
            mstack.push(number);
        }
        else
        {
            switch (c)
            {
            case '+':
                if (mstack.size() != 2)
                {
                    std::cout << "Error" << std::endl;
                    exit(1);
                }
                second_operands = mstack.top();
                mstack.pop();
                first_operands = mstack.top();
                mstack.pop();

                mstack.push((first_operands + second_operands));
                break;

            case '-':

                second_operands = mstack.top();
                mstack.pop();
                try
                {
                    if (mstack.size() <= 0)
                        throw std::runtime_error("Error");
                    first_operands = mstack.top();
                }
                catch (const std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                    exit(1);
                }
                mstack.pop();
                mstack.push((first_operands - second_operands));
                break;

            case '*':
                if (mstack.size() != 2)
                {
                    std::cout << "Error" << std::endl;
                    exit(1);
                }
                second_operands = mstack.top();
                mstack.pop();
                first_operands = mstack.top();
                mstack.pop();

                mstack.push((first_operands * second_operands));
                break;

            case '/':
                if (mstack.size() != 2)
                {
                    std::cout << "Error" << std::endl;
                    exit(1);
                }
                second_operands = mstack.top();
                mstack.pop();
                first_operands = mstack.top();
                mstack.pop();
                try
                {
                    if (first_operands == 0)
                        throw std::runtime_error("Error");
                    mstack.push((first_operands / second_operands));
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                    exit(1);
                }
                break;
            default:
                std::cout << "Error" << std::endl;
                exit(1);
            }
        }
    }
    return mstack.top();
}