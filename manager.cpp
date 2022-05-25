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

	//��ʼ������Ա��Ϣ
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
	cout << "������Ҫ���ĵ�id" << endl;
	cin >> input;
	flight fli;
	fli.change_information(input);

}

void Manager::show_performance() {
	cout << "1. �鿴�����˵�Ӫҵ��" << endl;
	cout << "2. �鿴���˵�Ӫҵ��" << endl;

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