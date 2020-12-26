#include <iostream>
#include "Maze.h"
#include "MCell.h"
#include "MTreeNode.h"

int main()
{
    MTreeNode* ptr = MTreeNode::beginTree(0, 0);
    MTreeNode tree = *ptr;
    tree.addChild(1, 0);
    tree.addChild(0, 1);

    for (int c = 1; c < 5; c++)
    {
        if (c != 1)
        {
            tree.hasChild(c - 1, c - 1)->addChild(c, c - 1);
            tree.hasChild(c - 1, c - 1)->addChild(c-1, c);
        }
        for (int i_x = c; i_x < 5; i_x++)
        {
            tree.hasChild(i_x, c - 1)->addChild(i_x + 1, c - 1);
        }

        for (int j_x = c; j_x < 5; j_x++)
        {
            tree.hasChild(c - 1, j_x)->addChild(c- 1, j_x + 1);
        }
        tree.hasChild(c - 1, c)->addChild(c, c);

    }
    
    Maze m = Maze(5, 5);
    for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
    {
        auto child = &tree;
        if (!(i == 0 && j == 0) && tree.hasChild(i, j))
            child = tree.hasChild(i, j);
        if (child->parent())
            m.makeConnection(child->parent()->i(), child->parent()->j(), i, j);

        for (int x = 0; x < child->childCount(); x++)
        {
            m.makeConnection(i, j, child->child(x)->i(), child->child(x)->j());
        }
    }

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
}
