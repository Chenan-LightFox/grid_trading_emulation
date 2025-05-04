#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "../head_files/SetArgument.h"
#include "../head_files/ProfileMainpage.h"
#include "../head_files/GlobalVariables.h"
using namespace std;

SetArgument::SetArgument() {}
SetArgument::~SetArgument() {}

void SetArgument::show_mainpage()
{
    ProfileMainpage profile;
    string filename = "docs/data.txt";
    ifstream fin;
    fin.open(filename, ios::in);
    if (fin.is_open() == 0)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
        cout << "所有参数已成功设置!\n";
        getDATAfile();
        system("pause");
        profile.show_mainpage();
    }
    else
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        system("cls");
        cout << "\n\n\n\t\t\t您已经设置过参数：\n";
        show_profile(fin);
        fin.close();
        cout << "\n\n\t\t\t是否重新设置参数？";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        cout << "\n\n\t\t\t[1] 是";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout << "\n\n\t\t\t[2] 否\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        int op;
        cin >> op;
        if (op == 1)
        {
            system("cls");
            if (remove(filename.c_str()) != 0) {
                std::perror("删除失败");
            }
            else {
                show_mainpage();
            }
        }
        else
        {
            system("cls");
            profile.show_mainpage();
        }
    }
}

void SetArgument::show_profile(istream &fin)
{
    cout << "\t\t\t基准价（元/股）：" << CENTER << endl;
    cout << "\t\t\t网格大小（%）：" << GridSize << endl;
    cout << "\t\t\t期望收益率（%）：" << YIELD << endl;
    cout << "\t\t\t一次买入金额（元）：" << FUND << endl;
    cout << "\t\t\t模拟行数：" << ROWS << endl;
}

void SetArgument::getDATAfile()
{
    ofstream fout;
    fout.open("docs/data.txt", ios::out); // 若不存在该文件，会自动创建
    // ios::out,ios::trunc和不写意义一样，覆盖式；
    // ios::app 追加式
    if (fout.is_open() != false)
    {
        fout << "CENTER " << CENTER << endl;
        fout << "GridSize " << GridSize << endl;
        fout << "YIELD " << YIELD << endl;
        fout << "FUND " << FUND << endl;
        fout << "ROWS " << ROWS << endl;
        fout << "ALL " << ALL << endl;
    }
    fout.close();

    // 更新全局变量
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
}