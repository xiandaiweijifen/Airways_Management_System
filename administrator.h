#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include "ticket_agent.h"
#include <vector>
#include "manager.h"
#include "flight.h"
#include "aircraft.h"

class Administrator :public Identity {

public:

	Administrator();

	~Administrator();

	Administrator(int id, string name, string pwd);

	virtual void operMenu();

	void addPerson();

	void showPerson();

	void add_Flight();

	void add_Aircraft();

	void showFlight();

	void cleanFile();

	void initVector();

	vector<Ticket_agent> vTick;

	vector<Manager> vMan;

	vector<flight> vFli;

	bool checkRepeat(int id, int type);

	void delLine(string file_name, int id);

	void change_Flight();

};