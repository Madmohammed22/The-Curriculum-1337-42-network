#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

class Iter{
    public:
        Iter();
        Iter(const Iter& iter);
        Iter& operator=(const Iter& iter);
        ~Iter();
};


template <class T> void swap(T& t1, T& t2){
    T tmp;
    tmp = t1;
    t1 = t2;
    t2 = tmp;
}

template <typename T> void bubbleSort(T* arr, int size, void (*f)(T&, T&)){
    for (int i = 0; i < size - 1; i++){
        for (int j = size - 1; i < j; j--){
            if (arr[j] < arr[j - 1])
                f(arr[j], arr[j - 1]);
        }
    }
}

template <typename T> bool search(T* arr, T& target, int size){
    for(int i = 0; i < size; i++){
        if (arr[i] == target)
            return true;
    }

    return false;
}

template<typename T > void check_status_of_data(T& data)
{
    std::cout << data << std::endl;
}

template void check_status_of_data<int>(int &data);
template void check_status_of_data<float>(float &data);
template void check_status_of_data<char>(char &data);

template <class T> void iter(T *t1, int size, void (*f)(T& )){
    for (int i = 0; i < size; i++){
        f(t1[i]);
    }
}

#endif