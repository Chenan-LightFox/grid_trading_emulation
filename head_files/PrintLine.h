#pragma once
#include <Windows.h>
#include <string>
#include <iostream>

enum textColor {black, blue, green, cyan, red, purple, yellow, white};

//The default value of color is 7(white)
inline void print_line(std::string s, textColor color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	std::cout << s << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
}

/*
	black	| 0
	blue	| 1
	green	| 2
	cyan	| 3
	red		| 4
	purple	| 5
	yellow	| 6
	white	| 7
*/