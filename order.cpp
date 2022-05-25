#include"order.h"
#include<fstream>
#include<string>
#include "administrator.h"
#include "globalFile.h"

Order::Order(){};

Order::~Order() {};

Order::Order(string o_id, int f_id, int c_id, int row, int column) {

	order_id = o_id;
	flight_id = f_id;
	customer_id = c_id;
	choose_row = row;
	choose_column = column;

};


void Order::show_myOrder(int c_id){

	int flag = 0;

	cout << endl;
	cout << "以下是你的订单信息： " << endl;
	cout << endl;

	ifstream fin("order.txt");

	while (fin.eof() == false) {
		fin >>order_id >> flight_id >> customer_id >> choose_row >> choose_column;
		if (customer_id == c_id) {

			cout << "Order id: " << order_id << endl;
			cout << endl;
			cout << "Flight id: " << flight_id << endl;
			cout << endl;
			cout << "Customer id: " << customer_id << endl;
			cout << endl;
			cout << "Choose row: " << choose_row << endl;
			cout << endl;
			cout << "Choose column: " << choose_column << endl;
			cout << endl;

			flag = 1;
		
			fin.get();                             //读取最后的回车符，防止重复读取最后一行
			if (fin.peek() == '\n') break;
		}	
	}

	if (flag == 0) {
		cout << "Flight not found!";
	}

	fin.close();
};

void Order::show_allOrder() {

	ifstream fin("order.txt");

	cout << "订单信息如下：" << endl;
	cout << endl;

	while (fin.eof() == false) {


		fin >> order_id >> flight_id >> customer_id >> choose_row >> choose_column>>status;
		cout <<"order_id: "<<order_id<<" " << "flight_id: " << flight_id << " " << "customer_id: " << customer_id << " " << "choose_row: " << choose_row << " " << "choose_column: " << choose_column <<" "<<"status: "<<status<< endl;
		cout << endl;
		
		fin.get();
		if (fin.peek() == '\n') break;
	}

	fin.close();

};

string Order::gene_order_id(int f_id, int c_id, int row, int column) {

	string or_id;

	or_id = to_string(f_id) + to_string(c_id) + to_string(row) + to_string(column);

	return or_id;

};

string Order::gene_order_id_by_mid(int mid) {

	ifstream fin("order.txt");

	while (fin.eof() == false) {
		fin >> order_id >> flight_id >> customer_id >> choose_row >> choose_column;
		if (customer_id == mid) {

			return order_id;

			break;
		}
	}
}

string charToStr(char* contentChar){

	string tempStr;
	for (int i = 0; contentChar[i] != '\0';i++) {
		tempStr += contentChar[i];
	
	}
	return tempStr;
}

void modifyContentInFile(char* filName, int lineNum, char * content) {


}

void Order::change_by_id(string id) {

		string o_id;
		int f_id;
		int c_id;
		int row;
		int column;

	ifstream fin("order.txt");

	while (fin.eof() == false) {

		fin >> order_id >> flight_id >> customer_id >> choose_row >> choose_column ;
		if (order_id == id) {

			o_id = order_id;
			f_id = flight_id;
			c_id = customer_id;
			row = choose_row;
			column=choose_column;

			Administrator adi;

			adi.delLine("order.txt", stoi(id)); //使用自带函数stoi实现string转int

			fin.get();                             //读取最后的回车符，防止重复读取最后一行
			if (fin.peek() == '\n') break;

		}
	}
	fin.close();


}

string Order::motify_order_status(string id) {
	ifstream fin(ORDER_FILE);

	string choose;
	Administrator admin;
	string pass_status = "Pass";
	string not_pass_status = "Not pass";

	while (fin.eof() == false) {
		fin >> order_id >> flight_id >> customer_id >> choose_row >> choose_column >> status;

		if (order_id == id) {
			cout << "Please enter the status you want to change to:" << endl;
			cout << "0. Exit" << endl;
			cout << "1. Paas" << endl;
			cout << "2. Not pass" << endl;

			cin >> choose;
			if (choose == "1") {
				admin.delLine(ORDER_FILE, stoi(id));
				ofstream ofs;
				ofs.open(ORDER_FILE, ios::out | ios::app);
				ofs << order_id << " " << flight_id << " " << customer_id << " " << choose_row << " " << choose_column << " " << pass_status;
				ofs.close();
				cout << "Change successful!" << endl;
				break;
			}

			else if (choose == "2") {
				admin.delLine(ORDER_FILE, stoi(id));
				ofstream ofs2;
				ofs2.open(ORDER_FILE, ios::out | ios::app);
				ofs2 << order_id << " " << flight_id << " " << customer_id << " " << choose_row << " " << choose_column << " " << not_pass_status;
				ofs2.close();
				cout << "Change successful!" << endl;
				break;
			}
			else if (choose == "0") {
				cout << "Welcome to use again!" << endl;
				break;
			}
			else {
				cout << "Inapproper input, please enter again; " << endl;
				system("pause");
				system("cls");
			}
			
		}
		else {
			cout << "Abnormal id, please input again." << endl;
			system("pause");
			system("cls");
		}
	}
	fin.close();
	return choose;
}

string Order::flightId_by_orderId(string order_Id) {
	ifstream fin(ORDER_FILE);
	string flight_Id;

	while (fin.eof() == false) {
		fin >> order_id >> flight_id >> customer_id >> choose_row >> choose_column >> status;
		if (order_Id == order_id) {
			flight_Id = flight_id;
			break;
		}

	}

	fin.close();
	return flight_Id;
}