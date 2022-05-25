#pragma once
#include<iostream>
#include "identity.h"

using namespace std;

class Customer : public Identity {

public:
	Customer();

	~Customer();

	Customer(int id, string name, string pwd);

	virtual void operMenu();

	void applyFlight();

	void showMyFlight();

	void showAllOrder();

	void cancelOrder();


};