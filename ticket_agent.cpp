#include"ticket_agent.h"
#include"order.h"
#include<string>
#include"globalFile.h"
#include "flight.h"
#include "turnover.h"

Ticket_agent::Ticket_agent() {

};

Ticket_agent::~Ticket_agent() {};

Ticket_agent::Ticket_agent(int Ti_Id, string name, string pwd) {
	this->m_Id = Ti_Id;
	this->m_Name = name;
	this->m_Pwd = pwd;
};

void Ticket_agent::operMenu() {

	cout << endl;
	cout << "Welcome to Airways Management System --- ticket_agent" << endl;
	cout << "Select the function you will perform" << endl;
	cout << "0.Exit to main" << endl;
	cout << "1.Show all order" << endl;
	cout << "2.Find flight" << endl;
	cout << "3.Booking a order" << endl;
	cout << "4.My turnover" << endl;


	cout << endl;
};

void Ticket_agent::showAllOrder() {
	Order order;
	string or_id;
	order.show_allOrder();
	Turnover tur;
	flight fli;

	cout << endl;
	cout << "Please input the order id you want to modify: " << endl;
	cin >> or_id;

	string choose = order.motify_order_status(or_id);

	string flight = order.flightId_by_orderId(or_id);

	string money = fli.flight_money(flight);

	if (choose == "1") {
		tur.change_turnover(to_string(m_Id), money);
	}

	system("pause");
	system("cls");
};


void Ticket_agent::valiOrder() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	string flight_id;
	string customer_id;
	string choose_row;
	string choose_colcumn;
	string choose_type;
	string status = "checking";

	flight fli;
	Order ord;

	cout << "Please entre customer id: " << endl;
	cin >> customer_id;
	cout << "Please input the id of the flight you want to book: " << endl;
	fli.show_allflight();
	cin >> flight_id;


	fli.show__flight_info_id(flight_id);

	//ord.show_seat_table();

	choose_type = fli.show_aircraft_of_flight(flight_id);

	if (choose_type == "P62") {

		cout << "Please choose the seat (6,2): " << endl;
		cout << "First choose the row: " << endl;
		cin >> choose_row;
		cout << "Then choose the column: " << endl;
		cin >> choose_colcumn;


	}
	else {
		cout << "Please choose the seat (12,4)" << endl;
		cout << "First choose the row: " << endl;
		cin >> choose_row;
		cout << "Then choose the column: " << endl;
		cin >> choose_colcumn;

	}


	string ord_id = ord.gene_order_id(stoi(flight_id), stoi(customer_id), stoi(choose_row), stoi(choose_colcumn));

	ofs << ord_id << " " << flight_id << " " << customer_id << " " << choose_row << " " << choose_colcumn << " " << status << endl;


	system("pause");
	system("cls");

	ofs.close();

};

void Ticket_agent::find_Flight() {
	cout << "Please choose how to find the flight: " << endl;
	cout << "1. Find by flight id" << endl;
	cout << "2. Find by price" << endl;
	cout << "3. Find by route" << endl;

	int id;
	string select;
	cin >> id;


	flight fli;

	if (id == 1) {

		cout << "Please give the flight id: " << endl;
		cin >> select;

		cout << "The flight show below" << endl;

		fli.show__flight_info_id(select);
	}

	else if (id == 2 ) {
	
		fli.show_flight_info_price();

	}

	else if (id == 3) {

		fli.show_flight_info_route();
	}

	system("pause");
	system("cls");
};

void Ticket_agent::show_myTurnover() {
	Turnover tur;
	tur.show_turnover(to_string(m_Id));

	system("pause");
	system("cls");
	
}