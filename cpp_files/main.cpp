#include<iostream>
#include "PrintLine.h"
using namespace std;

void MainMenu() {
    cout << "\n\n\n\n\t\t\t欢迎使用股票交易助手！";
    cout << "\n\t\t\t------------------------------";
    print_line("\n\n\t\t\t[1] 获得交易建议", green);
    print_line("\n\t\t\t[2] 设置个人信息", white);
    print_line("\n\t\t\t[3] 退出", red);
    cout << "\n\t\t\t------------------------------\n";
}

int main() {
    MainMenu();

	return 0;
}