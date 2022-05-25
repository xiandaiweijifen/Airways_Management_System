#include"flight.h"
#include "globalFile.h"
#include "administrator.h"

//构造器

flight::flight() {};

flight::~flight() {};

flight::flight(string flight_id, string aircraft, string date, string depart_airport, string arr_airport, double price) {

	this->flight_id = flight_id;
	this->aircraft = aircraft;
	this->date = date;
	this->depart_airport = depart_airport;
	this->arr_airport = arr_airport;
	this->price = price;


	int seatnum;
	int row;
	int column;
	string craftname, code;
	int flag = 0;

	ifstream fin("aircraft.txt");
	while (fin.eof() == false) {
		fin >> craftname >> code >> row >> column;
		if (aircraft == craftname) {
			seatnum = row * column;
			flag = 1;
			break;
		}
		else
			continue;
	}
	if (flag == 0) {
		seatnum = -1;
		cout << "Aircraft Error!" << endl;
	}
	this->remain_seat = seatnum;
	fin.close();
}
//构造器完





//显示所有的航班信息
void flight::show_allflight() {

	ifstream fin("flight.txt");

	cout << "航班信息如下：" << endl;

	while (fin.eof() == false) {
		fin >> flight_id >> aircraft >> date >> depart_airport >> arr_airport >> price >> remain_seat;
		cout << "flight_id: " << flight_id << " " << "aircraft: " << aircraft << " " << "date: " << date << " " << "depart_airport: " << depart_airport << " " << "arr_airport: " << arr_airport << " " << "ticket_price: " << price << " " << "remain_seats: " << remain_seat << endl;
		cout << endl;

		fin.get();                             //读取最后的回车符，防止重复读取最后一行
		if (fin.peek() == '\n') break;



	}
	fin.close();
};







//展示指定航班的信息(输入航班id，展示其信息）
void flight::show__flight_info_id(string choose_id) {

	int flight_id;
	string aircraft;
	string date;
	string depart_airport;
	string arr_airport;
	double price;
	int remain_seat;

	ifstream fin("flight.txt");
	int flag = 0;

	while (fin.eof() == false) {
		flight_id = 0;
		aircraft = "";
		date = "";
		depart_airport = "";
		arr_airport = "";
		price = -1;
		remain_seat = -2;   //为避免空行引起的bug，在读入新一行数据之前将所有值清空

		fin >> flight_id >> aircraft >> date >> depart_airport >> arr_airport >> price >> remain_seat;
		if (flight_id == stoi(choose_id)) {

			cout << endl;
			cout << "Flight id: " << flight_id << endl;
			cout << endl;
			cout << "Aircraft: " << aircraft << endl;
			cout << endl;
			cout << "Date: " << date << endl;
			cout << endl;
			cout << "Departure: " << depart_airport << endl;
			cout << endl;
			cout << "Arrival: " << arr_airport << endl;
			cout << endl;
			cout << "Ticket Price: " << price << endl;
			cout << endl;
			cout << remain_seat << " Seats remained." << endl;
			cout << endl;
			flag = 1;

			fin.get();                             //读取最后的回车符，防止重复读取最后一行
			if (fin.peek() == '\n') break;

			continue;
		}
		else
			continue;
	}
	if (flag == 0) {
		cout << "Flight not found!";
	}
	fin.close();

}


