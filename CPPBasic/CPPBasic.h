#pragma once

#include "stdafx.h"
#include <iostream>
#include <string>

#include "Sales_data.h"
#include "Screen.h"
#include "Bank_Acount.h"

using namespace std;

// 函数声明;
/* 声明const.cpp中的函数 */
void pointer1();
void ConstDefineInitPrint();
void ConstDefinePrint();

/* 声明auto.cpp中的函数 */
void autoUsing_JudgeType();

/* 声明function.cpp中的函数 */
string &refStringA(string&);
// 给定了一个默认参数;
int factorial(int val = 5);

void Printconst();