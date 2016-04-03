#include "Element.hpp"

Element::Element():
m_type(0)
{
		
}

Element::Element(int type):
m_type(type)
{
		
}

Element::Element(Element const & rhs)
{
	*this = rhs;
}

Element & Element::operator=(Element const & rhs)
{
	this->m_type = rhs.getType();		
	return (*this);
}

Element::~Element()
{
		
}

void		Element::setType(int type)
{
	this->m_type = type;		
}

int			Element::getType()const
{
	return(this->m_type);		
}
