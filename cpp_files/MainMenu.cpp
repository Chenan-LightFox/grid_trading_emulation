#include <iostream>
#include <Windows.h>
#include "../head_files/MainMenu.h"
#include "../head_files/AdviceMainpage.h"
#include "../head_files/ProfileMainpage.h"
#include "../head_files/SetArgument.h"

MainMenu::MainMenu() {}
MainMenu::~MainMenu() {}

void MainMenu::show()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "\n\n\n\n\t\t\t欢迎使用股票交易助手！";
    std::cout << "\n\t\t\t----------------------------------";
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    std::cout << "\n\n\t\t\t[1] 获得交易建议";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "\n\n\t\t\t[2] 设置个人信息";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::cout << "\n\n\t\t\t[3] 退出\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void MainMenu::get_start()
{
    int operation = 0;
    std::cin >> operation;
    AdviceMainpage advice;
    ProfileMainpage profile;
    switch (operation)
    {
    case 1:
        advice.show_mainpage();
        break;
    case 2:
        profile.show_mainpage();
        break;
    case 3:
        std::cout << "程序正在退出...";
        break;
    default:
        std::cout << "未知的命令，程序正在退出...";
        break;
    }
}