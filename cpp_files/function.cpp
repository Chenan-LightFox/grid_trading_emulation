#include<iostream>
#include<vector>
#include<iomanip>
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


int main()
{
	double a = 0;//a指波动大小，任务二里是百分比这里方便计算用小数，大小范围为0.05-0.3
	cout << "请输入波动大小:" << endl;
	cin >> a;

	double b = 0.0;//b指一行的利益率，数值范围是0.02-0.3，没有进行百分数处理
	cout << "请输入一行的利益率:" << endl;;
	cin >> b;

	double frdbuy = 0.0;//这里指的是首行的买入触发价
	cout << "请输入首行买入触发价:" << endl;
	cin >> frdbuy;

	int line = 0;//模型行数 由用户输入
	cout << "请输入模型行数:" << endl;
	cin >> line;

	int tmoney = 0;//每一次网格的固定购买金额
	cout << "请输入你每次购买时的买入金额:" << endl;
	cin >> tmoney;

	double fbuy = frdbuy - 0.005;
	double fsell = fbuy * (1 + b);
	double frdsell = fsell - 0.005;
	double fprofit = (fsell - fbuy) * (tmoney / fbuy);
	grid fgrid = { 1.00,frdbuy,fbuy,frdsell,fsell,0,fprofit};
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
	cout << setw(5) << "序号" << '\t'
		<< setw(8) << "跌幅" << '\t'
		<< setw(8) << "档位" << '\t'
		<< setw(12) << "买入触发价" << '\t'
		<< setw(12) << "买入交易价" << '\t'
		<< setw(8) << "金额" << '\t'
		<< setw(12) << "卖出触发价" << '\t'
		<< setw(12) << "卖出交易价" << '\t'
		<<setw(8)<<"盈利"<<endl;
	
	for (int i = 0; i < line; i++)
	{
		cout << setw(5) << i + 1 << '\t'
			<< setw(8) << arr[i].decrease << '\t'
			<< setw(8) << arr[i].stage << '\t'
			<< setw(12) << arr[i].rdbuy << '\t'
			<< setw(12) << arr[i].buy << '\t'
			<< setw(8) << tmoney << '\t'
			<< setw(12) << arr[i].rdsell << '\t'
			<< setw(12) << arr[i].sell << '\t'
			<<setw(8)<<arr[i].profit<<endl;
	}

};
