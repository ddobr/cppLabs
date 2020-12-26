#ifndef MTREENODE_H
#define MTREENODE_H

class MTreeNode
{
public:
	int i() const
	{
		return m_i;
	}

	int j() const
	{
		return m_j;
	}

	MTreeNode* parent() const
	{
		return m_parent;
	}

	MTreeNode* child(int i) const
	{
		return &m_children[i];
	}

	int distance() const;

	int childCount() const
	{
		return m_childCount;
	}

	bool addChild(int i, int j);

	MTreeNode* hasChild(int i, int j) const;

	static MTreeNode* beginTree(int i, int j);

	~MTreeNode();


private:
	int m_i= 0;
	int m_j= 0;
	MTreeNode* m_parent = nullptr;
	int m_childCount = 0;
	MTreeNode() {}
	MTreeNode* m_children = nullptr;
	int m_distance = 0;
	MTreeNode(MTreeNode* parent)
	{
		m_parent = parent;
	}
};

#endif // !MTREENODE_H
