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
        double unit = 0;   // 定义每股多少元
        int i = 0;         // 作为标号
        double sell = 0.0; // 定义卖出价格
    };

    void divide(double center, int unit, int n, double a, std::vector<grid> &rattle, double b); // 分网格函数
    grid sell(double price, std::vector<grid> &rattle, double b, std::vector<grid> buy);        // 卖出函数
};

#endif