#include <iostream>
#include "PrintLine.h"
using namespace std;

void MainMenu()
{
    cout << "\n\n\n\n\t\t\t��ӭʹ�ù�Ʊ�������֣�";
    cout << "\n\t\t\t------------------------------";
    print_line("\n\n\t\t\t[1] ��ý��׽���", green);
    print_line("\n\t\t\t[2] ���ø�����Ϣ", white);
    print_line("\n\t\t\t[3] �˳�", red);
    cout << "\n\t\t\t------------------------------\n";
}

int main()
{
    MainMenu();

    return 0;
}