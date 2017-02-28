#include "stdafx.h"
#include "Screen.h"

Screen& Screen::move(pos x, pos y)
{
	pos row = width * x;
	this->curcos = row + y;
	return *this;
}

char Screen::get(pos x, pos y) const
{
	pos row = width * x;
	return content[row + y];
}