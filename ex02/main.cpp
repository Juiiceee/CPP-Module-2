#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a(1);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << (int)(a >= Fixed(1)) << std::endl;
	std::cout << (int)(a <= Fixed(1)) << std::endl;
	std::cout << (int)(a > Fixed(1))  * 3 << std::endl;
	std::cout << (int)(a < Fixed(1)) + 2 << std::endl;
	return (0);
}