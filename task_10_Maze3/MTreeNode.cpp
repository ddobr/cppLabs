#include "MTreeNode.h"


MTreeNode::MTreeNode(MTreeNode* parent)
{
	m_parent = parent;
}

MTreeNode::MTreeNode() {}

MTreeNode::MTreeNode(int i, int j)
{
	m_i = i;
	m_j = j;
}

MTreeNode::MTreeNode(MTreeNode* parent, int i, int j)
{
	m_parent = parent;
	m_i = i;
	m_j = j;
	m_distance = parent->m_distance + 1;
}

int MTreeNode::i() const
{
	return m_i;
}

int MTreeNode::j() const
{
	return m_j;
}

MTreeNode* MTreeNode::parent() const
{
	return m_parent;
}

MTreeNode* MTreeNode::child(int i) const
{
	return &m_children[i];
}

int MTreeNode::distance() const
{
	return m_distance;
}

int MTreeNode::childCount() const
{
	return m_childCount;
}

bool MTreeNode::addChild(int i, int j)
{
	if (m_childCount == 0)
		m_children = new MTreeNode[4];
	if (m_childCount == 4)
		return false;
	if (i != m_i && j != m_j)
		return false;
	if (m_childCount != 0)
	{
		for (int x = 0; x < m_childCount; x++)
		{
			if ((child(x)->m_i == i && max(m_j, child(x)->m_j) >= j && min(m_j, child(x)->m_j) <= j)
				|| (child(x)->m_j == j && max(m_i, child(x)->m_i) >= i && min(m_i, child(x)->m_i) <= i))
				return false;
		}
	}

	m_children[m_childCount++] = MTreeNode(this, i, j);
}

MTreeNode* MTreeNode::hasChild(int i, int j)
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
	return new MTreeNode(i, j);
}

MTreeNode::~MTreeNode()
{
	delete[] m_children;
}


void MTreeNode::setCoord(int i, int j)
{
	COORD coord;
	coord.Y = i;
	coord.X = j;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
