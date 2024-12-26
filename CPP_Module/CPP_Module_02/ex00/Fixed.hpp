#ifndef FIXED_CPP
#define FIXED_CPP 


#include <iostream>

class Fixed {
    private : int FixedPointNumber;
    private : static const int fractional = 8;
    
    public : 
        Fixed();
        Fixed (const Fixed &copy);
        Fixed &operator=(const Fixed& f);
        ~Fixed();

    public : int getRawBits( void ) const;
    public : void setRawBits( int const raw );
};

#endif