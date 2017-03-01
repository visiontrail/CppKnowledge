#pragma once
#ifndef WIN_MGR_H
#define WIN_MGR_H

#include <vector>
#include "Screen.h"
using namespace std;

class Window_Manager
{
	// 实现一个将screen屏幕清零的函数;
public:
	void Clear();
	~Window_Manager();
	Screen scr1;
private:
};

#endif // WIN_MGR_H!
