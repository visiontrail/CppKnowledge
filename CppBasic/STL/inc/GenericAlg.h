#pragma once
#include "stdafx.h"
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <stack>
#include <string>

using std::list;
using std::string;
using std::vector;

struct GenericContainer
{
	vector<string> StringVector;
	vector<int> IntVector;
	list<string> StringList;
	list<int> IntList;
};
