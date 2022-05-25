#pragma once
using namespace std;
#include<iostream>
#include<string>

class Turnover {

public:

	string ticket_id;
	string turnovers;

	Turnover();

	~Turnover();

	Turnover(string ti_id, string turn);

	void change_turnover(string id, string increase_money);

	void show_turnover(string id);

	void show_allTurnover();

};