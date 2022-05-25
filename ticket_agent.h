#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "identity.h"
#include <vector>
#include"order.h"

class Ticket_agent :public Identity {

public:
	Ticket_agent();

	~Ticket_agent();

	Ticket_agent(int Ti_Id, string name, string pwd);

	virtual void operMenu();

	void showAllOrder();

	void valiOrder();

	void find_Flight();

	void show_myTurnover();

};