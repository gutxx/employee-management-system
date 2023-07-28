#include<iostream>
#include"boss.h"
using namespace std;


//构造函数
Boss::Boss(int id, string name, int did) {
	this->id = id;
	this->m_name = name;
	this->m_deptId = did;
}
//获取个人信息
void Boss::showinfo() {
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位:" << this->getDpetName()
		<< "\t岗位职责：下发任务给经理" << endl;
}

//显示岗位名称
string Boss::getDpetName() {
	return string("老板");
}

