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

//进入用户子菜单界面
void customerMenu(Identity* customer) {

	while (true) {

		//调用管理员的子菜单
		customer->operMenu();

		//将父类指针转为子类的指针，调用子类里其他接口
		Customer* cus = (Customer*)customer;

		int select = 0;
		//接受用户选项
		cin >> select;

		if (select == 1) {//添加申请
			cout << "添加申请" << endl;
			cus->applyFlight();
		}
		else if (select == 2) {//查看账号
			cout << "查看我的申请状态" << endl;
			cus->showMyFlight();
		}
		else if (select == 3) {//查看航班
			cout << "查看所有申请" << endl;
			cus->showAllOrder();
		}
		else if (select == 4) {//清空预约
			cout << "清空预约" << endl;
			cus->cancelOrder();
		}
		else {//注销模块

			delete customer;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入售票员子菜单界面
void ticket_agentMenu(Identity* ticket_agent) {

	while (true) {

		//调用管理员的子菜单
		ticket_agent->operMenu();

		//将父类指针转为子类的指针，调用子类里其他接口
		Ticket_agent* tic = (Ticket_agent*)ticket_agent;

		int select = 0;
		//接受用户选项
		cin >> select;

		if (select == 1) {//展示所有申请
			cout << "展示所有申请" << endl;
			tic->showAllOrder();
		}
		else if (select == 2) {//查找航班
			cout << "查找航班" << endl;
			tic->find_Flight();
		}
		else if (select == 3) {//提交申请
			cout << "提交申请" << endl;
			tic->valiOrder();
		}

		else if (select == 4) {//展示业绩
			cout << "展示业绩" << endl;
			tic->show_myTurnover();
		}
		
		else {//注销模块
			delete ticket_agent;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单界面
void managerMenu(Identity* manager) {

	while (true) {
		
		//调用管理员的子菜单
		manager->operMenu();

		//将父类指针转为子类的指针，调用子类里其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户选项
		cin >> select;

		if (select == 1) {//查询飞机数量
			cout << "查询飞机数量" << endl;
			man->show_air_amount();
		}
		else if (select == 2) {//查询航班
			cout << "查询航班" << endl;
			man->show_all_flight();
		}
		else if (select == 3) {//修改航班
			cout << "修改航班" << endl;
			man->change_Flight();
		}
		else if (select == 4) {//查询业绩
			cout << "查询业绩" << endl;
			man->show_performance();
		}
		else {//注销模块
			delete manager;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入主管子菜单界面
void administratorMenu(Identity* administrator) {

	while (true) {

		//调用管理员的子菜单
		administrator->operMenu();

		//将父类指针转为子类的指针，调用子类里其他接口
		Administrator* adm = (Administrator*)administrator;

		int select = 0;
		//接受用户选项
		cin >> select;

		if (select == 1) {//添加账号
			cout << "添加员工" << endl;
			adm->addPerson();
		}
		else if (select == 2) {//查看账号
			cout << "查看员工" << endl;
			adm->showPerson();
		}
		else if (select == 3) {//查看航班
			cout << "添加航班" << endl;
			adm->add_Flight();
		}
		else if (select == 4) {//查看航班
			cout << "添加机型" << endl;
			adm->add_Aircraft();
		}
		else if (select == 5) {//查看航班
			cout << "查看航班" << endl;
			adm->showFlight();
		}
		else if (select == 6) {//修改航班
			cout << "修改航班" << endl;
			adm->change_Flight();
		}
		else if (select == 7) {//清空预约
			cout << "清空预约" << endl ;
			adm->cleanFile();
		}
		else {//注销模块

			delete administrator;//销毁堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void LoginIn(string fileName, int type) {

	//父类指针，用于指向子类对象
	Identity * person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open()) {
		cout << "not exist" << endl;
		ifs.close();
		return;
	}

	//准备接受用户的信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)//顾客身份
	{
		cout << "please your customer id: " << endl;
		cin >> id;
	}
	else if (type == 2) //售票员身份
	{
		cout << "please your ticket_agent id: " << endl;
		cin >> id;
	}
	else if (type == 3) //经理身份
	{
		cout << "please your manager id: " << endl;
		cin >> id;
	}
	else if (type == 4) //老板身份
	{
		cout << "please your admionistrator id: " << endl;
		cin >> id;
	}

	cout << "please nickname: " << endl;
	cin >> name;

	cout << "please pwd: " << endl;
	cin >> pwd;

	if (type == 1) {

		//用户身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "用户登录成功" << endl;
				system("pause");
				system("cls");
				person = new Customer(id, name, pwd);

				//进入学生身份的子菜单
				customerMenu(person);

				return;
			}
		}
	}

	else if (type == 2) {
		//售票员身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "售票员登录成功" << endl;
				system("pause");
				system("cls");
				person = new Ticket_agent(id, name, pwd);

				//进入售票员身份的子菜单
				ticket_agentMenu(person);

				return;
			}
		}
	}

	else if (type == 3) {
		//经理身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "经理登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(id, name, pwd);

				//进入售票员身份的子菜单
				managerMenu(person);
				return;
			}
		}
	}
	if (type == 4) {
		//老板身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "老板登录成功" << endl;
				system("pause");
				system("cls");
				person = new Administrator(id, name, pwd);

				//进入老板身份的子菜单
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