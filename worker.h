#pragma once
#include<iostream>
using namespace std;

//ְ���������
class Worker {
public:
	//��ʾ������Ϣ
	virtual void showinfo() = 0;
	//Worker* next;
	//��ȡ��λ����
	virtual string getDpetName() = 0;
	//ְ�����
	int id;
	//ְ������
	string m_name;
	//���ű��
	int m_deptId;

};