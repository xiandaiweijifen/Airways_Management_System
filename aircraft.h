#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class aircraft {

public:
	string name;
	string code;
	int row; //座位的行数
	int column;//座位的列数

	aircraft();
	
	~aircraft();

	aircraft(string name, string code, int row, int column);

	aircraft(string name, string code);

	virtual void show_seat_table(int the_row, int the_column);

	void amount_query();

	void add_existed_aircraft();

	void add_new_aircraft();

};
