// STL_Lerarn.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

#include "STL_Learn.h"
#include "Vector_etc.h"
#include "String_l.h"
#include "Sales_data.h"

using namespace std;
using std::string;

int main(int argc, char* args[])
{

	//-----------------vector-----------------------
	// 利用字符串拆分学习了下vector;
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

	// 通过Getline获取用户输入
// 	std::cout << "Input Something:";
// 	BKList.GetUserInput();
	//-----------------string------------------

	//--------------IOStream-------------------

	// 输出流到文件,使用ofstream;
	ofstream fout;
	fout.open("out.txt");

	// 用ofstream的构造函数可以直接传入open函数的参数;
	// 输出模式为app模式(append)的话：在open的时候,不会清除掉被open的文件;
	std::ofstream out("..//data//1.txt", ofstream::app);
	std::ifstream in("..//data//Sales_data.txt");

	if (out.is_open())
	{
		std::cout << "open!" << std::endl;
		out << "print \n";
		out << "print3 \n";
		out.close();
	}
	else
	{
		std::cout << "not open!" << std::endl;
	}

	char buff[265];
	if (in.is_open())
	{
		while (!in.eof())
		{
			in.getline(buff, 100);
			cout << buff << std::endl;
		}
	}
	else
	{
		cout << "open failed!" << endl;
	}
	
	//--------------IOStream-------------------

	system("pause");
    return 0;
}


