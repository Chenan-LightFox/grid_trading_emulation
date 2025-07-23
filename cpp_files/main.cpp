#include <iostream>
#include "../head_files/PrintLine.h"
using namespace std;

void MainMenu()
{
    print_line("\n\n\n\n\t\t\t欢迎使用网格交易助手！"
        "\n\t\t\t------------------------------");
    print_line("\n\n\t\t\t[1] 获取交易策略", green);
    print_line("\n\t\t\t[2] 设置交易参数");
    print_line("\n\t\t\t[3] 退出", red);
    print_line("\n\t\t\t------------------------------\n");
}

int main()
{
    MainMenu();

    return 0;
}