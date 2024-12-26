#include "Brain.hpp"

Brain::Brain(){
    std :: cout << "[Brain] Default constructor is called" << std :: endl;
}
Brain::Brain(const Brain& b){ // deep copy for Brain
    for(int i = 0; i < 100; i++){
        ideas[i] = b.ideas[i];
    }
    std :: cout << "[Brain] copy constructor is called" << std :: endl;
}

Brain& Brain::operator=(const Brain& b){
    if (this != &b){
        for (int i = 0; i < 100; i++){
            this->ideas[i] = b.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain(){
    std::cout << "[Brain] destructed" << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        this->ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return this->ideas[index];
    }
    return "";
}