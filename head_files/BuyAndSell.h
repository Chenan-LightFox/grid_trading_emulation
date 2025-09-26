#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "../head_files/GridCalculating.h"
#include "../head_files/GetGrid.h"
/*opencv*/

class Grid; // 前向声明Grid类

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

class AcceptData
{
public:
	AcceptData(std::string a) :
		textname(a) {};
	~AcceptData();
	void read(Data*& m);
	void print(Data* m);
private:
	std::string textname;
};

void accept_data();
void start_buy_and_sell(Grid user_grid); 
void buy(Grid &a,int number,std::vector<int>numexcel,std::vector<grid> gridexcel);

void sell(Grid &a,int number,std::vector<int>numexcel,std::vector<grid> gridexcel);
