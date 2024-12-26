#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
using namespace std;

class Harl{
    private :
        void debug();
        void info( void );
        void warning( void );
        void error( void );

    public :
        void complain(std::string level);
};

#endif