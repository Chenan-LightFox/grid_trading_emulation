#include "../head_files/BuyAndSell.h"
#include "../head_files/PrintLine.h"
#include"../head_files/GetGrid.h"
#include <Windows.h>


// 析构函数，释放资源
AcceptData::~AcceptData() {
    while (head != NULL) {
	    Data* temp = head;
	    head = head->next;
	    delete temp;
    }
}

// 从文本文件中读取数据并存储到链表中
void AcceptData::read(Data*& m)
{
	std::ifstream file;
	file.open(textname); // 打开文件
	if (!file.is_open())
	{
		print_line("错误：未找到文件。", red); // 文件未找到
	}
	else
	{
		// 定义变量以存储文件中的数据
		std::string date;
		std::string t = "abc";
		std::string t1 = "abc";
		double Open;
		double High;
		double Low;
		double Close;
		double Change;
		double Amplitude;
		double Volume;
		double Turnover;

		// 按行读取文件内容
		while (std::getline(file, t))
		{
			// 跳过非数字开头的行
			if (t[0] > 57 || t[0] < 48)
			{
				continue;
			}
			// 创建新节点以存储数据
			Data* temp = new Data;
			std::istringstream iss(t); // 使用字符串流解析数据
			iss >> date >> t1 >> t1 >> t1 >> t1 >> t1 >> t1 >> t1 >> t1 >> Open >> High >> Low >> Close >> Change >> Amplitude >> Volume >> Turnover;
			// 将解析的数据存储到节点中
			temp->date = date;
			temp->Open = Open;
			temp->High = High;
			temp->Low = Low;
			temp->Close = Close;
			temp->Change = Change;
			temp->Amplitude = Amplitude;
			temp->Volume = Volume;
			temp->Turnover = Turnover;
			temp->next = NULL;

			// 将节点添加到链表中

			if (head == NULL)
				head = temp;
			else
			{
				Data* m1 = m;
				while (1)
				{
					if (m1->next == NULL)
						break;
					m1 = m1->next;
				}
				m1->next = temp;
			}
		}
	}
	if (file.is_open())
	{
		print_line("\n\n\t\t文件读取成功。");
	}
	file.close(); // 关闭文件
}

// 打印链表中的数据
void AcceptData::print(Data* m)
{
	Data* temp = m;
	// 打印表头
	std::cout << std::setw(12) << "date" << std::setw(12) << "Open" << std::setw(12) << "High" << std::setw(12) << "Low" << std::setw(12) << "Close" << std::setw(12) << "Change" << std::setw(12) << "Amplitude" << std::setw(12) << "Volume" << std::setw(12) << "Turnover" << std::endl;

	// 遍历链表并打印每个节点的数据
	while (temp != NULL)
	{
		std::cout << std::setw(12) << temp->date << std::setw(12) << temp->Open << std::setw(12) << temp->High << std::setw(12) << temp->Low << std::setw(12) << temp->Close << std::setw(12) << temp->Change << std::setw(12) << temp->Amplitude << std::setw(12) << temp->Volume << std::setw(12) << temp->Turnover << std::endl;
		temp = temp->next;
	}
}
Data* head = NULL;


void start_buy_and_sell(Grid user_grid) {
	//获取中正指数,可改
    int raise[2]={0,0};//趋势发生改变时记录，-1表示下跌，1表示上涨，0表示持平,但是由于测试是用到的数据纯线性，无需考虑持平时误买误卖
    AcceptData accept_data("./GTE_Data/data.txt");
    accept_data.read(head);


	//生成网格数据
	int size=user_grid.gridLine;
	
	std::vector<grid> gridexcel = get_grid(user_grid);
	std::vector<int> numexcel;//持有股数

	for(int i = 0; i < size; i++){
		numexcel.push_back(0);
	}

	print_line("数据已导入，开始模拟买卖。");
    Data* temp = head;
	//线性模拟买卖,每天每个网格最多一次买卖，后续改为实时模拟
    while (temp != NULL) {
        raise[0] = raise[1]; // 保存上一个状态
        if (temp->Open - temp->Close > 0) {
            for (int i = size - 1; i >= 0; i--) {	//上升段     
                if(gridexcel[i].buy > temp->Open){
					if(temp->High > gridexcel[i].buy){
						buy(user_grid, i, numexcel); 
					}
					else{
						break;
					}
				}         
            }
            for (int i = 0; i < size; i++) {//下降段
                if(gridexcel[i].sell < temp->High){
					if(gridexcel[i].sell > temp->Low){
						sell(user_grid, i, numexcel); 
					}
					else{
						break;
					}
					
				}
            }
            for (int i = size - 1; i >= 0; i--) {//上升段
                if(gridexcel[i].buy > temp->Low){
					if(temp->Close > gridexcel[i].buy){
						buy(user_grid, i, numexcel); 
					}
					else{
						break;
					}
				}         
            }
        } 
        else {
            for (int i = 0; i < size; i++) {//下降段
                if(gridexcel[i].sell < temp->Open){
					if(gridexcel[i].sell > temp->Low){
						sell(user_grid, i, numexcel); 
					}
					else{
						break;
					}
					
				}
            }
			for (int i = size - 1; i >= 0; i--) {//上升段
                if(gridexcel[i].buy > temp->Low){
					if(temp->High > gridexcel[i].buy){
						buy(user_grid, i, numexcel); 
					}
					else{
						break;
					}
				}         
            }
			for (int i = 0; i < size; i++) {//下降段
                if(gridexcel[i].sell < temp->High){
					if(gridexcel[i].sell > temp->Close){
						sell(user_grid, i, numexcel); 
					}
					else{
						break;
					}
					
				}
            }
        } 
		temp = temp->next;
    }
	print_line("买卖模拟完成。交易日志产生");
}

void buy(Grid &a, int number, std::vector<int> numexcel){ 
	// 买入股数,直接用用户输入的数据，可能股数不对
	int numOfBuy = a.buyInAmounts/gridexcel[number].buy;
    std::ofstream trading_log("./GTE_Data/trading_log.txt", std::ios::app);

    if(a.properity - numOfBuy * gridexcel[number].buy >= 0){
        a.properity -= numOfBuy* gridexcel[number].buy;
        numexcel[number] += numOfBuy;
        trading_log << "于某时以" << gridexcel[number].buy << "每股买入" << numOfBuy << "股" << std::endl << "－" << numOfBuy * gridexcel[number].buy << "元" << "\n\n";
    }
    else {
        trading_log << "于某时资金不足无法买入" << "\n\n";
    }

    trading_log.close();
}

 void sell(Grid &a, int number, std::vector<int> numexcel) {
    std::ofstream trading_log("./GTE_Data/trading_log.txt", std::ios::app);

    if(numexcel[number] > 0) {
        a.properity += numexcel[number] * gridexcel[number].sell;
        trading_log << "于某时" << gridexcel[number].sell << "卖出" << numexcel[number] << "股" << std::endl << "+" << gridexcel[number].sell * numexcel[number] << "元" << "\n\n";
        numexcel[number] = 0; 
    } else {
        std::cout << "于某时没有持有股票，无法卖出。" << "\n\n";
    }

    trading_log.close();
 }