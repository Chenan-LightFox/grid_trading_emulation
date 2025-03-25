#include <iostream>
#include <Windows.h>
#include "../head_files/MainMenu.h"
#include "../head_files/AdviceMainpage.h"
#include "../head_files/ProfileMainpage.h"
#include "../head_files/SetArgument.h"

int main() // main function
{
    MainMenu mainmenu;
    mainmenu.show();
    mainmenu.get_start();
    system("pause");
    return 0;
}