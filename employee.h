#pragma once
#include<iostream>
#include"worker.h"
using namespace std;

class employee :public Worker
{
public:
	//���캯��
	employee(int id,string name,int did);
	//��ȡ������Ϣ
	virtual void showinfo();

	//��ʾ��λ����
	virtual string getDpetName();

};