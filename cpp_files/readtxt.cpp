#include <iostream>
#include"../head_files/readtxt.h"
#include<iomanip>
ReadTxt::~ReadTxt() {};
void ReadTxt::read(Data* &m) {
	std::ifstream file;
	file.open(textname);
	if (!file.is_open()) {
		std::cout << "Error: file not found" << std::endl;
	}
	else {
		std::string date;
		std::string t="abc";
		std::string t1= "abc";
		double Open;
		double High;
		double Low;
		double Close;
		double Change;
		double Amplitude;
		double Volume;
		double Turnover;
		while (std::getline(file,t)) {
			if (t[0]>57||t[0]<48) {
				continue;
			}
			Data* temp = new Data;
			std::istringstream iss(t);
			iss >> date >> t1 >> t1 >> t1 >> t1 >> t1 >> t1 >> t1 >> t1 >> Open >> High >> Low >> Close >> Change >> Amplitude >> Volume >> Turnover;
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
			if (head==NULL)head = temp;
			else {
				Data* m1 = m;
				while (1) {
					if (m1->next == NULL)break;
					m1 = m1->next;
				}
				m1->next = temp;
			}
		}
	}
	if (file.is_open()) {
		std::cout << "finish!" << std::endl;
	}
	file.close();

}
void ReadTxt::print(Data* m) {
	Data* temp = m;
	std::cout << std::setw(12) << "date"  << std::setw(12) << "Open" << std::setw(12) << "High" << std::setw(12) << "Low" << std::setw(12) << "Close" << std::setw(12) << "Change" << std::setw(12) << "Amplitude"<<std::setw(12) << "Volume" << std::setw(12) << "Turnover" << std::endl;
	while (temp != NULL) {
		std::cout << std:: setw(12) << temp->date  << std::setw(12) << temp->Open << std::setw(12) << temp->High << std::setw(12) << temp->Low << std::setw(12) << temp->Close << std::setw(12) << temp->Change << std::setw(12) << temp->Amplitude << std::setw(12) << temp->Volume << std::setw(12) << temp->Turnover << std::endl;
		temp = temp->next;
	}
}
/*int main() {
	std::string a = "../readtxt/data.txt";
	ReadTxt readtext(a);
	readtext.read(head);
	readtext.print(head);
	readtext.print(head);
	return 0;
}*/