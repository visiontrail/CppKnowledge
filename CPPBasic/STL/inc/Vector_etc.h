#pragma once

#include <string>
using namespace std;

// ²ð·Ö×Ö·û´®;
vector<std::string> SplitStr(std::string inputstr, std::string splitstr);
bool SortFater50(const int &para1, const int &para2);

#include "Sales_data.h"

class strvec
{
public:
	strvec() = default;
	void vectorinit();
	std::vector<std::string> strvector;
	std::vector<Sales_data> vecSalesData;
	std::vector<int> vecint;
};
