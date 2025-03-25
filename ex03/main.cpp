#include <iostream>
#include "Fixed.h"
#include "Point.h"
#include "colors.h"

int main( void )
{
	Point a(0, 0);
	Point b(20, 0);
	Point c(0, 6);



	Point d(0, 3);

	std::cout << bsp(a, b, c, d) << std::endl;

	drawTriangle(a, b, c, RED);
	return 0;
}
