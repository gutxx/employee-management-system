#include "WorkerManager.h"
using namespace std;
#include<iostream>
#include<fstream>
workerManager::workerManager() {

	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;		//ֱ���˳�
	}
	//�ļ����ڣ���û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;		//ֱ���˳�
	}
	//���ļ����ڣ��Ҽ�¼������,����ֻ������֣���save�������Զ������ֻ����ַ������ͣ�����Ϊ0��
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݴ浽������
	this->init_Emp();
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ� " << this->m_EmpArray[i]->id
	//		<< "������ " << this->m_EmpArray[i]->m_name
	//		<< "���ű�ţ� " << this->m_EmpArray[i]->m_deptId << endl;
	//}
	////��ʼ������
	//this->m_EmpNum = 0;
	//this->m_EmpArray = NULL;
}
//��ʾ�˵�
void workerManager::Show_menu() {
	cout << "*********************************************" << endl;
	cout << "********��ӭʹ��ְ������ϵͳ*******" << endl;
	cout << "*********0���˳��������************" << endl;
	cout << "*********1������ְ����Ϣ************" << endl;
	cout << "*********2����ʾְ����Ϣ************" << endl;
	cout << "*********3��ɾ����ְԱ��************" << endl;
	cout << "*********4���޸�ְ����Ϣ************" << endl;
	cout << "*********5������ְ����Ϣ************" << endl;
	cout << "*********6�����ձ������************" << endl;
	cout << "*********7����������ĵ�************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}
//���ְ��
void workerManager::add_emp() {
	cout << "��������ӵ�ְ��������" << endl;
	int add_num =0;//�����û�����������
	cin >> add_num;

	if (add_num>0)
	{	//	���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + add_num;//�¿ռ�����=ԭ����¼����+��������
		//�����¿ռ�
		Worker* *newspace=new Worker *[newSize];//(һ��ָ���»��м�����Ա�����������ö���ָ������������)
		//ָ�������ַ��ָ���ָ�루�����ַ��ָ��ĵ�ַ�������õ���
		//����ĵ�ַһֱ���䣬ֻ�ǽ�ָ�������ַ�ĵ�ַ�ı䣬�������鳤�ȶ�̬�仯
		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i <this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < add_num; i++)
		{
			int id;
			string name;
			int dSelect;		//����ѡ��

			cout << "������� " << i + 1 << "����ְ�����:" << endl;
			cin >> id;

			cout << "������� " << i + 1 << "����ְ������:" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;

			default:
				break;
			}
			//��������ְ��ָ�룬���浽������
			newspace[this->m_EmpNum + i] = worker;//����
		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newspace;//����֮ǰ��Ӧ,����ָ��
		//�����µ�ְ������
		this->m_EmpNum = newSize;
		//����ְ����Ϊ��
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ���� " << add_num << "����ְ��" << endl;
		//�������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	//������������󣬷����ϼ�Ŀ¼
	system("pause");
	system("cls");
}
//ͳ���ļ�������
int workerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�
	int id;
	string name;
	int did;
	//string dname;
	int num = 0;
	while (ifs>>id && ifs>>name && ifs>>did)
	{
		//ͳ������
		num++;
	}
	ifs.close();
	return num;
}

//�����ļ�
void workerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д�ļ�

	for (int i = 0; i < this->m_EmpNum; i++)
	{//"."��Ա����������ȼ����
		ofs << (*m_EmpArray[i]).id << "  "
			<< this->m_EmpArray[i]->m_name << "  "
			<< this->m_EmpArray[i]->m_deptId << endl;
	}
	ofs.close();
}

//��ʼ��Ա��
void workerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;
	int index = 0;
	while (ifs>>id  && ifs>>name && ifs>>did)
	{
		Worker* worker = NULL;

		if (did==1)//�չ�
		{
			worker = new employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else if (did == 3)
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	//�ر��ļ�
	ifs.close();
}

//��ʾְ��
void workerManager::show_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");

}

//���ְ���Ƿ����
int workerManager::isExist(string name) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_name==name)
		{
			index = i;
			break;
		}
	}
	return index;

}


