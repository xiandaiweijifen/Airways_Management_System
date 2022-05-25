#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class aircraft {

public:
	string name;
	string code;
	int row; //��λ������
	int column;//��λ������

	aircraft();
	
	~aircraft();

	aircraft(string name, string code, int row, int column);

	aircraft(string name, string code);

	virtual void show_seat_table(int the_row, int the_column);

	void amount_query();

	void add_existed_aircraft();

	void add_new_aircraft();

};
