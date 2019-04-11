#include "ComplexClass.h"


Complex Complex::operator+=(const Complex& a)
{
	re_ += a.re_;
	im_ += a.im_;
	return *this;
}

Complex Complex::operator-=(const Complex& a)
{
	re_ -= a.re_;
	im_ -= a.im_;
	return *this;
}

Complex& Complex::operator*=(const Complex& a)
{
	double temp_re, temp_im;
	temp_re = (this->re_ * a.re_) - (this->im_ * a.im_);
	temp_im = (this->re_ * a.im_) + (this->im_ * a.re_);
	this->re_ = temp_re;
	this->im_ = temp_im;
	return *this;
}

Complex& Complex::operator/=(const Complex& a)
{
	double temp_re, temp_im;
	temp_re = ((this->re_ * a.re_) + (this->im_ * a.im_)) / (a.re_*a.re_ + a.im_*a.im_);
	temp_im = ((this->im_ * a.re_) - (this->re_ * a.im_)) / (a.re_*a.re_ + a.im_*a.im_);
	this->re_ = temp_re;
	this->im_ = temp_im;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Complex& a)
{
	if (a.im_ > 0 && a.re_ != 0)
		out << a.re_ << " + " << a.im_ << "i";
	if (a.im_ < 0 && a.re_ != 0)
		out << a.re_ << " - " << abs(a.im_) << "i";
	if (a.im_ == 0 && a.re_ != 0)
		out << a.re_;
	if (a.re_ == 0 && a.im_ != 0)
		out << a.im_ << "i";
	if (a.re_ == 0 && a.im_ == 0)
		out << 0;
	return out;
}

std::istream& operator>>(std::istream & in, Complex & a)
{
	std::cout << "Please input real value: ";
	in >> a.re_;
	std::cout << "Please input imaginary value: ";
	in >> a.im_;
	return in;
}