#include "WorkerManager.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<iostream>
using namespace std;

//类中成员全局变量是在程序运行期，main函数开始之前，调用构造函数完成初始化的
int main() {
	
	//测试代码
	/*Worker* worker = NULL;
	worker = new Boss(3, "李五", 3);
	worker->showinfo();
	delete worker;
	worker = new employee(2, "李五", 2);
	worker->showinfo();
	delete worker;
	worker = new Manager(1, "李五", 1);
	worker->showinfo();
	delete worker;*/


	//实例化管理者对象 
	workerManager wm;

	//调用展示菜单成员函数
	int choice;//用来存储用户选项
	while (true)
	{
		wm.Show_menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加职工
			wm.add_emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.del_Emp();
			break;
		case 4://修改职工
			wm.mod_Emp();
			break;
		case 5://查找职工
			wm.find_Emp();
			break;
		case 6://排序职工
			wm.sort_Emp();
			break;
		case 7://清空文件
			wm.clean_File();
			break;
		default: //其他数默认清除后循环
			system("cls");
			break;
		}
	}
		
	
	system("pause");
}