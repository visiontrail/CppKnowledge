#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using std::vector;

extern class Window_Manager;

class Screen
{
	friend Window_Manager;
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos width, pos height, char c)
		: width(width), height(height), content(width * height, c) {}

	char get() const
	{
		return content[curcos];
	}
	inline char get(pos x, pos y) const;

	Screen& set(char c)
	{
		content[curcos] = c;
		return *this;
	}
	Screen& set(pos x, pos y, char c)
	{
		pos row = this->width * x;
		this->content[row + y] = c;
		return *this;
	}

	Screen& move(pos x, pos y);

	// 有两个display的目的是为了针对不同的对象，有不同的display可以使用;
	const Screen& display() const;
	Screen& display();

private:
	pos curcos = 0;        // 光标位置;
	pos height = 0;        // 屏幕高;
	pos width = 0;         // 屏幕宽;
	std::string content;   // 显示内容;
	void do_dispaly() const;
};

#endif // !SCREEN_H