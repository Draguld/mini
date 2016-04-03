#include "Pixel.hpp"

Pixel::Pixel():
r(255),
g(255),
b(255),
a(255)
{
		
}

Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a):
r(r),
g(g),
b(b),
a(a)
{
		
}

Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b):
r(r),
g(g),
b(b),
a(255)
{
		
}


Pixel::Pixel( Pixel const & rhs)
{
	*this = rhs;		
}

Pixel::~Pixel()
{
		
}

Pixel & Pixel::operator=( Pixel const & rhs )
{
	this->r = rhs.r;
	this->g = rhs.g;
	this->b = rhs.b;
	this->a = rhs.a;
	return *this;		
}

bool	operator==( Pixel const& a, Pixel const& b)
{
	return (a.r == b.r) && (a.g == b.g) && (a.b == b.b) && (a.a == b.a);
}

bool	operator!=( Pixel const& a, Pixel const& b)
{
	return !(a == b);
}
