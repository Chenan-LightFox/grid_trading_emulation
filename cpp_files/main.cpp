#include <iostream>
#include <fstream>
#include <Windows.h>
#include "../head_files/MainMenu.h"
#include "../head_files/GlobalVariables.h"
using namespace std;

void loadFromFile() //每次程序启动时，从文件中读取数据
{
    ifstream fin("docs/data.txt");
    if (fin)
    {
        string line;
        fin >> line >> CENTER;
        fin >> line >> GridSize;
        fin >> line >> YIELD;
        fin >> line >> FUND;
        fin >> line >> ROWS;
        fin.close();
    }
    // 方便测试
    cout << "基准价（元/股）：" << CENTER << endl;
    cout << "网格大小（%）：" << GridSize << endl;
    cout << "期望收益率（%）：" << YIELD << endl;
    cout << "一次买入金额（元）：" << FUND << endl;
    cout << "模拟行数：" << ROWS << endl;
}

int main() // main function
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    // ↑解决中文乱码问题
    loadFromFile();
    MainMenu mainmenu;
    mainmenu.show();
    mainmenu.get_start();
    system("pause");
    return 0;
}
