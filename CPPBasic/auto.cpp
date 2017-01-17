#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 使用auto关键字直接判断其等号后边表达式的类型;
// 作用1：可以缩短冗长的代码编写;
void autoUsing_JudgeType()
{
	std::map<int, std::map<int, int>> map1;
	std::map<int, int> map1Value;

	map1Value.insert(std::make_pair(1, 1));
	map1.insert(std::make_pair(1, map1Value));
	map1.insert(std::make_pair(2, map1Value));

	// 使用迭代器迭代map1的方法为：
	std::map<int, std::map<int, int>>::iterator iter = map1.begin();
	for (; iter != map1.end(); ++iter)
	{
		std::cout << "复杂写法迭代;" << iter->first << std::endl;
	}

	// 使用auto关键字让编译器直接判断表达式的返回类型;
	auto iter2 = map1.begin();
	for (; iter2 != map1.end(); ++iter2)
	{
		std::cout << "auto变量迭代;" << iter2->first << std::endl;
	}

	return;
}

// 使用模板技术时，如果某个变量的类型依赖于模板参数;
// 不使用auto将很难确定变量的类型（使用auto后，将由编译器自动进行确定）
template <class T, class U>
void UseAutoMultiply(T t, U u)
{
	auto v = t * u;
}

template <typename T1, typename T2>
auto compose(T1 t1, T2 t2) -> decltype(t1 + t2)
{
	return t1 + t2;
}
auto v = compose(2, 3.14); // v's type is double;