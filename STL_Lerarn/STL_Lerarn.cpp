// STL_Lerarn.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>

#include "STL_Learn.h"

using namespace std;

vector<std::string> SplitStr(std::string inputstr, std::string splitstr)
{
	std::vector<std::string> res;
	inputstr += splitstr;
	if (splitstr.empty())
	{
		return res;
	}
	for ( int i = 0; i < (int)inputstr.size(); ++i )
	{
		int postion = inputstr.find(splitstr, i);
		if (postion < (int)inputstr.size())
		{
			std::string tempstr = inputstr.substr(i, postion - i);
			res.push_back(tempstr);
			i = postion + (splitstr.size() - 1);
		}
		
	}

	return res;
}

int main()
{
	std::string inputstr = "123//324//345/56";
	std::string splitstr = "//";
	std::vector<std::string> res = SplitStr(inputstr, splitstr);
	for (int i = 0; i < (int)res.size(); ++i)
	{
		std::cout << "Split result is " << res[i].c_str() << endl;
	}

	strvec vec1;

	vec1.vectorinit();

	for (vector<std::string>::iterator iter = vec1.strvector.begin(); iter != vec1.strvector.end();++iter)
	{
		std::cout << iter->c_str() << endl;
	}
	
	system("pause");
    return 0;
}

