// ComplexNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ComplexClass.h"

int main()
{
	Complex a{ 3.0, 2.0 }, b{ 3.0, -5.0 };
	a /= b;
	cout << a << "\n";
	cout << b << "\n";
}
