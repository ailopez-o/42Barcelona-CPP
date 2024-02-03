#include <iostream>
#include "FixedPointNumber.hpp"

int main( void ) {
	FixedPointNumber a;
	FixedPointNumber b( a );
	FixedPointNumber c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}