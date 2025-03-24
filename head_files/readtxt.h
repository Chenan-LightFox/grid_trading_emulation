#include<iostream>
#include<fstream>	
#include<sstream>
#include<string>
struct Data {
	std::string date;//日期
	double Open;//开盘价
	double High;//最高价
	double Low;//最低价
	double close;//收盘价
	double Change;//涨跌
	double Amplitude;//涨跌幅
	double Volume;//成交量
	double Turnover;//成交金额
	Data* next;
}*head=NULL;
class ReadTxt
{
public:
	ReadTxt(std::string a) :
	textname(a){};
	~ReadTxt();
	void read(Data* &m);
	void print(Data* m);
private:
	std::string textname;
};//没有主动创建txt文件，需要用户自己创建并放入根目录

