#include "SLList.h"

SLList::SLList(int data)
{
	m_data = new int(data);
}

int SLList::getData() const
{
	return *m_data;
}

SLList* SLList::addElement(int data)
{
	if (!m_nextElem)
	{
		m_nextElem = new SLList(data);
		return m_nextElem;
	}

	SLList *next = m_nextElem->addElement(data);
	return next;
}

SLList* SLList::beginList(int data)
{
	return new SLList(data);
}

void SLList::setData(int data)
{
	delete m_data;
	m_data = new int(data);
}

SLList* SLList::next() const
{
	return m_nextElem;
}

bool SLList::hasNext() const
{
	if (m_nextElem)
		return true;
	return false;
}

void SLList::removeNext()
{
	SLList* secondNext = m_nextElem->next();
	m_nextElem = secondNext;
}

SLList::~SLList()
{
	delete m_nextElem;
	delete m_data;
}
