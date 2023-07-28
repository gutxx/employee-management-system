#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
#define FILENAME "empfile.txt"

//在C++里面，每一个对象都能通过this指针来访问自己的地址,友元函数没有this指针，成员函数有
class workerManager {
public:
	//构造函数
	workerManager();

	//展示菜单
	void Show_menu();

	//退出系统
	void exitSystem();

	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker ** m_EmpArray; //二级指针 指向指针的指针
	//添加职工
	void add_emp();
	//统计人数
	int get_EmpNum();
	//保存文件
	void save();
	//判断文件是否为空 标志
	bool m_FileIsEmpty=false;
	//初始化员工
	void init_Emp();
	
	//显示职工
	void show_Emp();
	//检测职工是否存在
	int isExist(string name);

	//删除职工
	void del_Emp();

	//修改职工
	void mod_Emp();

	//查找员工
	void find_Emp();

	//排序职工
	void sort_Emp();

	//清空文件
	void clean_File();

	//析构函数
	~workerManager();
};