#include <iostream>
#include<fstream>
#include<string>
#include <Windows.h>
#include "../head_files/SetArgument.h"
#include "../head_files/ProfileMainpage.h"
using namespace std;

SetArgument::SetArgument() {}
SetArgument::~SetArgument() {}

double center, a, b, w, n;
void SetArgument::show_mainpage()
{
    ProfileMainpage profile;
    string filename = "docs/data.txt";
    ifstream fin;
    fin.open(filename, ios::in);
    if (fin.is_open() == 0) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        system("cls");
        cout << "基准价（元/股）：";
        cin >> center;
        cout << "网格大小（%）：";
        cin >> a;
        cout << "期望收益率（%）：";
        cin >> b;
        cout << "一次买入金额（元）：";
        cin >> w;
        cout << "模拟行数：";
        cin >> n;
        cout << "所有参数已成功设置!\n";
        getDATAfile();
        system("pause");
        profile.show_mainpage();
    }
    else {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "您已经设置过参数：\n";
        show_profile(fin);
        fin.close();
		cout << "\n\t\t\t是否重新设置参数？";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        cout << "\n\n\t\t\t[1] 是";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << "\n\n\t\t\t[2] 否";
		cout << "\n";
        int op;
		cin >> op;
        if (op == 1) {
			remove(filename.c_str());
            show_mainpage();
        }
        else {
			profile.show_mainpage();
        }
    }
    
}

void SetArgument::show_profile(istream & fin) // Need fstream to read the profile from a file
{
    string column;
    while (!fin.eof()) {
        getline(fin, column);  //按行读取，默认遇换行结束.若遇逗号结束，可添加第三个参数','
        cout << column << endl;
    }
}

void SetArgument::getDATAfile() // Waiting for functions to be implemented
{
    ofstream fout;
    fout.open("docs/data.txt", ios::out);   //若不存在该文件，会自动创建
    //ios::out,ios::trunc和不写意义一样，覆盖式；
    //ios::app 追加式
    if (fout.is_open() != false) {
        fout << "基准价（元/股）：" << center << endl;
        fout << "网格大小（%）：" << a << endl;
        fout << "期望收益率（%）：" << b << endl;
        fout << "一次买入金额（元）：" << w << endl;
        fout << "模拟行数：" << n << endl;
    }
    fout.close();
}