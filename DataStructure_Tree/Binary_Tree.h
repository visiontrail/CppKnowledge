#pragma once
#define OK 1

class Binary_tree
{
public:
	int Value;
	Binary_tree *LeftTree;
	Binary_tree *RightTree;

	int RecursionTree(Binary_tree *);
};