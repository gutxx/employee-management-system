#include<iostream>
#include"manager.h"
using namespace std;


//���캯��
Manager::Manager(int id, string name, int did) {
	this->id = id;
	this->m_name = name;
	this->m_deptId = did;
}
//��ȡ������Ϣ
void Manager::showinfo() {
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->m_name
		<< "\t��λ:" << this->getDpetName()
		<< "\t��λְ������ϰ彻�������񣬲��·�������չ�" << endl;
}

//��ʾ��λ����
string Manager::getDpetName() {
	return string("����");
}

