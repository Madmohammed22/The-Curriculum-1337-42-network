#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <algorithm>
#include <vector>

template <typename T>
int easyfind(T &buffer, int target)
{
    std::vector<int> holder;
    int size = sizeof(buffer) / sizeof(buffer[0]);
    for (int i = 0; i < size; i++)
        holder.push_back(buffer[i]);

    std::vector<int>::iterator Iter = std::find(holder.begin(), holder.end(), target);
    if (!(Iter == holder.end()))
        return *Iter;
    throw std::runtime_error("Target not found");
}
#endif