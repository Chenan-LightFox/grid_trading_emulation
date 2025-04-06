#include "../head_files/grid.h"
#include "../head_files/GlobalVariables.h"
using namespace std;

Grid::Grid() {};
Grid::~Grid() {};



void Grid::divide(double center, int unit, int n, double a, vector<grid> &rattle, double b)
// 作为分网格的函数,center确定中线,unit确定单位价,n确定总共设置的行数,默认用户给的n是偶数,不然上下不平,a是网格的百分比，b是卖出价格的百分比
{
	// 创建一个能够存储多个结构体的动态数组,数组传在上面不然只能函数定义域
	grid rattle0;
	rattle0.center = center;
	rattle0.unit = unit;
	rattle0.i = 0;
	rattle0.sell = center * (1 + (b / 100.0));
	rattle.push_back(rattle0);
	for (int i = 1; i <= n / 2; i++) // 向上设置网格
	{
		grid *p = new grid;
		p->center = center;
		p->i = i;
		p->unit = unit * (1 + i * (a / 100.0));
		rattle.push_back(*p);
	}
	for (int i = 1; i <= n / 2; i++) // 向下设置网格
	{
		grid *p = new grid;
		p->center = center;
		p->i = i;
		p->unit = unit * (1 - i * (a / 100.0));
		rattle.insert(rattle.begin(), *p); // 一直在数组的最前面插入结构体信息
	}
}

void Grid::sell(double price,double b, vector<grid> &buy) // 用来判断哪组需要卖出
{
	int c = 0;
	int size=sizeof(buy)/sizeof(grid);
	for (int i = 0;i<size; i++) // 找出目前价格会在哪个网格之下网格，然后在这之下找
	{
		if (buy[i].sell >= price)
		{
			c = i-1;
			break;
		}
	}
	for (int i = 0; i <= c; i++)
	{
		if (price >= buy[i].sell)
		{
			buy.erase(buy.begin() + i); // 当实时价格超过存储的批次所对应的网格的目标金额则删除该批次，认为已卖出
		}
	}
    for(int i=c+1;i<size;i++)//前面的删除后，后面的会补到前面去，补完之后这些变为空白位置
	{
		grid reset;
      grid tem=buy[i];
	  buy[i]=reset;
	  buy[i-c+1]=tem;
	}
	for(int i=0;i<size;i++)//在往前补了之后把空白位置删除掉
	
	{
		if(buy[i].sell=0.0)
		{
			buy.erase(buy.begin()+i);
		}
	}
}