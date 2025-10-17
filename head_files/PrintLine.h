#pragma once
#include <Windows.h>
#include <string>
#include <iostream>

enum textColor {black, blue, green, cyan, red, purple, yellow, white};

//The default value of color is 7(white)
inline void print_line(std::string s, textColor foreColor = white, textColor backColor = black) {
	WORD colorAttribute = static_cast<WORD>(foreColor) | (static_cast<WORD>(backColor) << 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorAttribute);
	std::cout << s;
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

// 去除小数点后多余的0
inline std::string decline0s(std::string str) {
	if (str.find('.') != std::string::npos) {
		// 去除末尾的0
		str.erase(str.find_last_not_of('0') + 1, std::string::npos);
		// 如果小数点后没有数字了，去掉小数点
		if (str.back() == '.') {
			str.pop_back();
		}
	}
	return str;
}