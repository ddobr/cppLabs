#include "MTreeNode.h"


MTreeNode::MTreeNode(MTreeNode* parent)
{
	m_parent = parent;
}
MTreeNode::MTreeNode() {}

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
		m_children = new MTreeNode[2];
	if (m_childCount == 2)
		return false;
	if (i != m_i && j != m_j)
		return false;
	if (m_childCount == 1)
	{
		MTreeNode ch = *child(0);
		if (ch.m_i == i || ch.m_j == j)
			return false;
	}
	if (i < m_i || j < m_j)
		return false;
	MTreeNode newChild = MTreeNode(this);
	newChild.m_i = i; newChild.m_j = j;
	newChild.m_distance = (i - m_i) + (j - m_j);
	m_children[m_childCount++] = newChild;
}

MTreeNode* MTreeNode::hasChild(int i, int j)
{
	for (int x = 0; x < m_childCount; x++)
	{
		if ((*child(x)).m_i == i && (*child(x)).m_j == j)
			return child(x);
	}
	return nullptr;
}

MTreeNode* MTreeNode::beginTree(int i, int j)
{
	MTreeNode newNode = MTreeNode();
	newNode.m_i = i; newNode.m_j = j;
	newNode.m_children = new MTreeNode[2];
	return &newNode;
}

MTreeNode::~MTreeNode()
{
	if (m_children && m_childCount != 0)
		delete[] m_children;
}

void MTreeNode::printMaze()
{
	setCoord(m_i, m_j);
	if (m_parent == nullptr || m_childCount == 0)
		std::cout << '0';
	else std::cout << findChar();
	for (int x = 0; x < m_childCount; x++)
	{
		setCoord(m_i, m_j);
		MTreeNode current = m_children[x];;
		char type = (current).m_i != m_i ? 'v' : 'h';
		for (int rem = 1; rem < current.m_distance; rem++)
		{
			if (type == 'h')
			{
				setCoord(m_i, m_j + rem);
				std::cout << char(196);
			}
			else
			{
				setCoord(m_i + rem, m_j);
				std::cout << char(179);
			}
		}
		current.printMaze();
	}
}

void MTreeNode::setCoord(int i, int j)
{
	COORD coord;
	coord.Y = i;
	coord.X = j;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int MTreeNode::getCode()
{
	int res = 0;
	if (m_parent != nullptr && (*m_parent).m_i < m_i)
		res += 1000;
	else res += 1;

	for (int x = 0; x < m_childCount; x++)
	{
		res += (m_children[x]).m_i > m_i ? 10 : 0;
		res += (m_children[x]).m_j > m_j ? 100 : 0;
	}

	return  res;
}

char MTreeNode::findChar()
{
	switch (getCode())
	{
	case 0: return 248;
	case 1: return 196;
	case 10: return 179;
	case 11: return 191;
	case 100: return 196;
	case 101: return 196;
	case 110: return 218;
	case 111: return 194;
	case 1000: return 179;
	case 1001: return 217;
	case 1010: return 179;
	case 1011: return 180;
	case 1100: return 192;
	case 1101: return 193;
	case 1110: return 195;
	case 1111: return 197;
	}

	return -1;
}





