#include <iostream>
#include <fstream>
#include <Windows.h>
#include "head_files/MainMenu.h"
#include "head_files/GlobalVariables.h"
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
        fin >> line >> ALL;
        CUR_ALL = ALL; 
        fin.close();
    }
    // 方便测试
    // cout << "基准价（元/股）：" << CENTER << endl;
    // cout << "网格大小（%）：" << GridSize << endl;
    // cout << "期望收益率（%）：" << YIELD << endl;
    // cout << "一次买入金额（元）：" << FUND << endl;
    // cout << "模拟行数：" << ROWS << endl;
}

int main() // main function
{  
    loadFromFile();
    system("cls");
    if(ALL==0){
        cout<<"\t\t\t请设置总资金：";
        cin>>ALL;
        ofstream fout("docs/data.txt",ios::app);
        fout<<"ALL "<<ALL<<endl;
    }
    MainMenu mainmenu;
    mainmenu.show();
    mainmenu.get_start();
    system("pause");
    return 0;
}
