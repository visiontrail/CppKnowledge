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

const Screen& Screen::display() const
{
	do_dispaly();
	return *this;
}

Screen& Screen::display()
{
	do_dispaly();
	return *this;
}

void Screen::do_dispaly() const
{
	std::cout << "Screen is: " << std::endl;
	std::cout << "      ";
	for (int PrintCol = 0; PrintCol < this->width
		; ++PrintCol)
	{
		std::cout << " " << PrintCol;
	}
	printf("\n");
	for (pos Row = 0; Row < this->height; ++Row)
	{
		//std::cout << "Row" << Row + 1 << ":";
		printf("Row%2d:", Row);
		for (pos Col = 0; Col < this->width; ++Col)
		{
			std::cout << " " << content[((this->height * Row) + Col)];
		}
		std::cout << std::endl;
	}
}