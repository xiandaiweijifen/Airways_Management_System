#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class flight {
public:

	string flight_id;
	string aircraft;
	string date;
	string depart_airport;
	string arr_airport;
	double price;
	int remain_seat;


	flight();

	~flight();

	flight(string flight_id, string aircraft, string date, string depart_airport, string arr_airport, double price);

	void show_allflight();

	void show__flight_info_id(string choose_id);

	void show_flight_info_route();

	void show_flight_info_price();

	void add_flight();

	string show_aircraft_of_flight(string choose_id);

	void change_by_id(string id);

	void change_price(int id);

	void chaneg_date(int id);

	void change_start(int id);
	
	void change_arr(int id);

	void show_remain_seat_table(string choose_id);

	string flight_money(string id);

	void change_information(string id);

};