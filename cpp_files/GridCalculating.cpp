#include <iostream>
#include "../head_files/GridCalculating.h"
#include "../head_files/PrintLine.h"

// �����ʼ�������
void Grid::grid_params_input() {
	print_line("\t\t�����������");
	print_line("\t\t\t��׽������С\t��", cyan);
	std::cin >> gridSize;
	print_line("\t\t\tһ�е�������\t��", cyan);
	std::cin >> profitRate;
	print_line("\t\t\t�������봥����\t��", cyan);
	std::cin >> firstBuyInPrice;
	print_line("\t\t\tģ������\t\t��", cyan);
	std::cin >> gridLine;
	print_line("\t\t\t������\t\t��", cyan);
	std::cin >> buyInAmounts;
}