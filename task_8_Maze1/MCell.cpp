#include "MCell.h"

MCell::MCell()
{}

bool MCell::right()
{
	return m_right;
}

bool MCell::down()
{
	return m_down;
}

short MCell::codePaths()
{
	return  m_top * 1000 + m_right * 100 + m_down * 10 + m_left;
}