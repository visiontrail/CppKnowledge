#pragma once
#include "stdafx.h"
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <stack>


using std::vector;
using std::list;
using std::string;


struct GenericContainer
{
	vector<string> StringVector;
	vector<int> IntVector;
	list<string> StringList;
	list<int> IntList;
};
