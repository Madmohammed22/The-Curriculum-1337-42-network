#include "Span.hpp"
Span::Span() : count(0)
{
    std::cout << "[Span] Constructor is called" << std::endl;
}

Span::Span(unsigned int N) : count(0), reserve(N)
{
    this->buffer.reserve(N);
    std::cout << "[Span] Parametrize constructor is called" << std::endl;
}
Span::Span(const Span &Init) : count(Init.count), reserve(Init.reserve)
{
    for (size_t i = 0; i < this->buffer.size(); i++)
        this->buffer[i] = Init.buffer[i];
}

Span &Span::operator=(const Span &Init)
{
    if (this == &Init)
        return *this;
    this->buffer.clear();
    for (size_t i = 0; i < this->buffer.size(); i++)
        this->buffer[i] = Init.buffer[i];
    return *this;
}

Span::~Span()
{
    this->buffer.clear();
    std::cout << "[Span] Distructor is called" << std::endl;
}

void Span::addNumber(int data)
{
    try
    {
        if ((this->count < this->reserve))
        {
            this->buffer.push_back(data);
            this->count++;
        }
        else
        {
            throw std::runtime_error("[Span] is full");
        }
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
        _Exit(EXIT_FAILURE);
    }
}

unsigned int Span::longestSpan()
{
    std::sort(this->buffer.begin(), this->buffer.end());
    return this->buffer.back() - this->buffer.front();
}

unsigned int Span::shortestSpan()
{
    std::vector<int> holder;
    for (size_t i = 0; i < this->buffer.size() - 1; i++)
    {
        if (this->buffer[i + 1] - this->buffer[i] >= 0)
            holder.push_back(this->buffer[i + 1] - this->buffer[i]);
    }
    std::sort(holder.begin(), holder.end());
    return holder.front();
}

void Span::display()
{
    for (size_t i = 0; i < this->buffer.size(); i++)
    {
        std::cout << this->buffer[i] << std::endl;
    }
}

void Span::addMany()
{
    // std::vector<int>::iterator myIter = this->buffer.front();
    // for (myIter = this->buffer.begin(); myIter != this->buffer.end(); myIter++)
    //     this->addNumber(rand() % this->reserve + 1);
    srand(time(NULL));
    for (size_t i = 0; i < this->reserve; i++)
        this->addNumber(rand() % this->reserve + 1);
}