#include<iostream>
#include"boss.h"
using namespace std;


//���캯��
Boss::Boss(int id, string name, int did) {
	this->id = id;
	this->m_name = name;
	this->m_deptId = did;
}
//��ȡ������Ϣ
void Boss::showinfo() {
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->m_name
		<< "\t��λ:" << this->getDpetName()
		<< "\t��λְ���·����������" << endl;
}

//��ʾ��λ����
string Boss::getDpetName() {
	return string("�ϰ�");
}

