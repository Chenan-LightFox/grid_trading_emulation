#include<iostream>
#include<fstream>	
#include<sstream>
#include<string>
struct Data {
	std::string date;
	double Open;
	double High;
	double Low;
	double Close;
	double Change;
	double Amplitude;
	double Volume;
	double Turnover;
	Data* next;
}*head=NULL;
class ReadTxt
{
public:
	ReadTxt(std::string a) :
	textname(a){};
	~ReadTxt();
	void read(Data* &m);
	void print(Data* m);
private:
	std::string textname;
};

