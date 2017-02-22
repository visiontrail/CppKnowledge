#include "stdafx.h"
#include <iostream>

using namespace std;

typedef unsigned int u32;
using s32 = int;

/*
* const常量的各种定义、初始化版本;
* 普通const常量;
* const引用;
* const指针;
*/
void ConstDefineInitPrint()
{
	// 两个变量，一个初始化，一个没有初始化;
	int i2;
	int init1 = 11;

	//int i = 1, &r = 0;                     //错误，引用r不能使用常量
	int &PTr2 = i2;                          //正确，普通的引用只能引用变量;
	int *const p2 = &i2;                     //正确，一种const指针的声明方式;
	const int i = -1, &r2 = 0;               //正确，普通const常量和常量的引用可以使用常量;
	const int *const p3 = &i2;               //正确，有两个const的常量指针;
	const int *p4 = &init1;                  //错误(编译不会出错)，对于p4来说，是一个普通指针，但对于*p4来说，它是一个常量;
	const int &r3 = i2;                      //正确，一个const引用;
	const int i3 = i2, &r4 = i;				 //错误，常量i3使用变量初始化，编译没有问题，如果对应的变量没有被初始化，可能造成异常

	std::cout << "const引用可以引用常量(普通引用只能引用变量);" << r2 << "\n" << std::endl;
	std::cout << "const引用,引用的没有初始化的变量;" << r3 << "\n" << std::endl;
	std::cout << "const指针指向了一个没有初始化的变量;" << *p3 << "\n" << std::endl;

	PTr2 = 222;
	std::cout << "const引用,引用没初始化的变量被赋值;" << r3 << "\n" << std::endl;
	std::cout << "const指针指向了一个被初始化的变量;" << *p4 << "\n" << std::endl;
	std::cout << "const指针内存地址指向的没有初始化的值被赋值了;" << *p3 << "\n" << std::endl;

	//p3 = &init1;                           //导致错误的编译,因为指针P3是一个常量;

	init1 = 12;
	std::cout << "const指针内存地址指向的初始化的值被改变了;" << *p4 << "\n" << std::endl;
	std::cout << "const *p4这样声明的指针，是否会被改变存放的内存地址,没改变之前的内存地址;" << p4 << "\n" << std::endl;
	p4 = &i2;
	std::cout << "const *p4这样声明的指针，是否会被改变存放的内存地址？" << p4 << "\n" << std::endl;

	std::cout << "普通const常量在赋值的时候被赋值了一个没有初始化的变量;" << i3 << "\n" << std::endl;
	std::cout << "那个变量如何改变，那const常量也不会变，那个变量的值是;" << i2 << "\n" << std::endl;

	return;
}

/*
const常量定义;
*/
void ConstDefinePrint()
{
	int i2 = 30;
	int i, const *cp;              //合法(但不知道是干什么的)，cp不是const指针，*cp也不是一个const类型……;
	//int *p1,*const p2;           //错误，p1是int指针，正确，但是p2是const指针，需要初始化;
	//int *const cp2;              //错误，cp2是const*类型的，是const常量，必须初始化;
	//const int ic,&r = ic;        //错误，ic是const类型，是cosnt常量，必须初始化;后边的r本身没有问题，但是ic没有初始化
	//const int *const p3;         //错误，p3是一个const常量，必须初始化;
	const int *p;                  //合法(编译能通过),p是int指针而不是const类型，*p是const类型
	//constexpr int i = i2;        //constexpr变量，编译器一定会检查，赋给其值必须是一个常量表达式;

	i = 10;
	//cp到底是什么?;
	//cp是一个指针类型，但是并不是const指针常量;
	cp = &i;
	std::cout << "cp value is:" << *cp << ",cp address is " << cp << "\n" << std::endl;
	cp = &i2;
	std::cout << "change cp pointer,cp value is" << *cp << ",cp address is " << cp << "\n" << std::endl;
	*cp = 10;
	std::cout << "cp value is" << *cp << "\n" << std::endl;

	return;
}

/*
下面代码是否合法？如果非法，修改之;

int null = 0, *p = null;
错误，null是int类型，不能绑定到p这个指针类型;

*/
void pointer1()
{
	//int null = 0, *p = null;
	s32 null = 0;
	s32 *p = &null;
	s32 *p2 = (int*)null;
	s32 *p3 = nullptr;

	std::cout << "p addr is " << p << std::endl;
	std::cout << "p2 addr is " << p2 << std::endl;
	std::cout << "p3 addr is " << p3 << std::endl;

	return;
}

void Printconst()
{
	const double pi = 3.14;
	const double pi2 = 3.1415;
	// ppi是一个指向常量对象的常量指针;
	const double* const ppi = &pi;

	// ppi3是一个常量指针;
	const double* ppi3 = &pi;

	// 也就是做ppi的地址和所对应的值都不能被改变;
	//ppi = &pi2;      ppi是指向常量的常量指针,ppi不是一个可赋值的左值;
	//*ppi = 3.141;    ppi是指向常量的常量指针,ppi不是一个可赋值的左值;

	// ppi3的地址可以改变?????;
	ppi3 = &pi2;

	std::cout << *ppi3 << std::endl;

}