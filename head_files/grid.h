#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Grid
{
private:
public:
    Grid();
    ~Grid();

    struct grid {
        string date = "nullptr";     // 日期
        double unit;     // 交易价格
        int i;           // 交易序号
        double sell;     // 卖出价格
        bool sold = false; // 是否卖出标志
    };

    void print(grid line); // 打印结构体成员
    void divide(double unit, int n, double a, std::vector<grid> &rattle, double b); // 分网格函数
    int getIndex(double price, std::vector<grid> &rattle); // 得到价格所在的网格
    void sortBYunit(std::vector<grid> &vec); // 买卖时对网格进行排序
    void sortBYi(std::vector<grid> &vec); //买卖结束后对网格进行排序
};
