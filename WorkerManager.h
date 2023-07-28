#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"
#define FILENAME "empfile.txt"

//��C++���棬ÿһ��������ͨ��thisָ���������Լ��ĵ�ַ,��Ԫ����û��thisָ�룬��Ա������
class workerManager {
public:
	//���캯��
	workerManager();

	//չʾ�˵�
	void Show_menu();

	//�˳�ϵͳ
	void exitSystem();

	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker ** m_EmpArray; //����ָ�� ָ��ָ���ָ��
	//���ְ��
	void add_emp();
	//ͳ������
	int get_EmpNum();
	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsEmpty=false;
	//��ʼ��Ա��
	void init_Emp();
	
	//��ʾְ��
	void show_Emp();
	//���ְ���Ƿ����
	int isExist(string name);

	//ɾ��ְ��
	void del_Emp();

	//�޸�ְ��
	void mod_Emp();

	//����Ա��
	void find_Emp();

	//����ְ��
	void sort_Emp();

	//����ļ�
	void clean_File();

	//��������
	~workerManager();
};