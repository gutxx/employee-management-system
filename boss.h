#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class Boss :public Worker {
public:
	//���캯��
	Boss(int id, string name, int did);
	//��ȡ������Ϣ
	virtual void showinfo();

	//��ʾ��λ����
	virtual string getDpetName();

};