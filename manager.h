#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Manager :public Worker {
public:
	//���캯��
	Manager(int id, string name, int did);
	//��ȡ������Ϣ
	virtual void showinfo();

	//��ʾ��λ����
	virtual string getDpetName();

};