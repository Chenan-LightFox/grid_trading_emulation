#pragma once

class Grid {
public:
	double gridSize;		// 捕捉波动大小
	double profitRate;		// 一行的收益率
	double firstBuyInPrice;	// 首行买入触发价
	int	   gridLine;		// 模型行数
	double buyInAmounts;	// 买入金额
	double properity;		// 总资产

	void grid_params_input();
	void grid_params_save();
};
