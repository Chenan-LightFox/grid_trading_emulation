#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>

class Grid
{
private:
public:
    Grid();
    ~Grid();

    struct grid // 定义一个网格的结构体用来存放各种数据。
    {
        double center = 0; // 定义中心
        double unit = 0;   // 定义网格线对应的价格
        int i = 0;         // 作为标号
        double sell = 0.0; // 定义卖出价格
    };

    void print(grid line); // 打印结构体成员
    void divide(double center, int unit, int n, double a, std::vector<grid> &rattle, double b); // 分网格函数
    void sell(double price,  double b, std::vector<grid> &buy);        // 卖出函数
    int getIndex(double high,double low, std::vector<grid> &rattle); // 得到价格所在的网格
};

#endif