#include <iostream>
#include <Windows.h>
#include "../head_files/ProfileMainpage.h"

ProfileMainpage::ProfileMainpage() {}
ProfileMainpage::~ProfileMainpage() {}

void ProfileMainpage::show_mainpage()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    std::cout << "\n\n\n\n\t\t\tTrading Profile";
    std::cout << "\n\t\t\t---------------";
    std::cout << "\n\n\t\t\t[1] Set your trading profile.";
    std::cout << "\n\n\t\t\t[2] View your trading profile.";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::cout << "\n\n\t\t\t[3] Delete your trading profile.";
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    std::cout << "\n\n\t\t\t[4] Back to main menu.\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}