//根据航班的出发地和目的地搜索航班
void flight::show_flight_info_route() {

	string departure;
	string arrival;
	int flight_id;
	string aircraft;
	string date;
	string depart_airport;
	string arr_airport;
	double price;
	int remain_seat;

	cout << "Please input departure place: ";
	cin >> departure;
	cout << "Please input arrival place: ";
	cin >> arrival;
	ifstream fin("flight.txt");
	int flag = 0;
	while (fin.eof() == false) {
		flight_id = 0;
		aircraft = "";
		date = "";
		depart_airport = "";
		arr_airport = "";
		price = -1;
		remain_seat = -2;//为避免空行引起的bug，在读入新一行数据之前将所有值清空
		fin >> flight_id >> aircraft >> date >> depart_airport >> arr_airport >> price >> remain_seat;
		if (depart_airport == departure && arr_airport == arrival) {
			cout << "Flight id: " << flight_id << endl;
			cout << "Aircraft: " << aircraft << endl;
			cout << "Date: " << date << endl;
			cout << "Departure: " << depart_airport << endl;
			cout << "Arrival: " << arr_airport << endl;
			cout << "Ticket Price: " << price << endl;
			cout << remain_seat << " seats remained." << endl;
			cout << endl;
			flag = 1;

			fin.get();                             //读取最后的回车符，防止重复读取最后一行
			if (fin.peek() == '\n') break;

			continue;
		}
		else
			continue;
	}
	if (flag == 0) {
		cout << "Flight not found!";
	}
	fin.close();
}



//根据价格区间搜索航班
void flight::show_flight_info_price() {

	double min;
	double max;
	string flight_id;
	string aircraft;
	string date;
	string depart_airport;
	string arr_airport;
	double price;
	int remain_seat;

	cout << "Please input minimum price: ";
	cin >> min;
	cout << "Please input maximum price: ";
	cin >> max;

	ifstream fin("flight.txt");
	int flag = 0;

	while (fin.eof() == false) {

		flight_id = "";
		aircraft = "";
		date = "";
		depart_airport = "";
		arr_airport = "";
		price = -1;
		remain_seat = -2;//为避免空行引起的bug，在读入新一行数据之前将所有值清空

		fin >> flight_id >> aircraft >> date >> depart_airport >> arr_airport >> price >> remain_seat;
		if (price >= min && price <= max) {
			cout << "Flight id: " << flight_id << endl;
			cout << "Aircraft: " << aircraft << endl;
			cout << "Date: " << date << endl;
			cout << "Departure: " << depart_airport << endl;
			cout << "Arrival: " << arr_airport << endl;
			cout << "Ticket Price: " << price << endl;
			cout << remain_seat << " seats remained." << endl;
			cout << endl;
			flag = 1;
			continue;
		}
		else
			continue;
	}
	if (flag == 0) {
		cout << "Flight not found!";
	}
	fin.close();
}


//添加新航班到文件
void flight::add_flight() {

	string flight_id;
	string aircraft;
	string date;
	string depart_airport;
	string arr_airport;
	double price;

	cout << "Please input flight ID: ";
	cin >> flight_id;

	cout << "Please input aircraft type: ";
	cin >> aircraft;

	cout << "Please input departure date (YYYY-MM-DD): ";
	cin >> date;

	cout << "Please input departure airport: ";
	cin >> depart_airport;

	cout << "Please input arrival airport: ";
	cin >> arr_airport;

	cout << "Please input ticket price: ";
	cin >> price;

	flight temp(flight_id, aircraft, date, depart_airport, arr_airport, price);
	int remain_seat = temp.remain_seat;

	if (remain_seat != 0) {
		ofstream fout("flight.txt", ios::app);
		fout << endl << flight_id << "\t" << aircraft << "\t" << date << "\t" << depart_airport << "\t" << arr_airport << "\t" << price << "\t" << remain_seat;
		fout.close();
		cout << "Flight added successfully!" << endl;
	}
	else {
		cout << "Cannot add flight, aircraft undefined!";
	}
}


string flight::show_aircraft_of_flight(string choose_id) {



	int flight_id;
	string aircraft;
	string date;
	string depart_airport;
	string arr_airport;
	double price;
	int remain_seat;

	ifstream fin("flight.txt");
	int flag = 0;

	while (fin.eof() == false) {
		fin >> flight_id >> aircraft >> date >> depart_airport >> arr_airport >> price >> remain_seat;
		if (flight_id == stoi(choose_id)) {

			return aircraft;

			fin.get();                             //读取最后的回车符，防止重复读取最后一行
			if (fin.peek() == '\n') break;

			break;
		}
	}

	fin.close();

};
//文件“flight.txt"中存储的是有关航班的信息

