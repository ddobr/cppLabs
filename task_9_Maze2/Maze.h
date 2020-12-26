#ifndef MAZE_H
#define MAZE_H

#include "MCell.h"
#include <iostream>
#include <algorithm>

class Maze
{
public:
	Maze(int n, int m);

	const MCell& cell(int i, int j) const;

	bool hasConnection(int i1, int j1, int i2, int j2);

	bool makeConnection(int i1, int j1, int i2, int j2);

	bool removeConnection(int i1, int j1, int i2, int j2);

	void printMaze();

	char findChar(short code);

	~Maze();

private:
	MCell* m_field;
	int n = 0;
	int m = 0;

};

#endif
