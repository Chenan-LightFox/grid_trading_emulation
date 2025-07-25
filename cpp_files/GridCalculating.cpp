#include <iostream>
#include <fstream>
#include "../head_files/GridCalculating.h"
#include "../head_files/PrintLine.h"

// 输入初始网格参数
void Grid::grid_params_input() {
	print_line("\t\t请输入参数：");
	print_line("\t\t\t捕捉波动大小\t：", cyan);
	std::cin >> gridSize;
	print_line("\t\t\t一行的收益率\t：", cyan);
	std::cin >> profitRate;
	print_line("\t\t\t首行买入触发价\t：", cyan);
	std::cin >> firstBuyInPrice;
	print_line("\t\t\t模型行数\t\t：", cyan);
	std::cin >> gridLine;
	print_line("\t\t\t买入金额\t\t：", cyan);
	std::cin >> buyInAmounts;
}

// 输出网格参数到文件
void Grid::grid_params_save() {
	std::ofstream outFile("./GTE_Data/grid_params.txt");
	if (outFile.is_open()) {
		outFile << gridSize << profitRate << firstBuyInPrice
				<< gridLine << buyInAmounts;
		outFile.close();
		print_line("[√]参数已保存到 grid_params.txt", green);
	} else {
		print_line("[x]无法打开文件保存参数", red);
	}
}