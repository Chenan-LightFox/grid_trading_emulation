#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <climits>
#include <Windows.h>
#include "../head_files/GlobalVariables.h"
#include "../head_files/SetArgument.h"
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
    // 先判断参数是否设置完全，若未完全，跳转到设置参数界面。
    ifstream fin;
    fin.open("docs/data.txt");
    if (fin.is_open() == false){
        cout<<"您尚未设置基本参数！正在为您跳转。。。\n";
        system("pause");
        SetArgument setarg;
        setarg.show_mainpage();
        return;
    }

    ReadTxt readtext("docs\\file.txt"); // 从此开始head才有数据，能够调用，若出错应则停止程序（即head==NULL）
    readtext.read(head);               // 读取数据到链表中
    if (head != NULL) 
    { 
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
    vector<Grid::grid> buy,rattle,sell;
    Grid grid;
    grid.divide(CENTER,ROWS,GridSize,rattle,YIELD);

    // cout<<"测试grid：\n";
    // for(int i=0;i<rattle.size();i++){
    //     grid.print(rattle[i]);
    // }
    // cout<<"\n\n——————————————————————\n\n";

    double last_low = head->Low;  // 初始化为第一个节点的最低价
    double last_high = head->High;
    Data *temp = head->next;
    while(temp!=NULL && sell.size() < 10) {
        bool should_buy = temp->Low < last_low;  // 当前最低价低于前一个，考虑买入
        bool should_sell = temp->High > last_high; // 当前最高价高于前一个，考虑卖出
        if(should_buy && buy.size() < 10) { 
            Grid::grid s;
            s.date = temp->date;
	        s.unit = temp->Low;  // 以最低价买入
	        s.i = ++buy_index;  // 增加买入记录
	        s.sell = s.unit * (1 + (YIELD / 100.0));
            buy.push_back(s);  // 买入
            grid.sortBYunit(buy); //排序
            last_low = temp->Low;
        }

        else if(should_sell) { // 当当前价格高于上一个价格时，考虑卖出
            for(auto& b : buy) {  // 可以一天卖出多天的股
                if(!b.sold && temp->High >= b.sell) {  // 添加卖出判断
                    Grid::grid s;
                    s.date = temp->date;
                    s.unit = temp->High;  // 以最高价卖出
                    s.i = b.i;           // 保持与买入记录相同的序号
                    s.sell = s.unit * FUND / b.unit;   // 卖出的价格
                    s.sold = true;       // 标记已卖出
                    sell.push_back(s);   // 记录卖出
                    b.sold = true;       // 标记买入记录已卖出
                }
            }
            last_high = temp->High;
        }

        // 更新参考价格为最新值（无论买卖都更新）
        if(!should_buy) last_low = min(last_low, temp->Low);
        if(!should_sell) last_high = max(last_high, temp->High);
        temp = temp->next; // 遍历
    }

    grid.sortBYi(buy);
    grid.sortBYi(sell); 
    //cout<<"sell的size："<<sell.size()<<endl;
    cout<<"打印前十条信息：\n";
    // 优化表头格式
    cout << left 
         << setw(19) << "买入日期" 
         << setw(16) << "买入点数" 
         << setw(19) << "买入金额"
         << setw(19) << "卖出日期" 
         << setw(16) << "卖出点数" 
         << setw(16) << "卖出金额" 
         << setw(16) << "收益"
         << endl;

    for(int i = 0,j = 0; i < buy.size();i++) {
        cout << left 
             << setw(15) << buy[i].date 
             << setw(12) << fixed << setprecision(2) << buy[i].unit 
             << setw(15) << FUND;
            
        while(1) {
            if(j>=sell.size() || sell[j].i>buy[i].i) {
                cout << setw(15) << "N/A" 
                     << setw(12) << "N/A" 
                     << setw(12) << "N/A"
                     << setw(12) << -FUND ; 
                break;
            }
            if(sell[j].i==buy[i].i){
                cout << setw(15) << sell[j].date 
                     << setw(12) << fixed << setprecision(2) << sell[j].unit 
                     << setw(12) << sell[j].sell
                     << setw(12) << sell[j].sell - FUND;
                j++;
                break;
            }
            else if(sell[j].i<buy[i].i){
                j++;
            }
        }
        cout<<endl;
    }
}