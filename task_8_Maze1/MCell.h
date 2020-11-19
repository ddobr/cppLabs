#ifndef MCELL_H
#define MCELL_H

class MCell
{
	friend class Maze;
private:
	bool m_top = false;
	bool m_right = false;
	bool m_down = false;	
	bool m_left = false;
	MCell();
public:
	bool right();

	bool down();

	short codePaths();
};

#endif // !MCELL_H