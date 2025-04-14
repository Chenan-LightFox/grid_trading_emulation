#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <string>

class Grid
{
private:
public:
    Grid();
    ~Grid();

    struct grid {
        string date;     // 日期
        double unit;     // 交易价格
        int i;           // 交易序号
        double sell;     // 卖出价格
        bool sold = false; // 新增：是否已卖出
    };

    void print(grid line); // 打印结构体成员
    void divide(int unit, int n, double a, std::vector<grid> &rattle, double b); // 分网格函数
    void sell(double price,  double b, std::vector<grid> &buy);        // 卖出函数
    int getIndex(double high,double low, std::vector<grid> &rattle); // 得到价格所在的网格
    void sort(std::vector<grid> &vec); // 对网格进行排序
};

#endif