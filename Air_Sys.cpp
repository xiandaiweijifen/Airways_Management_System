#include<iostream>
using namespace std;
#include "main_control.h"

#include "customer.h"
#include "ticket_agent.h"
#include "manager.h"
#include "administrator.h"
#include "identity.h"
#include "fstream"
#include "globalFile.h"

//�����û��Ӳ˵�����
void customerMenu(Identity* customer) {

	while (true) {

		//���ù���Ա���Ӳ˵�
		customer->operMenu();

		//������ָ��תΪ�����ָ�룬���������������ӿ�
		Customer* cus = (Customer*)customer;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1) {//�������
			cout << "�������" << endl;
			cus->applyFlight();
		}
		else if (select == 2) {//�鿴�˺�
			cout << "�鿴�ҵ�����״̬" << endl;
			cus->showMyFlight();
		}
		else if (select == 3) {//�鿴����
			cout << "�鿴��������" << endl;
			cus->showAllOrder();
		}
		else if (select == 4) {//���ԤԼ
			cout << "���ԤԼ" << endl;
			cus->cancelOrder();
		}
		else {//ע��ģ��

			delete customer;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//������ƱԱ�Ӳ˵�����
void ticket_agentMenu(Identity* ticket_agent) {

	while (true) {

		//���ù���Ա���Ӳ˵�
		ticket_agent->operMenu();

		//������ָ��תΪ�����ָ�룬���������������ӿ�
		Ticket_agent* tic = (Ticket_agent*)ticket_agent;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1) {//չʾ��������
			cout << "չʾ��������" << endl;
			tic->showAllOrder();
		}
		else if (select == 2) {//���Һ���
			cout << "���Һ���" << endl;
			tic->find_Flight();
		}
		else if (select == 3) {//�ύ����
			cout << "�ύ����" << endl;
			tic->valiOrder();
		}

		else if (select == 4) {//չʾҵ��
			cout << "չʾҵ��" << endl;
			tic->show_myTurnover();
		}
		
		else {//ע��ģ��
			delete ticket_agent;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�����
void managerMenu(Identity* manager) {

	while (true) {
		
		//���ù���Ա���Ӳ˵�
		manager->operMenu();

		//������ָ��תΪ�����ָ�룬���������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1) {//��ѯ�ɻ�����
			cout << "��ѯ�ɻ�����" << endl;
			man->show_air_amount();
		}
		else if (select == 2) {//��ѯ����
			cout << "��ѯ����" << endl;
			man->show_all_flight();
		}
		else if (select == 3) {//�޸ĺ���
			cout << "�޸ĺ���" << endl;
			man->change_Flight();
		}
		else if (select == 4) {//��ѯҵ��
			cout << "��ѯҵ��" << endl;
			man->show_performance();
		}
		else {//ע��ģ��
			delete manager;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//���������Ӳ˵�����
void administratorMenu(Identity* administrator) {

	while (true) {

		//���ù���Ա���Ӳ˵�
		administrator->operMenu();

		//������ָ��תΪ�����ָ�룬���������������ӿ�
		Administrator* adm = (Administrator*)administrator;

		int select = 0;
		//�����û�ѡ��
		cin >> select;

		if (select == 1) {//����˺�
			cout << "���Ա��" << endl;
			adm->addPerson();
		}
		else if (select == 2) {//�鿴�˺�
			cout << "�鿴Ա��" << endl;
			adm->showPerson();
		}
		else if (select == 3) {//�鿴����
			cout << "��Ӻ���" << endl;
			adm->add_Flight();
		}
		else if (select == 4) {//�鿴����
			cout << "��ӻ���" << endl;
			adm->add_Aircraft();
		}
		else if (select == 5) {//�鿴����
			cout << "�鿴����" << endl;
			adm->showFlight();
		}
		else if (select == 6) {//�޸ĺ���
			cout << "�޸ĺ���" << endl;
			adm->change_Flight();
		}
		else if (select == 7) {//���ԤԼ
			cout << "���ԤԼ" << endl ;
			adm->cleanFile();
		}
		else {//ע��ģ��

			delete administrator;//���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void LoginIn(string fileName, int type) {

	//����ָ�룬����ָ���������
	Identity * person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open()) {
		cout << "not exist" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)//�˿����
	{
		cout << "please your customer id: " << endl;
		cin >> id;
	}
	else if (type == 2) //��ƱԱ���
	{
		cout << "please your ticket_agent id: " << endl;
		cin >> id;
	}
	else if (type == 3) //�������
	{
		cout << "please your manager id: " << endl;
		cin >> id;
	}
	else if (type == 4) //�ϰ����
	{
		cout << "please your admionistrator id: " << endl;
		cin >> id;
	}

	cout << "please nickname: " << endl;
	cin >> name;

	cout << "please pwd: " << endl;
	cin >> pwd;

	if (type == 1) {

		//�û������֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "�û���¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Customer(id, name, pwd);

				//����ѧ����ݵ��Ӳ˵�
				customerMenu(person);

				return;
			}
		}
	}

	else if (type == 2) {
		//��ƱԱ�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ƱԱ��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Ticket_agent(id, name, pwd);

				//������ƱԱ��ݵ��Ӳ˵�
				ticket_agentMenu(person);

				return;
			}
		}
	}

	else if (type == 3) {
		//���������֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "�����¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(id, name, pwd);

				//������ƱԱ��ݵ��Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	if (type == 4) {
		//�ϰ������֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "�ϰ��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Administrator(id, name, pwd);

				//�����ϰ���ݵ��Ӳ˵�
				administratorMenu(person);

				return;
			}
		}
	}

	ifs.close();
	cout << "Failed to authenticate login!" << endl;
	system("pause");
	system("cls");
}

int main() {
	Main_control mc;

	int choice = 0;

	while (true) {
		mc.Show_Main_Menu();

		cout << "Please enter your choice:" << endl;
		cin >> choice;

		switch (choice) {

		case 0://Exit
			mc.exitSystem();
			break;

		case 1://Customer
			LoginIn(CUSTOMER_FILE, 1);
			break;

		case 2://Ticket agent
			LoginIn(TICKET_AGENT_FILE, 2);
			break;

		case 3://Manager
			LoginIn(MANAGER_FILE, 3);
			break;

		case 4://Administrator
			LoginIn(ADMIN_FILE, 4);
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}