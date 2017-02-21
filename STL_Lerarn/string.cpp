/*
本文件学习的主要内容有;
1、string的基本用法
2、stream的基本用法
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

#include "String_l.h"

using namespace std;
using std::string;

// 初始化数据以便实验;
vector<Bookinfo> Bookinfo::Strinit()
{
	std::vector<Bookinfo> BKinfo;

	BKinfo.push_back(Bookinfo("Book1", 110001, 100));
	BKinfo.push_back(Bookinfo("Book3", 110003, 300));
	BKinfo.push_back(Bookinfo("Book2", 110003, 50));

	return BKinfo;
}

// 使用getline获取用户输入;
void Bookinfo::GetUserInput()
{
	string line;
	string::size_type len;

	while (getline(std::cin, line))
	{
		for (auto &c : line)
		{
			c = toupper(c);
		}

		std::cout << line << std::endl;
		len = line.size();
		auto len2 = line.size();
		// 从“size_t”转换到“int”，可能丢失数据;
		//int len3 = line.size();
		std::cout << "输入的字符长度为;" << len2 << std::endl;

		return;
	}

	return;
}