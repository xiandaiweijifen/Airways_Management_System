#include "turnover.h"
#include "globalFile.h"
#include "administrator.h"
#include<fstream>


Turnover::Turnover() {

};

Turnover::~Turnover() {};

Turnover::Turnover(string ti_id, string turn) {
	ticket_id = ti_id;
	turnovers = turn;
};

void Turnover::change_turnover(string id, string increase_money) {

	ifstream fin(TURNOVER_FILE);

	while (fin.eof() == false) {

		fin >> ticket_id >> turnovers;

		if (ticket_id == id) {
			Administrator admin;
			admin.delLine(TURNOVER_FILE, stoi(id));
			int allmoney = stoi(turnovers) + stoi(increase_money);
			fin.close();

			ofstream ofs;
			ofs.open(TURNOVER_FILE, ios::out | ios::app);
			ofs << id << " " << to_string(allmoney);
			ofs.close();
		}
		else {
			ofstream ofs;
			ofs.open(TURNOVER_FILE, ios::out | ios::app);
			ofs << id << " " << increase_money;
			ofs.close();
		}
	
	}
	fin.close();
}

void Turnover::show_turnover(string id) {
	ifstream fin(TURNOVER_FILE);

	while (fin.eof() == false) {

		fin >> ticket_id >> turnovers;

		if (ticket_id == id) {
			cout << "Your total turnover is: " << turnovers << endl;
			break;
		}
		else {
			cout << "You don't have a turnover yet." << endl;
			break;
		}
	}
	fin.close();
}

void Turnover::show_allTurnover() {
	ifstream fin(TURNOVER_FILE);

	while (fin.eof() == false) {
		fin >> ticket_id >> turnovers;
		cout << "Ticket id: " << ticket_id << "Turnover: " << turnovers << endl;
	}

	fin.close();
}