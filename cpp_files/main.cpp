#include <iostream>
#include <Windows.h>
#include "../head_files/MainMenu.h"
#include "../head_files/AdviceMainpage.h"
#include "../head_files/ProfileMainpage.h"
#include "../head_files/SetArgument.h"

int main() // main function
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    //↑解决中文乱码问题
    MainMenu mainmenu;
    mainmenu.show();
    mainmenu.get_start();
    system("pause");
    return 0;
}