void flight::change_by_id(string id) {

	string flight_id;
	string aircraft;
	string date;
	string depart_airport;
	string arr_airport;
	double price;
	int remain_seat;

	ifstream fin("flight.txt");

	while (fin.eof() == false) {

		fin >>flight_id >> aircraft >> date >> depart_airport>> arr_airport>> price>> remain_seat;
		if (flight_id == id) {

			Administrator adi;

			adi.delLine("flight.txt", stoi(id)); //使用自带函数stoi实现string转int

			fin.get();                             //读取最后的回车符，防止重复读取最后一行
			if (fin.peek() == '\n') break;

			break;
		}
	}
	fin.close();

	remain_seat = remain_seat-1;

	if (remain_seat != 0) {
		ofstream fout("flight.txt", ios::app);
		fout << flight_id << "\t" << aircraft << "\t" << date << "\t" << depart_airport << "\t" << arr_airport << "\t" << price << "\t" << remain_seat<<endl;
		fout.close();
	}


}

void flight::change_price(int id){

	string flight_id;
	string aircraft;
	string date;
	string depart_airport;
	string arr_airport;
	double price;
	int remain_seat;



	ifstream fin("flight.txt");

	while (fin.eof() == false) {

		fin >> flight_id >> aircraft >> date >> depart_airport >> arr_airport >> price >> remain_seat;
		if (flight_id == to_string(id)) {

			Administrator adi;

			adi.delLine("flight.txt", id); //使用自带函数stoi实现string转int

			fin.get();                             //读取最后的回车符，防止重复读取最后一行
			if (fin.peek() == '\n') break;

			break;
		}
	}
	fin.close();

	remain_seat = remain_seat - 1;

	if (remain_seat != 0) {
		ofstream fout("flight.txt", ios::app);
		fout << flight_id << "\t" << aircraft << "\t" << date << "\t" << depart_airport << "\t" << arr_airport << "\t" << price << "\t" << remain_seat << endl;
		fout.close();
	}

};

void flight::chaneg_date(int id){};

void flight::change_start(int id){};

void flight::change_arr(int id){};

/*
//展示该航班剩余座位的平面图
void flight::show_remain_seat_table(string choose_id) {

	string flight_id;
	string aircraft;
	string date;
	string depart_airport;
	string arr_airport;
	double price;
	int remain_seat;
	flight tar;
	string tarname;
	string code;
	int status;

	string order_id;
	int id;
	int choose_seat_column;
	int choose_seat_row;
	string choose_type;
	string m_id;

	int row;
	int column;

	ifstream fin_flight("flight.txt");

	while (fin_flight.eof() == false) {

		fin_flight >> flight_id >> aircraft >> date >> depart_airport >> arr_airport >> price >> remain_seat;

		if (flight_id == choose_id) {

			ifstream fin_aircraft("aircraft.txt");



			while (fin_aircraft.eof() == false) {
				fin_aircraft >> code>> tarname  >> row >> column;

				if (tarname == aircraft) {
					//ifstream fin_order("order.txt");

					for (int i = 1; i <= row; i++) {
						cout << "|";

						for (int j = 1; j <= column; j++) {
							//cout << i << '-' << j << '\t';
							int flag = 0;

							ifstream fin_order("order.txt");

						//	fin_order.open(ORDER_FILE, ios::out | ios::app);

							while (fin_order.eof() == false) {

								fin_order >> order_id >> id >> m_id >> choose_seat_row >> choose_seat_column >> status;

								if (choose_seat_row == i && choose_seat_column == j && id == stoi(choose_id)) {

									cout << "         |";
									flag = 1;


									break;

								}

								else continue;
								fin_order.get();
							}

							fin_order.close();

							if (flag == 0) {
								printf("%4d-%-4d|", i, j);
							}

						}
						cout << endl;
					}

				}

				fin_aircraft.get();
				break;
			}
			fin_aircraft.close();
		}

		fin_flight.get();
		break;

	}
	fin_flight.close();

}
*/

