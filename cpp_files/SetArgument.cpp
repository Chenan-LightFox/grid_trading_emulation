#include <iostream>
#include<fstream>
#include<string>
#include <Windows.h>
#include "../head_files/SetArgument.h"
#include "../head_files/ProfileMainpage.h"
using namespace std;

SetArgument::SetArgument() {}
SetArgument::~SetArgument() {}

double center,a,b,w,n;
void SetArgument::show_mainpage()
{ 
    ProfileMainpage profile;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    std::cout << "基准价（元/股）：";
	cin>>center;
    std::cout << "网格大小（%）：";
    cin>>a;
    std::cout << "期望收益率（%）：";
    cin>>b;
    std::cout << "一次买入金额（元）：";
    cin>>w;
	std::cout << "模拟行数：";
    cin>>n;
    std::cout << "所有参数已成功设置!\n";
    getDATAfile();
	system("pause");
    profile.show_mainpage();
}

void SetArgument::show_profile(string Argument) // Need fstream to read the profile from a file
{
    ifstream fin;
    fin.open("docs/data.txt", ios::in);
    if (!fin) {
        cerr << "无法打开文件 docs/data.txt" << endl;
        return;
    }

    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

void SetArgument::getDATAfile() 
{
    ofstream fout;
    fout.open("docs/data.txt", ios::out); // 若不存在该文件，会自动创建
    if (!fout) {
        cerr << "无法打开文件 docs/data.txt" << endl;
        return;
    }

    if (fout.is_open()) {
        fout << "基准价（元/股）：" << center << endl;
        fout << "网格大小（%）：" << a << endl;
        fout << "期望收益率（%）：" << b << endl;
        fout << "一次买入金额（元）：" << w << endl;
        fout << "模拟行数：" << n << endl;
    } else {
        cerr << "文件 docs/data.txt 打开失败" << endl;
    }
    fout.close();
}