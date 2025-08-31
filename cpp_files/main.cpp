#include <iostream>
#include <cstdlib>
#include "../head_files/Menus.h"

int main()
{
	system("chcp 65001"); // 设置控制台为UTF-8编码，支持中文显示
    //自动创建文件夹 
    if (system("cd GTE_Data") == 1) { // 检查GTE_Data文件夹是否存在
        system("cls");
        system("mkdir GTE_Data"); // 创建GTE_Data文件夹
        print_line("GTE_Data文件夹不存在，已为您创建！\n");
        system("pause");
    }
    else system("cd ../");

    main_menu_display(0);

    return 0;
}