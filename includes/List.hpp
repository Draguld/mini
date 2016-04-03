#ifndef		LIST_HPP
#define		LIST_HPP

#include "std.hpp"
#include "Element.hpp"

class		List
{
	public:
	List();
	List(Element *data);
	
	void					insert(List *node);
	void					addEnd(List *node);
	void					addBegin(List *node);
	List					*remove();
	void					clear();

	void					setData(Element *data);
	void					setNext(List *next);
	void					setPrevious(List *previous);
	void					setIsAlive(bool alive);

	unsigned int			getSize();
	List					*getFirst();
	List					*getLast();
	List					*getNext()const;
	List					*getPrevious()const;
	List					*getCurrent()const;
	Element					*getData()const;
	bool					getIsAlive()const;

	List				*removeUsed();

	private:

	Element					*m_data;
	List					*m_next;
	List					*m_previous;
	bool					m_isAlive;
};

#endif
