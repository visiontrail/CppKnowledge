#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
class Multi_Tree
{

public:
	Multi_Tree(int val, Multi_Tree *parent) 
		: m_value(val), m_Parent(parent)
	{
	}

public:
	int m_value;
	Multi_Tree *m_Parent;
	std::vector<Multi_Tree*> m_Children;

	// Ç°Ðò±éÀú;
	static std::vector<int> RecursionTree_Front(Multi_Tree*);
};

class Tree_Container
{
public:
	static std::vector<int> Tree;
protected:
private:
};