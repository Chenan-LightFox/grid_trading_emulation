#include "../head_files/buy_and_sell.h"

void buy(Grid a,int number, std::vector<int> grid) {
    //int 买入股数=买入金额/该序号对应的买入价格
    std::ofstream trading_log("./GTE_Data/trading_log.txt", std::ios::app);

    // if(总资产-买入金额* 买入价格>=0){
    //     总资产-= 买入金额 * 买入价格;
    //     grid[number] += 买入股数;
    //     trading_log << "于某时以"<<买入价格<<"买入"<<买入股数<<"股"<<std::endl<<"－"<<买入金额 * 买入价格<<"元"<<"\n\n";
    // }
    // else {
    //     trading_log << "于某时资金不足无法买入"<<"\n\n";
    // }

    trading_log.close();
}
 void sell(Grid a, int number, std::vector<int> grid) {
    std::ofstream trading_log("./GTE_Data/trading_log.txt", std::ios::app);

    // if(grid[number] > 0) {
    //     总资产+= grid[number] * 卖出价格;
    //     trading_log<< "于某时"<<卖出价格<<"卖出"<<grid[number]<<"股"<<std::endl<<"+"<<grid[number] * 卖出价格<<"元"<<"\n\n";
    //     grid[number] = 0; 
    // } else {
    //     std::cout << "没有持有股票，无法卖出。" << "\n\n";
    // }
    trading_log.close();
 }