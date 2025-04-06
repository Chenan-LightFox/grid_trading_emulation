#include <iostream>
#include <iomanip> 
#include <climits>
#include <Windows.h>
#include "../head_files/GlobalVariables.h"
#include "../head_files/AdviceMainpage.h"
#include "../head_files/MainMenu.h"
#include "../head_files/readtxt.h"
#include "../head_files/grid.h"
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
    ReadTxt readtext("docs\\file.txt"); // 从此开始head才有数据，能够调用，若出错应则停止程序（即head==NULL）
    readtext.read(head);               // 读取数据到链表中
    if (head != NULL)
    { // 测试，之后1要修改成head
        cout << "\n\n\t\t交易建议已生成完毕。";
        cout << "\n\t\t回复 1 获取——————\n";
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

    // cout<<"测试打印file.txt前十组数据：\n";
    // Data *temp = head;
	// // 打印表头
	// cout << setw(12) << "date" << setw(12) << "High" << setw(12) << "Low" << endl;

	// // 遍历链表并打印每个节点的数据
    // int i=0;
	// while (temp != NULL&&i<10)
	// {
	// 	cout << setw(12) << temp->date << setw(12) << temp->High << setw(12) << temp->Low << endl;
	// 	temp = temp->next;
    //     i++;
	// }

    // cout<<"\n\n——————————————————————\n\n";

    buyRecorder();
}

void AdviceMainpage::buyRecorder(){
    int buy_index = 0; // 用来记录买入股票的存量
    vector<Grid::grid> buy,rattle;
    Grid grid;
    grid.divide(center,center,n,a,rattle,b);

    cout<<"测试grid：\n";
    for(int i=0;i<rattle.size();i++){
        grid.print(rattle[i]);
    }
    cout<<"\n\n——————————————————————\n\n";

    int last = INT_MIN,cur = INT_MAX; // 用来记录上一个价格和当前价格所在网格的标号
    Data *temp = head;
    last = grid.getIndex(temp->High,temp->Low,rattle);
    temp = temp->next;
    while(temp!=NULL&&buy_index<10){
        cur = grid.getIndex(temp->High,temp->Low,rattle);
        if(cur < last && cur != INT_MIN) { // 当当前价格低于上一个价格时，说明要买入
            Grid::grid tmp;
	        tmp.center = center;
	        tmp.unit = temp->Low;
	        tmp.i = ++buy_index;
	        tmp.sell = tmp.unit * (1 + (b / 100.0));
            buy.push_back(tmp);  // 买入
        }
        last = cur; // 更新上一个价格
        temp = temp->next; // 遍历
    }

    cout<<"打印前十个买入信息：\n";
    for(int i=0;i<buy.size();i++){
        grid.print(buy[i]);
    }
}