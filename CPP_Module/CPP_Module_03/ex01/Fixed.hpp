#ifndef FIXED_CPP
#define FIXED_CPP 


#include <iostream>
#include <cmath>

class Fixed {
    private : int FixedPointNumber;
    private : static const int fractional = 8;
    
    public :
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed& f);
        ~Fixed();
    
    public : 
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        int toInt(void) const;
        float toFloat(void) const;
    // std::ostream &operator<<(std::ostream& os);
    // std::ostream &operator<<(std::ostream& os, const Fixed& f);
};

std::ostream &operator<<(std::ostream& os, const Fixed& f);

#endif