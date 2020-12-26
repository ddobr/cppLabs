#include "Maze.h"

Maze::Maze(int n, int m)
{
	this->m = m;
	this->n = n;
	m_field = new MCell[n * m];
}

const MCell& Maze::cell(int i, int j) const
{
	return m_field[i * n + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	int first = std::min(n * i1 + j1, n * i2 + j2);
	int second = std::max(n * i1 + j1, n * i2 + j2);

	if (!(first + 1 == second || first + n == second))
		return false;

	else if (first + 1 == second)
		return m_field[first].right();

	return m_field[first].down();
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	int first = std::min(n * i1 + j1, n * i2 + j2);
	int second = std::max(n * i1 + j1, n * i2 + j2);

	if (!(first + 1 == second || first + n == second))
		return false;

	else if (first + 1 == second)
	{
		m_field[first].m_right = true;
		return true;
	}

	m_field[first].m_down = true;
	return true;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	int first = std::min(n * i1 + j1, n * i2 + j2);
	int second = std::max(n * i1 + j1, n * i2 + j2);

	if (!(first + 1 == second || first + n == second))
		return false;

	else if (first + 1 == second)
	{
		m_field[first].m_right = false;
		return true;
	}

	m_field[first].m_down = false;
	return true;
}

void Maze::printMaze()
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << findChar(m_field[i * n + j].codePaths(hasConnection(i, j - 1, i, j), hasConnection(i - 1, j, i, j)));
		}
		std::cout << std::endl;
	}
}

char Maze::findChar(short code)
{
	switch (code)
	{
	case 0: return 248;
	case 1: return 196;
	case 10: return 179;
	case 11: return 191;
	case 100: return 196;
	case 101: return 196;
	case 110: return 218;
	case 111: return 194;
	case 1000: return 179;
	case 1001: return 217;
	case 1010: return 179;
	case 1011: return 180;
	case 1100: return 192;
	case 1101: return 193;
	case 1110: return 195;
	case 1111: return 197;
	}

	return -1;
}

Maze::~Maze()
{
	delete[] m_field;
}
