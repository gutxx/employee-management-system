#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager :public Worker {
public:
	//构造函数
	Manager(int id, string name, int did);
	//获取个人信息
	virtual void showinfo();

	//显示岗位名称
	virtual string getDpetName();

};