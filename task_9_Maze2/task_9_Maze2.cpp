#include <iostream>
#include "MTreeNode.h"

int main()
{
    MTreeNode treeh = *MTreeNode::beginTree(0, 0);
    MTreeNode* tree = &treeh;
    tree->addChild(4, 0);
    tree->addChild(0, 1);
    MTreeNode* ch = tree->child(1);
    ch->addChild(0, 4);
    ch->addChild(1, 1);
    ch = ch->child(1);
    ch->addChild(4, 1);
    ch->addChild(1, 2);
    ch = ch->child(1);
    ch->addChild(1, 4);
    ch->addChild(2, 2);
    ch = ch->child(1);
    ch->addChild(4, 2);
    ch->addChild(2, 3);
    ch = ch->child(1);
    ch->addChild(2, 4);
    ch->addChild(3, 3);
    ch = ch->child(1);
    ch->addChild(4, 3);
    ch->addChild(3, 4);
    tree->printMaze();
}