void flight::show_remain_seat_table(string choose_id) {

	int tid = stoi(choose_id);
	int flight_id;
	string aircraft;
	string date;
	string depart_airport;
	string arr_airport;
	double price;
	int remain_seat;

	flight tar;
	string tarname;
	string code;

	string order_id;
	int id;
	int choose_seat_column;
	int choose_seat_row;
	string choose_type;
	int statu;
	string m_id;

	int row;
	int column;

	ifstream fin_flight("flight.txt");
	while (fin_flight.eof() == false) {
		fin_flight >> flight_id >> aircraft >> date >> depart_airport >> arr_airport >> price >> remain_seat;
		if (flight_id == tid) {
			ifstream fin_aircraft("aircraft.txt");
			while (fin_aircraft.eof() == false) {
				fin_aircraft >> code>> tarname  >> row >> column;
				if (tarname == aircraft) {
					ifstream fin_order("order.txt");

					for (int i = 1; i <= row; i++) {
						cout << "|";
						for (int j = 1; j <= column; j++) {
							//cout << i << '-' << j << '\t';
							int flag = 0;
							while (fin_order.eof() == false) {
								fin_order >> order_id >> id >> m_id >> choose_seat_row >> choose_seat_column >> statu;
								if (choose_seat_row == i && choose_seat_column == j && id == tid) {
									cout << "        |";
									flag = 1;
									break;
								}
								else continue;
								fin_order.get();
							}
							fin_order.close();
							if (flag == 0) {
								printf("%4d-%-4d|", i, j);
							}
						}
						cout << endl;
					}

				}
				fin_aircraft.get();
			}
			fin_aircraft.close();
		}
		fin_flight.get();
	}
	fin_flight.close();

}


string flight::flight_money(string id) {
	ifstream fin(FLIGHT_FILE);
	while (fin.eof() == false) {
		fin >> flight_id >> aircraft >> date >> depart_airport >> arr_airport >> price >> remain_seat;
		if (flight_id == id) {
			return to_string(price);
		}

	}
	fin.close();
}

void flight::change_information(string id) {
	int select;
	ifstream fin(FLIGHT_FILE);
	Administrator admin;
	string change;
	while (fin.eof() == false) {
		fin >> flight_id >> aircraft >> date >> depart_airport >> arr_airport >> price >> remain_seat;
		if (flight_id == id) {
			cout << "请输入你想更改信息的种类： " << endl;
			cout << "1. Date" << endl;
			cout << "2. 起点" << endl;
			cout << "3. 终点" << endl;
			cout << "4. Price" << endl;
			cin >> select;

			cout << "请输入更改信息：" << endl;
			cin >> change;
			if (select == 1) {
				admin.delLine(FLIGHT_FILE, stoi(id));
				ofstream ofs;
				ofs.open(FLIGHT_FILE, ios::out | ios::app);
				ofs << flight_id << " " << aircraft << " " << change << " " <<
					depart_airport << " " << arr_airport << " " << price << " " << remain_seat;
				break;
			}
			else if (select == 2) {
				admin.delLine(FLIGHT_FILE, stoi(id));
				ofstream ofs;
				ofs.open(FLIGHT_FILE, ios::out | ios::app);
				ofs << flight_id << " " << aircraft << " " << date << " " <<
					change << " " << arr_airport << " " << price << " " << remain_seat;
			}
			else if (select == 3) {
				admin.delLine(FLIGHT_FILE, stoi(id));
				ofstream ofs;
				ofs.open(FLIGHT_FILE, ios::out | ios::app);
				ofs << flight_id << " " << aircraft << " " << date << " " <<
					depart_airport << " " << change << " " << price << " " << remain_seat;
			}
			else if (select == 4) {
				admin.delLine(FLIGHT_FILE, stoi(id));
				ofstream ofs;
				ofs.open(FLIGHT_FILE, ios::out | ios::app);
				ofs << flight_id << " " << aircraft << " " << date << " " <<
					depart_airport << " " << arr_airport << " " << change << " " << remain_seat;
			}
			else {
				cout << "Abnormal input, please input again." << endl;
			}
			break;
		}
		else {
			cout << "Abnormal input, please input again." << endl;
		}
	}

}

