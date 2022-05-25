#include"manager.h"
#include "globalFile.h"
#include"iostream"
#include"fstream"
#include "flight.h"
#include "aircraft.h"
#include "turnover.h"

Manager::Manager() {

}

Manager::~Manager() {};

Manager::Manager(int id,string name, string pwd) {

	//初始化管理员信息
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Manager::operMenu() {
	cout << endl;
	cout << "Welcome to Airways Management System --- manager" << endl;
	cout << "Select the function you will perform" << endl;
	cout << "0.Exit to main" << endl;
	cout << "1.Show aircraft amont" << endl;
	cout << "2.Show all flight" << endl;
	cout << "3.Modify the flight" << endl;
	cout << "4.Staff Performance" << endl;

	cout << endl;
}

void Manager::show_air_amount() {
	aircraft air;
	air.amount_query();
};

void Manager::show_all_flight() {
	flight fli;
	fli.show_allflight();
};

void Manager::change_Flight() {

	string input;
	cout << "请输入要更改的id" << endl;
	cin >> input;
	flight fli;
	fli.change_information(input);

}

void Manager::show_performance() {
	cout << "1. 查看所有人的营业额" << endl;
	cout << "2. 查看个人的营业额" << endl;

	int select;
	cin >> select;
	Turnover tur;
	string id;

	if (select == 1) {
		tur.show_allTurnover();
	}
	else if (select == 2) {
		cout << "Please input the ticket id:" << endl;
		cin >> id;
		tur.show_turnover(id);
	}
}