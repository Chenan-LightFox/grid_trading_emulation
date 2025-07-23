#pragma once
#include "../head_files/PrintLine.h"
#include <conio.h>
using namespace std;

void MainMenu(int chooseOn)
{
    print_line("\n\n\n\n\t\t\t欢迎使用网格交易助手！"
        "\n\t\t\t------------------------------");
    if(chooseOn == 1) print_line("\n\n\t\t\t[1] 获取交易策略", black, white);
    else print_line("\n\n\t\t\t[1] 获取交易策略", green);
    if (chooseOn == 2) print_line("\n\t\t\t[2] 设置交易参数", black, white);
    else print_line("\n\t\t\t[2] 设置交易参数", blue);
    if (chooseOn == 3) {
        print_line("\n\t\t\t[3] 退出", black, white);
        print_line("\n\t\t\t------------------------------\n");
        exit(0);
    }
    else print_line("\n\t\t\t[3] 退出", red);
    print_line("\n\t\t\t------------------------------\n");
    char key;
    while (true) {
        // 检查是否有按键按下
        if (_kbhit()) {
            // 获取按下的键
            key = _getch();
            switch (key) {
            case '1':
                system("cls");
                MainMenu(1);
                Sleep(1000);
                // TODO: Add func there
                break;
            case '2':
                system("cls");
                MainMenu(2);
                Sleep(1000);
                // TODO: Add func there
                break;
            case '3':
                system("cls");
                MainMenu(3);
            }
        }
    }
}