#pragma once
#include<iostream>
using namespace std;

//职工抽象基类
class Worker {
public:
	//显示个人信息
	virtual void showinfo() = 0;
	//Worker* next;
	//获取岗位名称
	virtual string getDpetName() = 0;
	//职工编号
	int id;
	//职工姓名
	string m_name;
	//部门编号
	int m_deptId;

};