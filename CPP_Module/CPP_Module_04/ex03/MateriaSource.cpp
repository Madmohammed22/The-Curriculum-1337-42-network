#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        materias[i] = NULL;
    }
    std::cout << "[MateriaSource] Default constructor is called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i) {
        if (other.materias[i]) {
            materias[i] = other.materias[i]->clone();
        } else {
            materias[i] = NULL;
        }
    }
    std::cout << "[MateriaSource] Copy constructor is called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete materias[i];
            if (other.materias[i]) {
                materias[i] = other.materias[i]->clone();
            } else {
                materias[i] = NULL;
            }
        }
    }
    std::cout << "[MateriaSource] Copy assignment operator is called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete materias[i];
    }
    std::cout << "[MateriaSource] Destructor is called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; ++i) {
        if (!materias[i]) {
            materias[i] = m;
            std::cout << "[MateriaSource] Learned " << m->getType() << " materia" << std::endl;
            return;
        }
    }
    std::cout << "[MateriaSource] No space to learn new materia" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; ++i) {
        if (materias[i] && materias[i]->getType() == type) {
            return materias[i]->clone();
        }
    }
    std::cout << "[MateriaSource] No materia of type " << type << " found" << std::endl;
    return NULL;
}