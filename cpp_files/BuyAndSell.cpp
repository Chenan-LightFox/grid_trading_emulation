#include "../head_files/BuyAndSell.h"
#include "../head_files/PrintLine.h"
#include <windows.h>
#include "../head_files/GetGrid.h"
using namespace std;

// 导入数据到数据库
void AcceptData::importToDB(string filename)
{
    dbHandler.ImportData(filename);
}

// 从数据库导出数据
vector<ProcessData::Data> AcceptData::exportFromDB(const string& tableName)
{
    return dbHandler.ExportData(tableName);
}

// 打印数据列表
void AcceptData::print(const vector<ProcessData::Data>& dataList)
{
    // 打印表头
    cout << setw(12) << "date"
        << setw(12) << "Open"
        << setw(12) << "High"
        << setw(12) << "Low"
        << setw(12) << "Close"
        << setw(12) << "Change"
        << setw(12) << "ChangePercent"
        << setw(12) << "Volume"
        << setw(12) << "Turnover" << endl;

    // 遍历数据列表并打印
    for (const auto& data : dataList)
    {
        cout << setw(12) << data.date
            << setw(12) << data.open
            << setw(12) << data.high
            << setw(12) << data.low
            << setw(12) << data.close
            << setw(12) << data.change
            << setw(12) << data.changePercent
            << setw(12) << data.volume
            << setw(12) << data.turnover << endl;
    }
}

void start_buy_and_sell(Grid user_grid) {
    // 获取表名（根据实际需求调整，这里假设用户输入的表名存储在某个变量中）
    string tableName;
    cout << "请输入要操作的表名：";
    cin >> tableName;

    // 导入数据到数据库（如果尚未导入）
    AcceptData acceptData(tableName);

    if (!ProcessData::tableExists("./GTE_Data/Database.db", tableName)) {
		acceptData.importToDB(tableName);  // 仅当表不存在时导入
    }

    // 从数据库导出数据
    vector<ProcessData::Data> dataList = acceptData.exportFromDB(tableName);
    if (dataList.empty()) {
        print_line("错误：未获取到数据", red);
        return;
    }

    // 生成网格数据
    int size = user_grid.gridLine;
    vector<grid> gridexcel = get_grid(user_grid);  // 标准网格
    vector<int> numexcel(size, 0);  // 持有股数初始化

    print_line("数据已导入，开始模拟买卖。");

	cout << "初始资产：" << user_grid.properity << "元" << endl;

    // 线性模拟买卖，遍历数据库导出的数据列表
    for (const auto& data : dataList) {
        // 使用ProcessData::Data中的字段（注意字段名小写）
        if (data.open - data.close > 0) {
            for (int i = size - 1; i >= 0; i--) {  // 上升段
                if (gridexcel[i].buy > data.open) {
                    if (data.high > gridexcel[i].buy) {
                        buy(user_grid, i, numexcel, gridexcel);
                    }
                    else {
                        break;
                    }
                }
            }
            for (int i = 0; i < size; i++) {  // 下降段
                if (gridexcel[i].sell < data.high) {
                    if (gridexcel[i].sell > data.low) {
                        sell(user_grid, i, numexcel, gridexcel);
                    }
                    else {
                        break;
                    }
                }
            }
            for (int i = size - 1; i >= 0; i--) {  // 上升段
                if (gridexcel[i].buy > data.low) {
                    if (data.close > gridexcel[i].buy) {
                        buy(user_grid, i, numexcel, gridexcel);
                    }
                    else {
                        break;
                    }
                }
            }
        }
        else {
            for (int i = 0; i < size; i++) {  // 下降段
                if (gridexcel[i].sell < data.open) {
                    if (gridexcel[i].sell > data.low) {
                        sell(user_grid, i, numexcel, gridexcel);
                    }
                    else {
                        break;
                    }
                }
            }
            for (int i = size - 1; i >= 0; i--) {  // 上升段
                if (gridexcel[i].buy > data.low) {
                    if (data.high > gridexcel[i].buy) {
                        buy(user_grid, i, numexcel, gridexcel);
                    }
                    else {
                        break;
                    }
                }
            }
            for (int i = 0; i < size; i++) {  // 下降段
                if (gridexcel[i].sell < data.high) {
                    if (gridexcel[i].sell > data.close) {
                        sell(user_grid, i, numexcel, gridexcel);
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    print_line("买卖模拟完成。交易日志产生");
	system("pause");
	cout << "最终资产：" << user_grid.properity << "元" << endl;
}

void buy(Grid& a, int number, vector<int>& numexcel, vector<grid>& gridexcel) {
    // 买入股数，使用用户输入的数据
    int numOfBuy = a.buyInAmounts / gridexcel[number].buy;
    ofstream trading_log("./GTE_Data/trading_log.txt", ios::app);

    if (a.properity - numOfBuy * gridexcel[number].buy >= 0) {
        a.properity -= numOfBuy * gridexcel[number].buy;
        numexcel[number] += numOfBuy;
        trading_log << "于某时以" << gridexcel[number].buy << "每股买入" << numOfBuy << "股" << endl
            << "－" << numOfBuy * gridexcel[number].buy << "元" << "\n\n";
    }
    else {
        trading_log << "于某时资金不足无法买入" << "\n\n";
    }

    trading_log.close();
}

void sell(Grid& a, int number, vector<int>& numexcel, vector<grid>& gridexcel) {
    ofstream trading_log("./GTE_Data/trading_log.txt", ios::app);

    if (numexcel[number] > 0) {
        a.properity += numexcel[number] * gridexcel[number].sell;
        trading_log << "于某时以" << gridexcel[number].sell << "卖出" << numexcel[number] << "股" << endl
            << "+" << gridexcel[number].sell * numexcel[number] << "元" << "\n\n";
        numexcel[number] = 0;
    }
    else {
        cout << "于某时没有持有股票，无法卖出。" << "\n\n";
    }

    trading_log.close();
}