// STL_Lerarn.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

#include "STL_Learn.h"
#include "Vector_etc.h"
#include "String_l.h"


using namespace std;

int main()
{

	//-----------------vector-----------------------
	//利用字符串拆分学习了下vector;
	std::string inputstr = "123//324//345/56";
	std::string splitstr = "//";
	std::vector<std::string> res = SplitStr(inputstr, splitstr);
	for (int i = 0; i < (int)res.size(); ++i)
	{
		std::cout << "Split result is " << res[i].c_str() << endl;
	}

	strvec vec1;

	// vector中使用迭代器进行迭代;
	vec1.vectorinit();
	for (vector<std::string>::iterator iter = vec1.strvector.begin(); iter != vec1.strvector.end();++iter)
	{
		std::cout << "使用iterator迭代;" << iter->c_str() << endl;
	}
	for (auto c : vec1.strvector)
	{
		std::cout << "新的迭代方法;" << c.c_str() << endl;
	}
	//-----------------vector-----------------------


	// ----------------string------------------
	// 使用string中字典排序对string内容进行比较;
	Bookinfo BKList;
	auto Booklist = BKList.Strinit();
	if (Booklist[1] > Booklist[2])
	{
		std::cout << "11" << std::endl;
	}
	std::cout << "Input Something:";
	BKList.GetUserInput();
	//-----------------string------------------


	system("pause");
    return 0;
}

