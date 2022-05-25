#include"administrator.h"
#include "globalFile.h"
#include"iostream"
#include"fstream"
#include<algorithm>
#include "aircraft.h"
#include "flight.h"
#include<sstream>
#include<string>

Administrator::Administrator() {

}
Administrator::~Administrator() {};

Administrator::Administrator(int id, string name, string pwd) {

}

void Administrator::operMenu() {
	cout << endl;
	cout << "Welcome to Airways Management System --- administrator" << endl;
	cout << "Select the function you will perform" << endl;
	cout << "0.Exit to main" << endl;
	cout << "1.Add employee" << endl;
	cout << "2.Show employee" << endl;
	cout << "3.Add flight" << endl;
	cout << "4.Add airceaft" << endl;
	cout << "5.Show flight" << endl;
	cout << "6.Change flight" << endl;
	cout << "7.clean order" << endl;
	cout << endl;
}

void Administrator::addPerson() {
	cout << "请输入添加账号的类型" << endl;
	cout << "1.添加售票员" << endl;
	cout << "2.添加经理" << endl;

	string fileName;
	string tip;
	ofstream ofs;
	string errorTip;

	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = TICKET_AGENT_FILE;
		tip = "ticket id:";
		errorTip = "Incorrect ticket id, please enter it again";
	}
	if (select == 2) {
		fileName = MANAGER_FILE;
		tip = "manager id:";
		errorTip = "Incorrect manager id, please enter it again";
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;

	cout << errorTip << endl;

	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}

	cout << "Please enter your name" << endl;
	cin >> name;
	cout << "Please enter your password" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "Add a success" << endl;
	initVector();

	system("pause");
	system("cls");

	ofs.close();

}


void Administrator::initVector() {
	//Make sure it is clear
	vTick.clear();
	vMan.clear();
	//Read the information

//	ifstream ifs;

//	ifs.open(TICKET_AGENT_FILE, ios::in);

	ifstream ifs("ticket_agent.txt");

	if (!ifs.is_open()) {
		cout << "File reading failure" << endl;
		return;
	}
	Ticket_agent t;
	while (ifs >> t.m_Id && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTick.push_back(t);
	}
	ifs.close();

//	ifs.open(MANAGER_FILE, ios::in);

	ifstream ifst("manager.txt");

	if (!ifst.is_open()) {
		cout << "File reading failure" << endl;
		return;
	}

	Manager m;

	while (ifst >> m.m_Id && ifst >> m.m_Name && ifst >> m.m_Pwd) {
		vMan.push_back(m);
	}
	ifst.close();


}


bool Administrator::checkRepeat(int id, int type) {
	if (type == 1) {
		//check tick agent
		for (vector<Ticket_agent>::iterator it = vTick.begin(); it != vTick.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else {
		//cjeck manager
		for (vector<Manager>::iterator it2 = vMan.begin(); it2 != vMan.end(); it2++) {
			if (id == it2->m_Id) {
				return true;
			}
		}
	}
	return false;
}


void printTicket_agent(Ticket_agent& t) {
	cout << "id: " << t.m_Id << " " << "name: " << t.m_Name << " " << "password: " << t.m_Pwd << endl;
}
void printManager(Manager& m) {
	cout << "id: " << m.m_Id << " " << "name: " << m.m_Name << " " << "password: " << m.m_Pwd << endl;
}



void Administrator::showPerson() {
	initVector();
	cout << "Please select the content to view" << endl;
	cout << endl;
	cout << "1. All ticket agent" << endl;
	cout << "2. All manager" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		// Ticket agent
		cout << "All ticket agent are listed below:" << endl;
		for_each(vTick.begin(), vTick.end(), printTicket_agent);
	}
	else if (select == 2) {
		// Manager
		cout << "All manager are listed below:" << endl;
		for_each(vMan.begin(), vMan.end(), printManager);
	}
	else {
		cout << "Invalid input, please re-enter" << endl;
		system("pause");
		system("cls");
	}
	system("pause");
	system("cls");
}

void Administrator::showFlight() {
	cout << "All flight are listed below:" << endl;


	flight fli;
	fli.show_allflight();

	system("pause");
	system("cls");
}

void Administrator::cleanFile() {
	cout << "The part you want to clean: " << endl;
	cout << "1. Ticket agent" << endl;
	cout << "2.	Manager" << endl;
	cout << "3. Flight" << endl;
	cout << "4. Aircrift" << endl;
	cout << "5. Customer" << endl;
	cout << "6. Order" << endl;
	cout << "Clear success" << endl;

	int select;
	cin >> select;

	if (select == 1) {
		cout << "Please input the ticket_agent id: " << endl;
		int id;
		cin >> id;
		delLine(TICKET_AGENT_FILE, id);
		cout << "Clear success" << endl;
	}

	if (select == 2) {
		cout << "Please input the manager id: " << endl;
		int id;
		cin >> id;
		delLine(MANAGER_FILE, id);
		cout << "Clear success" << endl;
	}

	if (select == 3) {
		cout << "Please input the flight id: " << endl;
		int id;
		cin >> id;
		delLine(FLIGHT_FILE, id);
		cout << "Clear success" << endl;
	}

	if (select == 4) {
		cout << "Please input the aircraft id: " << endl;
		int id;
		cin >> id;
		delLine(AIECRAFT_FILE, id);
		cout << "Clear success" << endl;
	}

	if (select == 5) {
		cout << "Please input customer id: " << endl;
		int id;
		cin >> id;
		delLine(CUSTOMER_FILE, id);
		cout << "Clear success" << endl;
	}

	if (select == 6) {
		cout << "Please input order id: " << endl;
		string id;
		cin >> id;
		delLine(ORDER_FILE, stoi(id));
		cout << "Clear success" << endl;
	}

	system("pause");
	system("cls");
}

void Administrator::delLine(string file_name, int id) {

	ifstream in(file_name);

	string data = "";
	string line, temp;

	while (getline(in, line)) {
		istringstream is(line);
		is >> temp;
		if (temp == to_string(id)) {
		}
		else {
			data += (line + "\n");
		}
	}

	in.close();

	ofstream os(file_name);

	os << data;
	os.close();

}

void Administrator::add_Aircraft() {
	aircraft air;
	air.add_existed_aircraft();

	system("pause");
	system("cls");
}

void Administrator::add_Flight() {

	flight fli;
	fli.add_flight();

	system("pause");
	system("cls");
}

void Administrator::change_Flight() {

	string input;
	cout << "请输入要更改的id" << endl;
	cin >> input;
	flight fli;
	fli.change_information(input);

}