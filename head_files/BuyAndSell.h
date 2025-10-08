#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "../head_files/GridCalculating.h"
#include "../head_files/GetGrid.h"
#include "../head_files/ProcessData.h"  // 引入ProcessData头文件

// 注意：移除了原Data结构体和head全局变量，使用ProcessData中的Data结构体

class AcceptData
{
public:
    AcceptData(std::string a) : textname(a) {};
    ~AcceptData() = default;  // 无需释放链表资源
    void importToDB(string filename);  // 改为导入数据库
    std::vector<ProcessData::Data> exportFromDB(const std::string& tableName);  // 从数据库导出
    void print(const std::vector<ProcessData::Data>& dataList);  // 打印数据列表
private:
    std::string textname;
    ProcessData dbHandler;  // 数据库处理对象
};

void inti(int size,string date, Grid& a, int number, std::vector<int>& numexcel, std::vector<grid>& gridexcel,double first_data_in);
void start_buy_and_sell(Grid user_grid);
void start_buy_and_sell2(Grid user_grid);//实时获取数据、实时购买的模板
void buy(string date, Grid& a, int number, std::vector<int>& numexcel, std::vector<grid>& gridexcel);
void sell(string date, Grid& a, int number, std::vector<int>& numexcel, std::vector<grid>& gridexcel);
int show_inventory(std::vector<int>& numexcel);//展示股数