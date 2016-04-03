#ifndef		ELEMENT_HPP
#define		ELEMENT_HPP

class		Element
{
	public:
	Element();
	Element(int type);
	Element(Element const & rhs);
	Element & operator =(Element const & rhs);
	~Element();

	enum	Type
	{
		None = 0		
	};

	void			setType(int type);
	int				getType()const;

	protected:
	int				m_type;		
};

#endif
