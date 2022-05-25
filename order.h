#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Order {

public:

	string order_id;
	int flight_id;
	int customer_id;
	int choose_row;
	int choose_column;
	string status = "checking";
	

	Order();
	~Order();

	Order(string o_id, int f_id, int c_id, int row, int column);

	void show_myOrder(int customer_id);

	void show_allOrder();

	string gene_order_id(int f_id, int c_id, int row, int column);

	string gene_order_id_by_mid(int m_id);

	void change_by_id(string id);

	string motify_order_status(string id);

	string flightId_by_orderId(string order_id);


};