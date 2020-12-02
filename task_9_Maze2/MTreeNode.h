#ifndef MTREENODE_H
#define MTREENODE_H

#include <windows.h>
#include <iostream>


class MTreeNode
{
public:
	int i() const;

	int j() const;

	MTreeNode* parent() const;

	MTreeNode* child(int i) const;

	int distance() const;

	int childCount() const;

	bool addChild(int i, int j);

	MTreeNode* hasChild(int i, int j);

	static MTreeNode* beginTree(int i, int j);

	~MTreeNode();

	static void setCoord(int i, int j);


private:
	int m_i= 0;
	int m_j= 0;
	MTreeNode* m_parent = nullptr;
	int m_childCount = 0;
	MTreeNode* m_children = nullptr;
	int m_distance = 0;
	MTreeNode(MTreeNode* parent);
	MTreeNode(MTreeNode* parent, int i, int j);
	MTreeNode(int i, int j);
	MTreeNode();
};

#endif // !MTREENODE_H



