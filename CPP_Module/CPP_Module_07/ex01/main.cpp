#include "iter.hpp"

void Test_function(int &data)
{
    std::cout << data << std::endl;
}

int main()
{
    {
        int arr[] = {1, 2, 3, -4, 10};
        int size = sizeof(arr) / sizeof(int);
        ::iter(arr, size, ::check_status_of_data<int>);
    }

    std::cout << "------------------------" << std::endl;

    {
        float arr[] = {1.0, 2.9, 22.00};
        int size = sizeof(arr) / sizeof(float);
        ::iter(arr, size, ::check_status_of_data<float>);
    }

    std::cout << "------------------------" << std::endl;

    {
        char arr[] = {'1', '2', '2'};
        int size = sizeof(arr) / sizeof(char);
        ::iter(arr, size, ::check_status_of_data<char>);
    }
    std::cout << "------------------------" << std::endl;
    {
        char arr[] = {'b', 'a', 's', 'z', 'x'};
        int size = sizeof(arr) / sizeof(char);
        bubbleSort(arr, size, ::swap);
        for (int i = 0; i < size; i++){
            std::cout << arr[i] << std::endl;
        }
    }
}
