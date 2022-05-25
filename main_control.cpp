#include"main_control.h"

Main_control::Main_control() {


}

void Main_control::Show_Main_Menu() {

	cout << endl;
	cout<< "Welcome to Airways Management System" << endl;
	cout<< "Select the login identity" << endl;
	cout<< "0.Exit" << endl;
	cout<< "1.Customer" << endl;
	cout<< "2.Ticket agent" << endl;
	cout<< "3.Manager" << endl;
	cout<< "4.Administrator" << endl;
	cout<<endl;

}
void Main_control::exitSystem() {
	cout<<"Welcome to use next time!" << endl;
	system("pause");
	exit(0);

}

Main_control::~Main_control() {


}