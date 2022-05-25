#pragma once
#include<iostream>
#include<string>
using namespace std;

class Identity {

public:
	//操作菜单
	virtual void operMenu() = 0;

	int m_Id;
	string m_Name;//用户名
	string m_Pwd;//密码




};