#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include<iomanip>
#include "../head_files/GridCalculating.h"

struct Data {
	std::string date;	//日期
	double Open;		//开盘价
	double High;		//最高价
	double Low;			//最低价
	double Close;		//收盘价
	double Change;		//涨跌额
	double Amplitude;	//涨跌幅
	double Volume;		//成交量
	double Turnover;	//成交额
	Data* next;
};
extern Data* head;			// 实现时通过extern声明

class Accept_data
{
public:
	Accept_data(std::string a) :
		textname(a) {};
	~Accept_data();
	void read(Data*& m);
	void print(Data* m);
private:
	std::string textname;
};

void accept_data();
void start_buy_and_sell(std::vector<int> grid); 
void buy(const Grid a,int number,std::vector<int>grid);//number，grid存储使用者目前各个网格的持有数,目前未接入软件故仅无法真正买入卖出，资产均由四则运算得到
void sell(const Grid a,int number,std::vector<int>grid);