#include <iostream>
#include "FixedPointNumber.hpp"

int main( void ) {
	FixedPointNumber a;
	FixedPointNumber const b( FixedPointNumber( 5.05f ) * FixedPointNumber( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << FixedPointNumber::max( a, b ) << std::endl;
	return 0;
}