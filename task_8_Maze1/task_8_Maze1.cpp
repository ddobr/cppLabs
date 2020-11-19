#include <iostream>
#include "MCell.h"
#include "Maze.h"


int main()
{
    std::cout << "Hello World!\n";

    Maze m = Maze(5, 5);
    m.makeConnection(0, 1, 1, 1);
    m.makeConnection(1, 1, 1, 2);
    m.makeConnection(1, 2, 2, 2);
    m.makeConnection(2, 2, 2, 3);
    m.makeConnection(2, 3, 3, 3);
    m.makeConnection(3, 3, 3, 4);
    m.makeConnection(3, 4, 4, 4);

    m.printMaze();

}
