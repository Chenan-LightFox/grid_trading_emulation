#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct Data
{
	std::string date; // 日期
	double Open;	  // 开盘价
	double High;	  // 最高价
	double Low;		  // 最低价
	double Close;	  // 收盘价
	double Change;	  // 涨跌额
	double Amplitude; // 涨跌幅
	double Volume;	  // 成交量
	double Turnover;  // 成交额
	Data *next;
};

extern Data *head; // 实现时通过extern声明

class ReadTxt
{
public:
	ReadTxt(std::string a) : textname(a) {};
	~ReadTxt();
	void read(Data *&m);
	void print(Data *m);

private:
	std::string textname;
}; // 没有主动创建txt文件，需要用户自己创建并放入根目录，然后输入文件名即可

/*用法
int main() {
	std::string filename = "docs/data.txt";
	ReadTxt readtext(filename); //从此开始head才有数据，能够调用，若出错应则停止程序（即head==NULL）
	readtext.read(head);
	readtext.print(head);
	return 0;
}*/