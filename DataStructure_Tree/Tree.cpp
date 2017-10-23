#include "stdafx.h"
#include "Tree.h"

std::vector<int> g_Ret;

std::vector<int> Multi_Tree::RecursionTree(Multi_Tree *tree)
{
	if (tree != nullptr)
	{
		std::cout << tree->m_value << " ";
		g_Ret.push_back(tree->m_value);
		if (tree->m_Children.size() != 0)
		{
			for (auto children : tree->m_Children)
			{
				RecursionTree(children);
			}
		}
	}

	return g_Ret;
}