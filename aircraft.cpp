#include"aircraft.h"

//ĳ�ֻ����״����ʱ�ô˹�����

aircraft::aircraft(){};

aircraft::~aircraft(){};

aircraft::aircraft(string name, string code, int row, int column) {
	this->name = name;
	this->code = code;
	this->row = row;
	this->column = column;
}


//������л���ʱ�Ĺ�����
aircraft::aircraft(string name, string code) {
	this->name = name;
	this->column = column;
	string tempname, tempcode;
	int temprow, tempcolumn;
	int flag = 0;
	ifstream fin("aircraft.txt");
	while (fin.eof() == false) {
		fin >> tempname >> tempcode >> temprow >> tempcolumn;
		if (tempname == name) {
			this->row = temprow;
			this->column = tempcolumn;
			flag = 1;
			break;
		}
		else
			continue;
	}
	if (flag == 0) {
		int newrow, newcolumn;
		cout << "This is not an existing aircraft! Please set seat row number and seat column number!" << endl;
		cout << "please input row number: ";
		cin >> newrow;
		cout << endl;
		cout << "Please input column number: ";
		cin >> newcolumn;
		cout << endl;
		this->row = newrow;
		this->column = newcolumn;
	}
	fin.close();

}




//��������û��͵���λƽ��ͼ
void aircraft::show_seat_table(int the_row,int the_column) {
	int row = the_row;
	int column = the_column;
	for (int i = 1; i <= row; i++) {
		cout << "|";
		for (int j = 1; j <= column; j++) {
			//cout << i << '-' << j << '\t';
			printf("%4d-%-4d|", i, j);
		}
		cout << endl;
	}
}




//����»���
void aircraft::add_new_aircraft() {
	string name;
	string code;
	int row;
	int column;

	aircraft tar;
	cout << "Please input aircraft name : ";
	cin >> name;
	cout << endl;
	cout << "Please input aircraft code: ";
	cin >> code;
	cout << endl;
	cout << "Please input aircraft seat row number:";
	cin >> row;
	cout << endl;
	cout << "Please input aircraft seat column number:";
	cin >> column;
	cout << endl;

	tar.name;
	tar.column;
	tar.row;
	ofstream fout("aircraft.txt", ios::app);
	fout << name << "\t" << code << "\t" << row << "\t" << column << endl;
	fout.close();
	cout << "New aircraft added successfully!" << endl;
}



//������л���
void aircraft::add_existed_aircraft() {
	string name;
	string code;
	cout << "Please input aircraft name : ";
	cin >> name;
	cout << endl;
	cout << "Please input aircraft code: ";
	cin >> code;
	cout << endl;
	aircraft tar(name, code);
	ofstream fout("aircraft.txt", ios::app);
	fout << name << "\t" << code << "\t" << tar.row << "\t" << tar.column << endl;
	fout.close();
	cout << "Aircraft added successfully!" << endl;
}




//��ѯĳ���ͺŷɻ�������
void aircraft::amount_query() {

	string tarname, name, code;
	int row, column;
	int counter = 0;

	cout << "Please input the aircraft type you want to query: ";
	cin >> tarname;

	ifstream fin("aircraft.txt");
	while (fin.eof() == false) {
		name = "";
		code = "";
		row = -1;
		column = -1; //Ϊ������������bug���ڶ�����һ������֮ǰ������ֵ���
		fin >> name >> code >> row >> column;
		if (name == tarname) {
			counter++;
			continue;
		}
		else continue;
	}

	cout << "A total of " << counter << " aircrafts of " << tarname << " at the airport." << endl;
	fin.close();

}

//�ļ�aircraft.txt�д洢���ǻ����йص���Ϣ��name��row��column��







//�˴���mainΪ�����ã���ʽǶ��ʱ��ɾ��
//int main() {
//
//	amount_query();
//
//	return 0;
//}
//���Խ���