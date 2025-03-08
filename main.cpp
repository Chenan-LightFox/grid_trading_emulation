#include <iostream>
#include <Windows.h>
#include "AdviceMainpage.h"
#include "ProfileMainpage.h"

void welcome_page()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "\n\n\n\n\t\t\tWelcome to Grid Trading Emulator!";
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    std::cout << "\n\t\t[1] Get Advice";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "\t\t[2] Set Trading Profile";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::cout << "\t\t[3] Exit\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void get_start()
{
    int operation = 0;
    std::cin >> operation;
    AdviceMainpage advice;
    ProfileMainpage profile;
    switch (operation)
    {
    case 1:
        advice.show_mainpage();
        break;
    case 2:
        profile.show_mainpage();
        break;
    case 3:
        std::cout << "Exiting...";
        break;
    default:
        std::cout << "Invalid input! Please retry.";
        get_start();
        break;
    }
}

int main()
{
    welcome_page();
    get_start();

    return 0;
}