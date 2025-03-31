#include <iostream>
#include <Windows.h>
#include"../head_files/MainMenu.h"
#include "../head_files/ProfileMainpage.h"
#include "../head_files/SetArgument.h"

ProfileMainpage::ProfileMainpage() {}
ProfileMainpage::~ProfileMainpage() {}
std::string filename = "docs/data.txt";

void ProfileMainpage::show_mainpage()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    std::cout << "\n\n\n\n\t\t\t交易助手 - 个人信息";
    std::cout << "\n\t\t\t---------------";
    std::cout << "\n\n\t\t\t[1] 设置您的交易信息";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::cout << "\n\n\t\t\t[2] 删除您的交易信息";
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    std::cout << "\n\n\t\t\t[3] 回到主界面\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "\n\t\t\t---------------\n";
    show_profile();
    profile_get_operation();
}

void ProfileMainpage::show_profile() // Need fstream to read the profile from a file
{
    std::cout << "The profile showing function is not implemented yet!\n";
}

void ProfileMainpage::profile_get_operation() // Waiting for functions to be implemented
{
    int operation = 0;
    std::cin >> operation;
    SetArgument setargument;
    MainMenu mainmenu;
    switch (operation)
    {
    case 1:
        setargument.show_mainpage();
        break;
    case 2:
        if (remove(filename.c_str()) != 0) {
            std::perror("删除失败");
        } 
        else {
            std::cout << "删除成功！" << std::endl;
        }
        system("pause");
        show_mainpage();
        break;
    case 3:
        mainmenu.show();
        mainmenu.get_start();
        break;
    default:
        std::cout << "未知的命令，程序正在退出...";
        break;
    }
}
