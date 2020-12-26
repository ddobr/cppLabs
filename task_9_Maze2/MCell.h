#ifndef MCELL_H
#define MCELL_H

class MCell
{
	friend class Maze;
public:
	bool right() const
	{
		return m_right;
	}

	bool down() const
	{
		return m_down;
	}

	short codePaths(bool hasLeft, bool hasTop) const
	{
		return hasTop * 1000 + m_right * 100 + m_down * 10 + hasLeft;
	}
private:
	bool m_right = false;
	bool m_down = false;
	MCell()
	{}
};

#endif // !MCELL_H
