#include "WorkerManager.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<iostream>
using namespace std;

//���г�Աȫ�ֱ������ڳ��������ڣ�main������ʼ֮ǰ�����ù��캯����ɳ�ʼ����
int main() {
	
	//���Դ���
	/*Worker* worker = NULL;
	worker = new Boss(3, "����", 3);
	worker->showinfo();
	delete worker;
	worker = new employee(2, "����", 2);
	worker->showinfo();
	delete worker;
	worker = new Manager(1, "����", 1);
	worker->showinfo();
	delete worker;*/


	//ʵ���������߶��� 
	workerManager wm;

	//����չʾ�˵���Ա����
	int choice;//�����洢�û�ѡ��
	while (true)
	{
		wm.Show_menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���ְ��
			wm.add_emp();
			break;
		case 2://��ʾְ��
			wm.show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.del_Emp();
			break;
		case 4://�޸�ְ��
			wm.mod_Emp();
			break;
		case 5://����ְ��
			wm.find_Emp();
			break;
		case 6://����ְ��
			wm.sort_Emp();
			break;
		case 7://����ļ�
			wm.clean_File();
			break;
		default: //������Ĭ�������ѭ��
			system("cls");
			break;
		}
	}
		
	
	system("pause");
}