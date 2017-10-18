#include "stdafx.h"
#include "Binary_Tree.h"


int Binary_tree::RecursionTree(Binary_tree *Tree)
{
	if (Tree == nullptr)
	{
		return 0;
	}
	RecursionTree(Tree->LeftTree);
	RecursionTree(Tree->RightTree);

	return Tree->Value;
}