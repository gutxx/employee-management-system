#include<iostream>
#include"manager.h"
using namespace std;


//构造函数
Manager::Manager(int id, string name, int did) {
	this->id = id;
	this->m_name = name;
	this->m_deptId = did;
}
//获取个人信息
void Manager::showinfo() {
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位:" << this->getDpetName()
		<< "\t岗位职责：完成老板交给的任务，并下发任务给普工" << endl;
}

//显示岗位名称
string Manager::getDpetName() {
	return string("经理");
}

