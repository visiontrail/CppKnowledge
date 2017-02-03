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

vector<Bookinfo> Bookinfo::Strinit()
{
	std::vector<Bookinfo> BKinfo;

	BKinfo.push_back(Bookinfo("Book1", 110001, 100));
	BKinfo.push_back(Bookinfo("Book3", 110003, 300));
	BKinfo.push_back(Bookinfo("Book2", 110003, 50));

	return BKinfo;
}