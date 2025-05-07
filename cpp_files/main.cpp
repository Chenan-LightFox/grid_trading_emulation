#include <iostream>
#include <fstream>
#include <Windows.h>
#include "../head_files/MainMenu.h"
#include "../head_files/GlobalVariables.h"
using namespace std;

void loadFromFile() //每次程序启动时，从文件中读取数据
{
    ifstream fin("docs/data.txt");
    
    if(fin)
    {
        string line;
        fin >> line >> CENTER;
        fin >> line >> GridSize;
        fin >> line >> YIELD;
        fin >> line >> FUND;
        fin >> line >> ROWS;
        fin >> line >> ALL;
        CUR_ALL = ALL; 
    }

    if(fin.is_open()==false) {
        system("cls");
        cout<<"\t\t\t请设置您的交易信息：\n";
        cout << "基准价（元/股）：";
        cin >> CENTER;
        cout << "网格大小（%）：";
        cin >> GridSize;
        cout << "期望收益率（%）：";
        cin >> YIELD;
        cout << "一次买入金额（元）：";
        cin >> FUND;
        cout << "模拟行数：";
        cin >> ROWS;
        cout<<"总资金：";
        cin>>ALL;
        cout << "所有参数已成功设置!\n";
        ofstream fout("docs/data.txt", ios::app);
        fout << "CENTER " << CENTER << endl;
        fout << "GridSize " << GridSize << endl;
        fout << "YIELD " << YIELD << endl;
        fout << "FUND " << FUND << endl;
        fout << "ROWS " << ROWS << endl;
        fout << "ALL " << ALL << endl;
        CUR_ALL = ALL;
        fout.close();
    }

    fin.close();
}

int main() // main function
{  
    if (system("cd docs") == 1) { // 检查docs文件夹是否存在
        system("mkdir docs"); // 创建docs文件夹
        cout << "docs文件夹不存在，已为您创建！\n";
        system("pause");
    }
    else system("cd ../");
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