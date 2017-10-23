#include "stdafx.h"
#include "CppUTest/TestHarness.h"
#include "../DataStructure_Tree/Tree.h"
#include <vector>

TEST_GROUP(FirstTestGroup)
{
};

TEST_GROUP(FooTestGroup)
{
	void setup()
	{
		// Init stuff
	}

	void teardown()
	{
		// Uninit stuff
	}
};

TEST(FirstTestGroup, FirstTest)
{
	std::vector<Multi_Tree> TreeList1;
	Multi_Tree a(1, nullptr);
	Multi_Tree b(2, &a);
	Multi_Tree c(3, &a);
	Multi_Tree d(4, &a);
	Multi_Tree e(5, &a);
	std::vector<Multi_Tree*> a_Children = { &b, &c, &d, &e };
	a.m_Children = a_Children;
	Multi_Tree f(6, &b);
	Multi_Tree g(7, &b);
	Multi_Tree h(8, &b);
	std::vector<Multi_Tree*> b_Children = { &f, &g, &h };
	b.m_Children = b_Children;

	Multi_Tree::RecursionTree(&a);
}