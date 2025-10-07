#pragma once
#include <conio.h>
#include "../head_files/PrintLine.h"
#include "../head_files/GridCalculating.h"
#include "../head_files/BuyAndSell.h"
using namespace std;

///////////////MainMenu///////////////

void main_menu_display(int);
void param_menu_display(int);
void BuyAndSell_display();

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
                system("cls");
                exit_flag = true;
                BuyAndSell_display();
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
        "\n\t\t\t------------------------------\n");
    if (chooseOn == 1) {
        print_line("\n\n\t\t\t[1] 获取交易策略\n", black, white);
    }
    else print_line("\n\n\t\t\t[1] 获取交易策略\n", green);
    if (chooseOn == 2) {
        print_line("\n\t\t\t[2] 设置交易参数\n", black, white);
    }
    else print_line("\n\t\t\t[2] 设置交易参数\n", blue);
    if (chooseOn == 3) {
        print_line("\n\t\t\t[3] 退出\n", black, white);
    }
    else print_line("\n\t\t\t[3] 退出\n", red);
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
                    print_line("删除失败！\n", red);
                }
                else
                {
                    print_line("删除成功！\n", green);
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
        "\n\t\t\t------------------------------\n");
    if (chooseOn == 1) {
        print_line("\n\n\t\t\t[1] 设置您的交易信息\n", black, white);
    }
    else print_line("\n\n\t\t\t[1] 设置您的交易信息\n", green);
    if (chooseOn == 2) {
        print_line("\n\t\t\t[2] 删除您的交易信息\n", black, white);
    }
    else print_line("\n\t\t\t[2] 删除您的交易信息\n", red);
    if (chooseOn == 3) {
        print_line("\n\t\t\t[3] 回到主界面\n", black, white);
    }
    else print_line("\n\t\t\t[3] 回到主界面\n", blue);
    print_line("\n\t\t\t------------------------------\n");
    grid.grid_params_read();
    param_menu_choice();
}

//////////////////////////////////////

void BuyAndSell_display() {
	Grid grid;
	grid.grid_params_read();
    system("cls");
	start_buy_and_sell(grid);
}