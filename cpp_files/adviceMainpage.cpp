#include <iostream>
#include <Windows.h>
#include "../head_files/GlobalVariables.h"
#include "../head_files/AdviceMainpage.h"
#include "../head_files/MainMenu.h"
#include "../head_files/readtxt.h"
using namespace std;

AdviceMainpage::AdviceMainpage() {}
AdviceMainpage::~AdviceMainpage() {}

inline void back_to_mainmenu()
{
    system("pause");
    system("cls");
    MainMenu mainmenu;
    mainmenu.show();
    mainmenu.get_start();
}

void AdviceMainpage::show_mainpage()
{
    ReadTxt readtext("docs/file.txt"); // 从此开始head才有数据，能够调用，若出错应则停止程序（即head==NULL）
    readtext.read(head);               // 读取数据到链表中
    if (1)
    { // 测试，之后1要修改成head
        cout << "\n\n\t\t交易建议已生成完毕。";
        cout << "\n\t\t回复 1 获取——————";
        int operation;
        cin >> operation;
        if (operation == 1)
        {
            show(); // 打印链表中的数据
        }
        else
        {
            cout << "未知的命令，程序正在退出...";
        }
        back_to_mainmenu();
    }
    else
    {
        cout << "未检测到所需文件。\n";
        cout << "程序正在退出...\n";
        back_to_mainmenu();
    }
}

void AdviceMainpage::show()
{ // 测试，之后要在算法之后把日期、买入、卖出打印出来
    cout << center << " " << a << " " << b << " " << w << endl;
}