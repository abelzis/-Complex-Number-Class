#pragma once

#include <iostream>
using std::cout;

class Complex
{
private:
	double re_, im_;
public:
	Complex() : re_(0), im_(0) {}
	Complex(const double& a) : re_(a), im_(0) {}
	Complex(const double& a, const double& b) : re_(a), im_(b) {}

	//adition operators
	Complex operator+=(const Complex& a);
	inline friend Complex operator+(Complex a, const Complex& b) { return a += b; }

	//subtraction operators
	Complex operator-=(const Complex& a);
	inline friend Complex operator-(Complex a, const Complex& b) { return a -= b; }

	//multiplication operators
	Complex& operator*=(const Complex& a);
	inline friend Complex operator*(Complex a, const Complex& b) { return a *= b; }

	//division operators
	Complex& operator/=(const Complex& a);
	inline friend Complex operator/(Complex a, const Complex& b) { return a /= b; }

	//sign operators
	inline Complex operator-() { return { -this->re_, -this->im_ }; }
	inline Complex operator+() { return { this->re_, this->im_ }; }
	
	//stream operators
	friend std::ostream& operator<<(std::ostream & out, const Complex & a);
	friend std::istream& operator>>(std::istream & in, Complex & a);

	//boolean operators
	inline friend bool operator==(const Complex& a, const Complex& b) { return a.re_ == b.re_ && a.im_ == b.im_; }
	inline friend bool operator!=(const Complex& a, const Complex& b) { return !(a == b); }


	//std::ostream& operator<<(const Complex& a);
};

