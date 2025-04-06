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
        fin >> line >> center;
        fin >> line >> a;
        fin >> line >> b;
        fin >> line >> w;
        fin >> line >> n;
        fin.close();
    }
    // 方便测试
    cout << "基准价（元/股）：" << center << endl;
    cout << "网格大小（%）：" << a << endl;
    cout << "期望收益率（%）：" << b << endl;
    cout << "一次买入金额（元）：" << w << endl;
    cout << "模拟行数：" << n << endl;
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
