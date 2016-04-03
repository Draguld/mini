#include "List.hpp"

List::List():
m_data(NULL),
m_next(NULL),
m_previous(NULL),
m_isAlive(true)
{
		
}

List::List(Element *data):
m_data(data),
m_next(NULL),
m_previous(NULL),
m_isAlive(true)
{
		
}

void			List::insert(List *node)
{
	node->setNext(this->getNext());
	this->setNext(node);
	node->setPrevious(this);
	node->getNext()->setPrevious(node);
}

void			List::addEnd(List *node)
{
	List	*cur;

	cur = this;
	while (cur->getNext() != NULL)
	{
		cur = cur->getNext();
	}
	cur->setNext(node);
	node->setNext(NULL);
	node->setPrevious(cur);
}

void			List::addBegin(List *node)
{
	List	*cur;

	cur = this;
	while (cur->getPrevious() != NULL)
	{
		cur = cur->getPrevious();
	}
	cur->setPrevious(node);
	node->setNext(cur);
	node->setPrevious(NULL);
}

List			*List::remove()
{
	List		*cur;
	List		*ret;

	cur = this;
	ret = NULL;
	if (this->getData() != NULL)
	{
		delete this->getData();
		this->setData(NULL);
	}
	if (this->getNext() != NULL && this->getPrevious() != NULL)
	{
		this->getNext()->setPrevious(this->getPrevious());
		this->getPrevious()->setNext(this->getNext());
		ret = this->getNext();
	}
	else if (this->getPrevious() != NULL)
	{
		this->getPrevious()->setNext(NULL);
		ret = this->getPrevious();
	}
	else if (this->getNext() != NULL)
	{
		this->getNext()->setPrevious(NULL);
		ret = this->getNext();
	}
	cur->setPrevious(NULL);
	cur->setNext(NULL);
	delete cur;
	cur = NULL;
	return(ret);
}

void			List::clear()
{	
	List	*cur = this;
	while (cur != NULL)
		cur = cur->remove();
}

void			List::setData(Element *data)
{
	this->m_data = data;
}

void			List::setNext(List *next)
{
	this->m_next = next;
}

void			List::setPrevious(List *previous)
{
	this->m_previous = previous;		
}

void			List::setIsAlive(bool alive)
{
	this->m_isAlive = alive;	
}

unsigned int	List::getSize()
{
	unsigned int	 size;
	List			*cur;
	
	size = 0;
	cur = this;

	while (cur->getPrevious() != NULL)
		cur = cur->getPrevious();
	while (cur->getNext() != 0)
	{
		cur = cur->getNext();
		size++;
	}
	return (size + 1);
}

List			*List::getFirst()
{
	List	*cur;

	cur = this;
	while (cur->getPrevious() != NULL)
		cur = cur->getPrevious();
	return (cur);
}

List			*List::getLast()
{
	List	*cur;

	cur = this;
	while (cur->getNext() != NULL)
		cur = cur->getNext();
	return (cur);
}

List			*List::getNext()const
{
	return (this->m_next);
}

List			*List::getPrevious()const
{
	return (this->m_previous);		
}

List			*List::getCurrent()const
{
	return ((List*)(this));		
}

Element		*List::getData()const
{
	return (this->m_data);		
}

bool		List::getIsAlive()const
{
	return (this->m_isAlive);		
}
