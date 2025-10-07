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


void start_buy_and_sell(Grid user_grid);
void buy(Grid& a, int number, std::vector<int>& numexcel, std::vector<grid>& gridexcel);
void sell(Grid& a, int number, std::vector<int>& numexcel, std::vector<grid>& gridexcel);