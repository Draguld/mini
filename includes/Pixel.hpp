#ifndef		PIXEL_HPP
#define		PIXEL_HPP

class	Pixel
{
	public:
	
	Pixel();
	Pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	Pixel(unsigned char r, unsigned char g, unsigned char b);
	Pixel( Pixel const & rhs);
	~Pixel();
	Pixel &	operator = ( Pixel const & rhs);

	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
};
	bool	operator == (Pixel const& a, Pixel const& b);
	bool	operator != (Pixel const& a, Pixel const& b);

#endif
