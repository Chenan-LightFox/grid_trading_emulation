#include <iostream>
#include <fstream>
#include "../head_files/GridCalculating.h"
#include "../head_files/PrintLine.h"

// 输入初始网格参数
void Grid::grid_params_input() {
	print_line("\n\n\n\t\t\t请输入参数：\n");
	print_line("\t\t\t捕捉波动大小\t：", cyan);
	std::cin >> gridSize;
	print_line("\n\t\t\t一行的收益率\t：", cyan);
	std::cin >> profitRate;
	print_line("\n\t\t\t首行买入触发价\t：", cyan);
	std::cin >> firstBuyInPrice;
	print_line("\n\t\t\t模型行数\t：", cyan);
	std::cin >> gridLine;
	print_line("\n\t\t\t买入金额\t：", cyan);
	std::cin >> buyInAmounts;
}

// 输出网格参数到文件
void Grid::grid_params_save() {
	std::ofstream outFile("./GTE_Data/grid_params.txt");
	if (outFile.is_open()) {
		outFile << gridSize << " " << profitRate << " " <<
			firstBuyInPrice << " " << gridLine << " " << buyInAmounts;
		outFile.close();
		print_line("\n[√]参数已保存到 grid_params.txt\n", green);
	} else {
		print_line("\n[x]无法打开文件保存参数\n", red);
	}
}

// 从文件读取网格参数
void Grid::grid_params_read() {
	std::ifstream inFile("./GTE_Data/grid_params.txt");
	if (inFile.is_open()) {
		inFile >> gridSize >> profitRate >> firstBuyInPrice
			   >> gridLine >> buyInAmounts;
		inFile.close();
		print_line("\n\n\t\t\t您目前的参数设置如下：\n", green);
		print_line("\t\t\t捕捉波动大小\t：", cyan);
		print_line(std::to_string(gridSize), green);
		print_line("\n\t\t\t一行的收益率\t：", cyan);
		print_line(std::to_string(profitRate), green);
		print_line("\n\t\t\t首行买入触发价\t：", cyan);
		print_line(std::to_string(firstBuyInPrice), green);
		print_line("\n\t\t\t模型行数\t：", cyan);
		print_line(std::to_string(gridLine), green);
		print_line("\n\t\t\t买入金额\t：", cyan);
		print_line(std::to_string(buyInAmounts) + "\n", green);
	} else {
		print_line("\n\n\t\t\t您目前未设置参数。\n", red);
	}
}