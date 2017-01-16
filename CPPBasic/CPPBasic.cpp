// CPPBasic.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	// 两个变量，一个初始化，一个没有初始化
	int i2;
	int init1 = 11;

	//int i = 1, &r = 0;                     //错误，引用r不能使用常量
	int &PTr2 = i2;                          //正确，普通的引用只能引用变量
	int *const p2 = &i2;                     //正确，一种const指针的声明方式
	const int i = -1, &r2 = 0;               //正确，普通const常量和常量的引用可以使用常量
	const int *const p3 = &i2;               //正确，有两个const的常量指针
	const int *p4 = &init1;                  //正确，正常声明的常量指针
	const int &r3 = i2;                      //正确，一个const引用
	const int i3 = i2, &r4 = i;				 //错误，常量i3使用变量初始化，编译没有问题，如果对应的变量没有被初始化，可能造成异常

	std::cout << "const引用可以引用常量(普通引用只能引用变量)" << r2 << "\n" << std::endl;
	std::cout << "const引用,引用的没有初始化的变量：" << r3 << "\n" << std::endl;
	std::cout << "const指针指向了一个没有初始化的变量：" << *p3 << "\n" << std::endl;

	PTr2 = 222;
	std::cout << "const引用,引用没初始化的变量被赋值：" << r3 << "\n" << std::endl;
	std::cout << "const指针指向了一个被初始化的变量：" << *p4 << "\n" << std::endl;
	std::cout << "const指针内存地址指向的没有初始化的值被赋值了：" << *p3 << "\n" << std::endl;

	init1 = 12;
	std::cout << "const指针内存地址指向的初始化的值被改变了：" << *p4 << "\n" << std::endl;

	std::cout << "普通const常量在赋值的时候被赋值了一个没有初始化的变量" << i3 << "\n" << std::endl;
	std::cout << "那个变量如何改变，那const常量也不会变，那个变量的值是：" << i2 << "\n" << std::endl;

	std::system("pause");

    return 0;
}

