#ifndef FIXED_CPP
#define FIXED_CPP 


#include <iostream>
#include <cmath>

class Fixed {
    private : int FixedPointNumber;
    private : static const int fractional = 8;
    public :Fixed();
            Fixed(const int value);
            Fixed(const float value);
            Fixed(const Fixed &copy);
            Fixed &operator=(const Fixed& f);
            ~Fixed();

    public : int getRawBits( void ) const;
    public : void setRawBits( const int raw );
    public : int toInt(void) const;
    public : float toFloat(void) const;
    static Fixed const& max(Fixed const& a, Fixed const& b);
    static Fixed& max(Fixed& lhs, Fixed& rhs);
    static Fixed const& min(Fixed const& a, Fixed const& b);
    static Fixed& min(Fixed& lhs, Fixed& rhs);
    // std::ostream &operator<<(std::ostream& os);
};
std::ostream &operator<<(std::ostream& os, const Fixed& f);

// comparison operators:
bool operator>(const Fixed& lhs, const Fixed& rhs);
bool operator<(const Fixed& lhs, const Fixed& rhs);
bool operator>=(const Fixed& lhs, const Fixed& rhs);
bool operator<=(const Fixed& lhs, const Fixed& rhs);
bool operator==(const Fixed& lhs, const Fixed& rhs);
bool operator!=(const Fixed& lhs, const Fixed& rhs);


// arithmetic operators:
Fixed operator+(const Fixed& lhs, const Fixed& rhs);
Fixed operator-(const Fixed& lhs, const Fixed& rhs);
Fixed operator*(const Fixed& lhs, const Fixed& rhs);
Fixed operator/(const Fixed& lhs, const Fixed& rhs);

Fixed& operator++(Fixed& f);
Fixed operator++(Fixed& f, int);

Fixed& operator--(Fixed& f);
Fixed operator--(Fixed& f, int);


#endif