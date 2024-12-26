#ifndef BRAIN_HPP
#define BRAIN_HPP 

#include <iostream>

class Brain{
public:
    Brain();
    Brain(const Brain& b);
    Brain& operator=(const Brain& b);
    ~Brain();

public:
    std::string ideas[100];
    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif