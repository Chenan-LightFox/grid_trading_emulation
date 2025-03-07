#include <iostream>
#include <Windows.h>

void welcome_page()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout << "\n\n\n\n\t\t\tWelcome to Grid Trading Emulator!";
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    std::cout << "\n\t\t[1] Get Advice";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    std::cout << "\t\t[2] Set Trading Profile";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
    std::cout << "\t\t[2]Exit\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void get_start()
{
    int operation = 0;
    std::cin >> operation;
    switch (operation)
    {
    case 1:
        break;
    case 2:
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