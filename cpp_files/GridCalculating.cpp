#include <iostream>
#include "../head_files/GridCalculating.h"
#include "../head_files/PrintLine.h"

// 输入初始网格参数
void Grid::grid_params_input() {
	print_line("\t\t请输入参数：", white);
	print_line("\t\t\t捕捉波动大小\t：",cyan);
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