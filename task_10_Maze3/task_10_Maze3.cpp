#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Maze.h"
#include "MCell.h"
#include "MTreeNode.h"

void buildFullMaze(Maze& iMaze, MTreeNode& tre)
{
    for (int i = 0; i < 5; i++)
    {
        MTreeNode& tree = tre;
        if (i != 0)
            tree = *tre.hasChild(i, tre.j());
        if (tree.j() != 5)
        {
            tree.addChild(i, tree.j() + 1);
        }
        for (int j = tree.j() + 1; j < 5; j++)
        {
            tree.hasChild(i, j)->addChild(i, j+1);
        }

        if (tree.j() != 0)
        {
            tree.addChild(i, tree.j() - 1);
        }

        for (int j = tree.j() - 1; j > 0; j--)
        {
            tree.hasChild(i, j)->addChild(i, j - 1);
        }

        if (tree.i() != 4)
        {
            tree.addChild(tree.i() + 1, tree.j());
        }
    }
    MTreeNode& tree = tre;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            auto child = &tree;
            if (!(i == 0 && j == 0) && tree.hasChild(i, j))
                child = tree.hasChild(i, j);
            if (child->parent())
                iMaze.makeConnection(child->parent()->i(), child->parent()->j(), i, j);

            for (int x = 0; x < child->childCount(); x++)
            {
                iMaze.makeConnection(i, j, child->child(x)->i(), child->child(x)->j());
            }
        }
}

int main()
{
    std::srand(std::time(nullptr));
    int random_variable = std::rand();
    int entry = 0;
    //while (entry > 5)
    //    entry = 1 + std::rand() / ((RAND_MAX + 1u) / 5);
    MTreeNode* ptr = MTreeNode::beginTree(0, entry);
    MTreeNode tree = *ptr;
    Maze m = Maze(5, 5);
    buildFullMaze(m, tree);
   


    m.printMaze();
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            auto child = &tree;
            if (!(i == 0 && j == 0) && tree.hasChild(i, j))
                child = tree.hasChild(i, j);
            int d = child->distance();
            std::cout << d;
        }
        std::cout << '\n';
    }

    delete ptr;
}

