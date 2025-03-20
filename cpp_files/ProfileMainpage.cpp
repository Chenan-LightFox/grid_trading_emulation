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
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::cout << "\n\n\t\t\t[2] Delete your trading profile.";
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    std::cout << "\n\n\t\t\t[3] Back to main menu.\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    profile_get_operation();
}

void ProfileMainpage::profile_get_operation() // Waiting for functions to be implemented
{
    int operation = 0;
    std::cin >> operation;
    switch (operation)
    {
    case 1:
        std::cout << "Setting your trading profile...";
        break;
    case 2:
        std::cout << "Deleting your trading profile...";
        break;
    case 3:
        std::cout << "Back to main menu...";
        break;
    default:
        std::cout << "Invalid input! Exiting...";
        break;
    }
}