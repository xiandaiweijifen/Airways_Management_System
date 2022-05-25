#include"customer.h"
#include"iostream"
#include"fstream"
#include "globalFile.h"
#include "flight.h"
#include "order.h"
#include "administrator.h"

Customer::Customer(){

}

Customer::~Customer() {};

Customer::Customer(int id, string name, string pwd) {

	//初始化属性
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;


}

void Customer::operMenu() {
	cout << endl;
	cout << "Welcome to Airways Management System --- customer" << endl;
	cout << "Select the function you will perform" << endl;
	cout << "0.Exit to main" << endl;
	cout << "1.Book flight" << endl;
	cout << "2.My order" << endl;
	cout << "3.Show all order" << endl;
	cout << "4.Cancel my order" << endl;
	cout << endl;
}

void Customer::applyFlight() {

	string order_id;
	string choose_id;
	int choose_seat_column;
	int choose_seat_row;
	string choose_type;
	string status="checking";

	flight fli;
	Order ord;

	fli.show_allflight();

	cout << "Please input the id of the flight you want to book: " << endl;
	cin >> choose_id;

	fli.show__flight_info_id(choose_id);


	choose_type = fli.show_aircraft_of_flight(choose_id);

	fli.show_remain_seat_table(choose_id);

	if (choose_type=="P62") {

		cout << "Please choose the seat (6,2): " << endl;
		cout << "First choose the row: " << endl;
		cin >> choose_seat_row;
		cout << "Then choose the column: " << endl;
		cin >> choose_seat_column;


	}
	else {
		cout << "Please choose the seat (12,4):" << endl;
		cout << "First choose the row: " << endl;
		cin >> choose_seat_row;
		cout << "Then choose the column: " << endl;
		cin >> choose_seat_column;
	
	}
	
//	ofstream fout("order.txt");
//	fout << choose_id << "\t" << m_Id << "\t" << choose_seat_row << "\t" << choose_seat_column << endl;
//	fout.close();

	order_id = ord.gene_order_id(stoi(choose_id),m_Id,choose_seat_row,choose_seat_column);

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs <<order_id<<"\t"<< choose_id << "\t" << m_Id << "\t" << choose_seat_row << "\t" << choose_seat_column <<"\t" << status << endl;

	int id;
	string name;
	string pwd;

	fli.change_by_id(choose_id);

	cout << "预约成功，审核中" << endl;
	
	ofs.close();

}

void Customer::showMyFlight() {

	Order ord;

	ord.show_myOrder(m_Id);

}

void Customer::showAllOrder() {

	Order ord;
	ord.show_allOrder();
}

void Customer::cancelOrder() {
	
	Order ord;

	Administrator adi;

	adi.delLine(ORDER_FILE, stoi(ord.gene_order_id_by_mid(m_Id))); //使用自带函数stoi实现string转int

	cout << "Clear success" << endl;

}