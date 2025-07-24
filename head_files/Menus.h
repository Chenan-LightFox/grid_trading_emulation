#pragma once
#include "../head_files/PrintLine.h"
#include <conio.h>
using namespace std;

///////////////MainMenu///////////////

void main_menu_display(int);
void param_menu_display();

void main_menu_choice() {
    char key;
    while (true) {
        // 检查是否有按键按下
        if (_kbhit()) {
            // 获取按下的键
            key = _getch();
            switch (key) {
            case '1':
                system("cls");
                main_menu_display(1);
                Sleep(500);
                break;
            case '2':
                system("cls");
                main_menu_display(2);
                Sleep(500);
                param_menu_display();
                break;
            case '3':
                system("cls");
                main_menu_display(3);
                Sleep(500);
                exit(0);
            }
        }
    }
}

void main_menu_display(int chooseOn)
{
    print_line("\n\n\n\n\t\t\t欢迎使用网格交易助手！"
        "\n\t\t\t------------------------------");
    if (chooseOn == 1) {
        print_line("\n\n\t\t\t[1] 获取交易策略", black, white);
    } else print_line("\n\n\t\t\t[1] 获取交易策略", green);
    if (chooseOn == 2) {
        print_line("\n\t\t\t[2] 设置交易参数", black, white);
    } else print_line("\n\t\t\t[2] 设置交易参数", blue);
    if (chooseOn == 3) {
        print_line("\n\t\t\t[3] 退出", black, white);
    } else print_line("\n\t\t\t[3] 退出", red);
    print_line("\n\t\t\t------------------------------\n");

    if (chooseOn != 1 && chooseOn != 2 && chooseOn != 3) main_menu_choice();
}

//////////////////////////////////////
//////////////ParamMenu///////////////

void param_menu_display() {

}

//////////////////////////////////////