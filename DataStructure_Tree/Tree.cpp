#include "stdafx.h"
#include "Tree.h"

void Multi_Tree::RecursionTree(Multi_Tree *tree)
{
	if (tree != nullptr)
	{
		std::cout << tree->m_value << " ";
		if (tree->m_Children.size() != 0)
		{
			for (auto children : tree->m_Children)
			{
				RecursionTree(children);
			}
		}

	}
}