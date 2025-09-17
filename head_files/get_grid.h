#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "../head_files/GridCalculating.h"
using namespace std;

struct grid
{
	double stage = 1.00;//档位
	double rdbuy = 0.0;//买入触发价
	double buy = 0.0;//交易买入价
	double  rdsell = 0.0;//卖出触发价
	double sell = 0.0;//交易卖出价
	double decrease = 0;//跌幅
	double profit = 0;//盈利
};

static vector<grid> get_grid(Grid g){
	double a=g.gridSize;
	double b=g.profitRate;
	double frdbuy=g.firstBuyInPrice;
	int line=g.gridLine;
	double tmoney=g.buyInAmounts;
	double fbuy = frdbuy - 0.005;
	double fsell = fbuy * (1 + b);
	double frdsell = fsell - 0.005;
	double fprofit = (fsell - fbuy) * (tmoney / fbuy);
	grid fgrid = { 1.00,frdbuy,fbuy,frdsell,fsell,0,fprofit };
	double tstage = 1.00;
	double trdbuy = 0;
	double tbuy = 0;
	double trdsell = 0;
	double tsell = 0;
	double tprofit = 0;
	vector<grid>arr;
	arr.push_back(fgrid);
	double tdecrease = 0;
	for (int i = 0; i < line - 1; i++)
	{
		tstage = arr[i].stage / (1 + a / 2);
		tdecrease = tstage - 1;
		trdbuy = arr[0].rdbuy * tstage;
		tbuy = trdbuy - 0.005;
		tsell = tbuy * (1 + b);
		trdsell = tsell - 0.005;
		tprofit = (tsell - tbuy) * (tmoney / tbuy);
		arr.push_back({ tstage,trdbuy,tbuy,trdsell,tsell,tdecrease,tprofit });
	}
	return arr;
}
