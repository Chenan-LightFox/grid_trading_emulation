#include <iostream>
#include <Windows.h>
#include "../head_files/SetArgument.h"
#include "../head_files/ProfileMainpage.h"

SetArgument::SetArgument() {}
SetArgument::~SetArgument() {}

void SetArgument::show_mainpage()
{
    ProfileMainpage profile;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    std::cout << "基准价（元/股）：";
	set();
    std::cout << "网格大小（%）：";
    set();
    std::cout << "期望收益率（%）：";
    set();
    std::cout << "一次买入金额（元）：";
    set();
	std::cout << "模拟行数：";
    set();
    show_profile("测试");
	system("pause");
    profile.show_mainpage();
}

void SetArgument::show_profile(string Argument) // Need fstream to read the profile from a file
{
    std::cout << "所有参数已成功设置!\n";
}

void SetArgument::set() // Waiting for functions to be implemented
{
    double n;
    cin >> n;
	cout << "设置成功！" << endl;
}