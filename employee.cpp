#include<iostream>
#include"employee.h"
using namespace std;


//构造函数
employee::employee(int id,string name,int did) {
	this->id = id;
	this->m_name = name;
	this->m_deptId = did;
}
//获取个人信息
void employee::showinfo() {
	cout << "职工编号：" << this->id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位:" << this->getDpetName() 
		<<"\t岗位职责：完成经理交给的任务" << endl;
 }

//显示岗位名称
string employee::getDpetName() {
	return string("员工");
}

