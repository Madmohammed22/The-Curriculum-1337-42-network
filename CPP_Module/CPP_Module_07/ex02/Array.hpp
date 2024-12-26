#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <class T>
class Array
{

public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &Init);
    Array<T> &operator=(const Array<T> &Init);
    T &operator[](int Index);
    const T &operator[](int Index) const;
    ~Array();

public:
    int getSize() const;
    void display() const;
    T at(int index);

private:
    T *arr;
    unsigned int size;
};


template <class T>
Array<T>::Array()
{
    this->arr = new T;
    std::cout << "[Array] constructor is called" << std::endl;
}

template <class T>
Array<T>::Array(unsigned int n) : size(n)
{
    this->arr = new T[n];
    std::cout << "[Array] parametrize constructor is called" << std::endl;
}

template <class T>
Array<T>::Array(const Array<T> &Init) : size(Init.size)
{

    this->arr = new T[Init.getSize()];
    for (int i = 0; i < Init.getSize(); i++)
    {
        this->arr[i] = Init.arr[i];
    }
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &Init)
{
    if (this != &Init)
    {
        delete[] this->arr;
        this->arr = new T[Init.getSize()];
        for (int i = 0; i < Init.getSize(); i++)
        {
            this->arr[i] = Init.arr[i];
        }
        return *this;
    }

    return *this;
}

template <class T>
T Array<T>::at(int index)
{
    try
    {
        // 100           // 10
        if (index < this->getSize())
            return this->arr[index];
        else
            throw std::runtime_error("Index out of bound");
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
        _Exit(EXIT_FAILURE);
    }
    return this->arr[index];
}

// template <class T>
// T Array<T>::operator[](int Index)
// {
//     return const_cast<T&>(std::as_const(*this)[Index]);
//     // return this->arr[Index];
// }

template <class T>
T &Array<T>::operator[](int Index)
{
    if (Index < 0 || Index >= this->getSize())
        throw std::runtime_error("Index out of bound..");
    return arr[Index];
}

template <class T>
const T &Array<T>::operator[](int Index) const
{
    if (Index < 0 || Index >= this->getSize())
        throw std::runtime_error("Index out of bound");
    return arr[Index];
}

template <class T>
Array<T>::~Array()
{
    delete[] this->arr;
    std::cout << "[Array] Distructor is called" << std::endl;
}

template <typename T>
int Array<T>::getSize() const
{
    return this->size;
}

template <typename T>
void Array<T>::display() const
{
    for (int i = 0; i < this->getSize(); i++)
    {
        std::cout << arr[i] << std::endl;
    }
}
#endif