#include<iostream>
#include"employee.h"
using namespace std;


//���캯��
employee::employee(int id,string name,int did) {
	this->id = id;
	this->m_name = name;
	this->m_deptId = did;
}
//��ȡ������Ϣ
void employee::showinfo() {
	cout << "ְ����ţ�" << this->id
		<< "\tְ��������" << this->m_name
		<< "\t��λ:" << this->getDpetName() 
		<<"\t��λְ����ɾ�����������" << endl;
 }

//��ʾ��λ����
string employee::getDpetName() {
	return string("Ա��");
}