//ɾ��ְ��
void workerManager::del_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{//��ְ������ɾ��
		//Worker* p,*j;
		//int i = 0;
		cout << "������Ҫɾ���˵�����" << endl;
		string name;
		cin >> name;
		int index=this->isExist(name);//���շ���ֵ
		if (index!=-1)//˵����Ա������
		{
		//	j = m_EmpArray[i];//��jָ��ָ���׵�ַ
		//	p = j->next;//pָ��ָ��j��next
		//	for (p;p<m_EmpArray[m_EmpNum]; p++)
		//	{
		//		if (p->m_name==name)
		//		{
		//			j->next = p->next;
		//			free(p);//���pָ��

		//			break;			//continue�����ǰ��������ѭ��������ִ���´�ѭ����break����ֹѭ��
		//		}
		//		j++;
		//	}
			for (int i=index; i< m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			m_EmpNum--;//����������Ա��������һ
			//delete m_EmpArray[m_EmpNum-1];
			//����ͬ���������ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���Ա��" <<endl;
		}
	}
}

//�޸�ְ��
void workerManager::mod_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		string name;
		cout << "������Ҫ�޸ĵ�ְ����������" << endl;
		cin >> name;
		int ret = this->isExist(name);
		if (ret!=-1)
		{
			//���Ҹ�Ա��
			delete this->m_EmpArray[ret];//��ɾ�������
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "�鵽Ϊ" << name << "��Ա������������ְ���ţ�" << endl;
			cin >> newid;

			//cout << "������������" << endl;
			//cin >> newname;

			cout << "�������¸�λ" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> newdid;

			Worker* worker = NULL;
			switch (newdid)
			{
			case 1:
				worker = new employee(newid, name, newdid);
				break;
			case 2:
				worker = new Manager(newid, name, newdid);
				break;
			case 3:
				worker = new Boss(newid, name, newdid);
				break;
			default:
				break;
			}
			//�������ݵ�������
			this->m_EmpArray[ret] = worker;

			//���浽�ļ�
			this->save();
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "���˲�����" << endl;
		}

	}
	system("pause");
	system("cls");
}

//����Ա��
void workerManager::find_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		//�����������Ϊ��id�Ų��ң��޸�isExist����
		string name;
		cout << "������Ҫ���ҵ�Ա��" << endl;
		cin >> name;
		int find = isExist(name);
		if (find!=-1)
		{
			cout << "�ҵ���Ա��" << endl;
			cout << "��Ա�����Ϊ" << this->m_EmpArray[find]->id << endl;
			cout << "��Ϣ���£�" << endl;
			m_EmpArray[find]->showinfo();
			/*֮ǰ��swith������worker��ַ������
			m_EmpArray���飬�����������ֱ�ӵ��ã�������ʾ��Ϣ�ӿڣ�*/
		}
		else
		{
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
void workerManager::sort_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{//(ð���������� )��ѡ������
		for (int i = 0; i < m_EmpNum; i++)
		{
			bool flag = false;
			//int min = i;//����һ����Сֵ��
			for (int j = m_EmpNum-1; j>i; j--)
			{
				if (m_EmpArray[j]->id<m_EmpArray[j-1]->id)
				{
					//min = j;//����Сֵ���±긳��min
					Worker* temp;
					temp = m_EmpArray[j - 1];
					m_EmpArray[j - 1]=m_EmpArray[j];
					m_EmpArray[j]=temp;
					//flag = true;
				}
				if (flag==false)
				{
					return;//�����α���û�з����ı䣬������
				}
			}
			//ÿ���ҳ�һ����С��ֵ��i����
		/*	if (i!=min)
			{
					Worker* temp;
					temp = m_EmpArray[min];
					m_EmpArray[min]=m_EmpArray[i];
					m_EmpArray[i]=temp;
			}*/
		}
		this->save();
		cout << "���Ա������" << endl;

	}
	system("pause");
	system("cls");
}

//����ļ�
void workerManager::clean_File() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int sure = 0;
	cin >> sure;
	if (sure==1)
	{
		//��ģʽ iOS����trunc �������ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		//���Ǵ��ڵ��ļ� �����ԭ���ļ���������ԭ�������ݾͱ������Ȩ��
		//��պ���д��Ϳ�����
		ofs.close();
		//��Ȼ�ļ�ɾ���ˣ��������ϵ�ָ��û�ͷţ�����Ϊ�ͷŶ���ָ�����
		if (this->m_EmpArray !=NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]!=NULL)
				{
					delete m_EmpArray[i];
				}
			}
			m_EmpNum = 0;
			delete[] m_EmpArray;
			m_EmpArray = NULL;
			m_FileIsEmpty = true;//���ļ���Ϊ�ձ�־
		}
		cout << "�ļ���ճɹ�" << endl;
	}
	else
	{
		cout << "���ѷ���" << endl;
		return;
	}
	system("pause");
	system("cls");
}

//�˳�ϵͳ
void workerManager::exitSystem(){
	{
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		exit(0);
	}
}

workerManager::~workerManager() {
	if (this->m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

