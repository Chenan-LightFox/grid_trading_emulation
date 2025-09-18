#pragma once
#include <conio.h>
#include "../head_files/PrintLine.h"
#include "../head_files/GridCalculating.h"
using namespace std;

///////////////MainMenu///////////////

void main_menu_display(int);
void param_menu_display(int);

void main_menu_choice() {
	bool exit_flag = false;
    char key;
    while (!exit_flag) {
        // 检查是否有按键按下
        if (_kbhit()) {
            // 获取按下的键
            key = _getch();
            switch (key) {
            case '1':
                system("cls");
                main_menu_display(1);
                Sleep(200);
                exit_flag = true;
                break;
            case '2':
                system("cls");
                main_menu_display(2);
                Sleep(200);
                system("cls");
                exit_flag = true;
                param_menu_display(0);
                break;
            case '3':
                system("cls");
                main_menu_display(3);
                Sleep(200);
                exit_flag = true;
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
    }
    else print_line("\n\n\t\t\t[1] 获取交易策略", green);
    if (chooseOn == 2) {
        print_line("\n\t\t\t[2] 设置交易参数", black, white);
    }
    else print_line("\n\t\t\t[2] 设置交易参数", blue);
    if (chooseOn == 3) {
        print_line("\n\t\t\t[3] 退出", black, white);
    }
    else print_line("\n\t\t\t[3] 退出", red);
    print_line("\n\t\t\t------------------------------\n");

    if (chooseOn != 1 && chooseOn != 2 && chooseOn != 3) main_menu_choice();
}

//////////////////////////////////////
//////////////ParamMenu///////////////

void param_menu_choice() {
    bool exit_flag = false;
    char key;
    while (!exit_flag) {
        if (_kbhit()) {
            key = _getch();
            switch (key) {
            case '1':
                system("cls");
                Sleep(200);
                exit_flag = true;
                Grid grid;
                grid.grid_params_input();
                grid.grid_params_save();
                system("pause");
                system("cls");
                param_menu_display(0);
                return;
            case '2':
                Sleep(200);
                exit_flag = true;
                if (remove("./GTE_Data/grid_params.txt") != 0)
                {
                    std::perror("删除失败");
                }
                else
                {
                    std::cout << "删除成功！" << std::endl;
                }
                system("pause");
                system("cls");
                param_menu_display(0);
                return;
            case '3':
                system("cls");
                Sleep(200);
                exit_flag = true;
                main_menu_display(0);
                return;
            }
        }
    }
}

void param_menu_display(int chooseOn) {
    Grid grid;
    print_line("\n\n\n\n\t\t\t交易助手 - 个人信息"
        "\n\t\t\t------------------------------");
    if (chooseOn == 1) {
        print_line("\n\n\t\t\t[1] 设置您的交易信息", black, white);
    }
    else print_line("\n\n\t\t\t[1] 设置您的交易信息", green);
    if (chooseOn == 2) {
        print_line("\n\t\t\t[2] 删除您的交易信息", black, white);
    }
    else print_line("\n\t\t\t[2] 删除您的交易信息", red);
    if (chooseOn == 3) {
        print_line("\n\t\t\t[3] 回到主界面", black, white);
    }
    else print_line("\n\t\t\t[3] 回到主界面", blue);
    print_line("\n\t\t\t------------------------------\n");
    param_menu_choice();
}

//////////////////////////////////////
