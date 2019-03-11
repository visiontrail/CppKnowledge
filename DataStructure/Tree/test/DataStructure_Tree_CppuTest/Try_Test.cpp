#include "stdafx.h"
#include "CppUTest/TestHarness.h"
#include "../DataStructure_Tree/Tree.h"
#include "CppUTestExt/MockSupport.h"
#include <vector>

TEST_GROUP(FirstTestGroup)
{
};

TEST_GROUP(TreeTestGroup)
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

void productionCode()
{
	mock().actualCall("productionCode");
}

//                                          有根节点，一颗完整的树;
//----------------------------------------------------------------
TEST(TreeTestGroup, TreeFrontRecoursion_Test1)
{
	std::vector<Multi_Tree> TreeList1;
	std::vector<int> Ret;

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

	Ret = Multi_Tree::RecursionTree_Front(&a);

	std::vector<int> CheckRight = { 1,2,6,7,8,3,4,5 };
	CHECK_TEXT(Ret == CheckRight, "Recoursion Tree (Front)");
}