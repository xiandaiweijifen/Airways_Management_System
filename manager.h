#pragma once
#include<iostream>
using namespace std;
#include "identity.h"

class Manager :public Identity {

public:

	Manager();
	
	~Manager();

	Manager(int id, string name, string pwd);

	virtual void operMenu();

	void show_air_amount();

	void show_all_flight();

	void show_performance();

	void change_Flight();

};