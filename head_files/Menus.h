#pragma once
#include "../head_files/PrintLine.h"
#include <conio.h>
using namespace std;

void MainMenu()
{
    print_line("\n\n\n\n\t\t\t欢迎使用网格交易助手！"
        "\n\t\t\t------------------------------");
    print_line("\n\n\t\t\t[1] 获取交易策略", green);
    print_line("\n\t\t\t[2] 设置交易参数");
    print_line("\n\t\t\t[3] 退出", red);
    print_line("\n\t\t\t------------------------------\n");
    char key;
    while (true) {
        // 检查是否有按键按下
        if (_kbhit()) {
            // 获取按下的键
            key = _getch();
            switch (key) {
            case '1':
                print_line("\n\t\t\t获取交易策略", green);
                break;
            case '2':
                print_line("\n\t\t\t设置交易参数", green);
                break;
            case '3':
                print_line("\n\t\t\t退出程序", red);
                exit(0);
            }
        }
    }
}