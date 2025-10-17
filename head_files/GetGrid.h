#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include "../head_files/GridCalculating.h"
using namespace std;

// 网格交易单格参数结构体
struct grid {
    double stage = 1.00;    // 档位系数(初始为1.00)
    double rdbuy = 0.0;     // 买入触发价
    double buy = 0.0;       // 实际买入价
    double rdsell = 0.0;    // 卖出触发价
    double sell = 0.0;      // 实际卖出价
    double decrease = 0;    // 相对初始档位跌幅
    double profit = 0.0;    // 该格交易理论盈利
};

// 根据配置生成网格数据列表
static vector<grid> get_grid(Grid g) {
    vector<grid> arr;
    // 计算首个网格参数并添加到列表
    double firstBuy = g.firstBuyInPrice - 0.005;  // 首格买入价(触发价-0.005)
    double firstSell = firstBuy * (1 + g.profitRate / 100.0);  // 首格卖出价(按利润率计算)
    arr.push_back({
        1.00,
        g.firstBuyInPrice,          // 首格买入触发价
        firstBuy,
        firstSell - 0.005,          // 首格卖出触发价(卖出价-0.005)
        firstSell,
        0,                          // 首格无跌幅
        (firstSell - firstBuy) * (g.buyInAmounts / firstBuy)  // 首格盈利
    });

    // 循环生成剩余网格(总数为gridLine)
    for (int i = 0; i < g.gridLine - 1; ++i) {
        double tstage = arr[i].stage / (1 + g.gridSize / 200);  // 计算当前档位系数
        double tbuyTrig = arr[0].rdbuy * tstage;              // 当前买入触发价
        double tbuy = tbuyTrig - 0.005;                       // 当前买入价
        double tsell = tbuy * (1 + g.profitRate / 100);             // 当前卖出价
        
        arr.push_back({
            tstage,
            tbuyTrig,
            tbuy,
            tsell - 0.005,           // 当前卖出触发价
            tsell,
            tstage - 1,              // 计算跌幅(档位系数-1)
            (tsell - tbuy) * (g.buyInAmounts / tbuy)  // 当前网格盈利
        });
    }
    return arr;
}

// 打印网格数据列表(调试用)
/*
static void print_grid(const vector<grid>& arr) {
    cout << "\n";
    cout << fixed << setprecision(3);
    cout << setw(16) << "档位系数" << setw(16) << "买入触发价" << setw(16)
        << "买入价" << setw(16) << "卖出触发价" << setw(16)
        << "卖出价" << setw(16) << "跌幅" << setw(16) << "理论盈利" << "\n";
    for (const auto& g : arr) {
        cout << setw(16) << g.stage << setw(16)
            << g.rdbuy << setw(16)
            << g.buy << setw(16)
            << g.rdsell << setw(16)
            << g.sell << setw(16)
            << g.decrease << setw(16)
            << g.profit << "\n";
    }
}
*/