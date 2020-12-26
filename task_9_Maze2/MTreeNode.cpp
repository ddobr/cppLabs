#include "MTreeNode.h"

int MTreeNode::distance() const
{
	auto a = parent();
	if (a != nullptr)
		return a->distance() + 1;
	return 0;
}


bool MTreeNode::addChild(int i, int j)
{
	if (m_childCount == 0)
		m_children = new MTreeNode[2];
	if (m_childCount == 2)
		return false;
	if (i != m_i && j != m_j)
		return false;
	if (m_childCount == 1)
	{
		if (child(0)->m_i == i || child(0)->m_j == j)
			return false;
	}
	if (i < m_i || j < m_j)
		return false;
	auto child = MTreeNode(this);
	child.m_i = i;
	child.m_j = j;
	m_children[m_childCount++] = child;
}

MTreeNode* MTreeNode::hasChild(int i, int j) const
{
	for (int x = 0; x < m_childCount; x++)
	{
		if (child(x)->m_i == i && child(x)->m_j == j)
			return child(x);
		else if (child(x)->m_childCount != 0)
		{
			auto foundChild = child(x)->hasChild(i, j);
			if (foundChild != nullptr)
				return foundChild;
		}
	}
	return nullptr;
}

MTreeNode* MTreeNode::beginTree(int i, int j)
{
	auto tree = new MTreeNode();
	tree->m_i = i;
	tree->m_j = j;
	return tree;
}

MTreeNode::~MTreeNode()
{
	delete[] m_children;
}
