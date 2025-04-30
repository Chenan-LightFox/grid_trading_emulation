#include <iostream>
#include "../head_files/readtxt.h"
#include <iomanip>

// 析构函数，释放资源
ReadTxt::~ReadTxt() {};

// 从文本文件中读取数据并存储到链表中
void ReadTxt::read(Data *&m)
{
	std::ifstream file;
	file.open(textname); // 打开文件
	if (!file.is_open())
	{
		std::cout << "Error: file not found" << std::endl; // 文件未找到
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
			Data *temp = new Data;
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
				Data *m1 = m;
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
		std::cout << "\n\n\t\t文件读取成功。" << std::endl;
	}
	file.close(); // 关闭文件
}

// 打印链表中的数据
void ReadTxt::print(Data *m)
{
	Data *temp = m;
	// 打印表头
	std::cout << std::setw(12) << "date" << std::setw(12) << "Open" << std::setw(12) << "High" << std::setw(12) << "Low" << std::setw(12) << "Close" << std::setw(12) << "Change" << std::setw(12) << "Amplitude" << std::setw(12) << "Volume" << std::setw(12) << "Turnover" << std::endl;

	// 遍历链表并打印每个节点的数据
	while (temp != NULL)
	{
		std::cout << std::setw(12) << temp->date << std::setw(12) << temp->Open << std::setw(12) << temp->High << std::setw(12) << temp->Low << std::setw(12) << temp->Close << std::setw(12) << temp->Change << std::setw(12) << temp->Amplitude << std::setw(12) << temp->Volume << std::setw(12) << temp->Turnover << std::endl;
		temp = temp->next;
	}
}
Data *head = nullptr;
