#include "WorkerManager.h"
using namespace std;
#include<iostream>
#include<fstream>
workerManager::workerManager() {

	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;		//直接退出
	}
	//文件存在，但没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;		//直接退出
	}
	//当文件存在，且记录着数据,这里只检测数字，再save函数中自动将数字换成字符串类型，所以为0；
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据存到数组中
	this->init_Emp();
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号： " << this->m_EmpArray[i]->id
	//		<< "姓名： " << this->m_EmpArray[i]->m_name
	//		<< "部门编号： " << this->m_EmpArray[i]->m_deptId << endl;
	//}
	////初始化属性
	//this->m_EmpNum = 0;
	//this->m_EmpArray = NULL;
}
//显示菜单
void workerManager::Show_menu() {
	cout << "*********************************************" << endl;
	cout << "********欢迎使用职工管理系统*******" << endl;
	cout << "*********0、退出管理程序************" << endl;
	cout << "*********1、增加职工信息************" << endl;
	cout << "*********2、显示职工信息************" << endl;
	cout << "*********3、删除离职员工************" << endl;
	cout << "*********4、修改职工信息************" << endl;
	cout << "*********5、查找职工信息************" << endl;
	cout << "*********6、按照编号排序************" << endl;
	cout << "*********7、清空所有文档************" << endl;
	cout << "**********************************************" << endl;
	cout << endl;
}
//添加职工
void workerManager::add_emp() {
	cout << "请输入添加的职工数量：" << endl;
	int add_num =0;//保存用户的输入数量
	cin >> add_num;

	if (add_num>0)
	{	//	添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + add_num;//新空间人数=原来记录人数+新增人数
		//开辟新空间
		Worker* *newspace=new Worker *[newSize];//(一级指针下还有几个成员变量，所以用二级指针来定义数组)
		//指向数组地址的指针的指针（数组地址的指针的地址，后面用到）
		//数组的地址一直不变，只是将指向数组地址的地址改变，并且数组长度动态变化
		//将原来空间下的数据，拷贝到新空间下
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
			int dSelect;		//部门选择

			cout << "请输入第 " << i + 1 << "个新职工编号:" << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << "个新职工姓名:" << endl;
			cin >> name;

			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			//将创建的职工指针，保存到数组中
			newspace[this->m_EmpNum + i] = worker;//链表
		}
		//释放原有的空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newspace;//（与之前呼应,重新指向）
		//更新新的职工人数
		this->m_EmpNum = newSize;
		//更新职工不为空
		this->m_FileIsEmpty = false;

		//提示添加成功
		cout << "成功添加 " << add_num << "名新职工" << endl;
		//保存数据到文件中
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
	}
	//按任意键清屏后，返回上级目录
	system("pause");
	system("cls");
}
//统计文件中人数
int workerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件
	int id;
	string name;
	int did;
	//string dname;
	int num = 0;
	while (ifs>>id && ifs>>name && ifs>>did)
	{
		//统计人数
		num++;
	}
	ifs.close();
	return num;
}

//保存文件
void workerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//写文件

	for (int i = 0; i < this->m_EmpNum; i++)
	{//"."成员运算符，优先级最高
		ofs << (*m_EmpArray[i]).id << "  "
			<< this->m_EmpArray[i]->m_name << "  "
			<< this->m_EmpArray[i]->m_deptId << endl;
	}
	ofs.close();
}

//初始化员工
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

		if (did==1)//普工
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
	//关闭文件
	ifs.close();
}

//显示职工
void workerManager::show_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");

}

//检测职工是否存在
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


//删除职工
void workerManager::del_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{//按职工姓名删除
		//Worker* p,*j;
		//int i = 0;
		cout << "请输入要删除人的姓名" << endl;
		string name;
		cin >> name;
		int index=this->isExist(name);//接收返回值
		if (index!=-1)//说明该员工存在
		{
		//	j = m_EmpArray[i];//让j指针指向首地址
		//	p = j->next;//p指针指向j的next
		//	for (p;p<m_EmpArray[m_EmpNum]; p++)
		//	{
		//		if (p->m_name==name)
		//		{
		//			j->next = p->next;
		//			free(p);//清除p指针

		//			break;			//continue语句提前结束本次循环，并且执行下次循环；break是终止循环
		//		}
		//		j++;
		//	}
			for (int i=index; i< m_EmpNum; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			m_EmpNum--;//更新数组人员个数，减一
			//delete m_EmpArray[m_EmpNum-1];
			//数据同步到更新文件中
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该员工" <<endl;
		}
	}
}

//修改职工
void workerManager::mod_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		string name;
		cout << "请输入要修改的职工的姓名：" << endl;
		cin >> name;
		int ret = this->isExist(name);
		if (ret!=-1)
		{
			//查找该员工
			delete this->m_EmpArray[ret];//先删除再添加
			int newid = 0;
			string newname = "";
			int newdid = 0;
			cout << "查到为" << name << "的员工，请输入新职工号：" << endl;
			cin >> newid;

			//cout << "请输入新姓名" << endl;
			//cin >> newname;

			cout << "请输入新岗位" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			//更新数据到数组中
			this->m_EmpArray[ret] = worker;

			//保存到文件
			this->save();
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "该人不存在" << endl;
		}

	}
	system("pause");
	system("cls");
}

//查找员工
void workerManager::find_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		//如果重名，改为用id号查找，修改isExist函数
		string name;
		cout << "请输入要查找的员工" << endl;
		cin >> name;
		int find = isExist(name);
		if (find!=-1)
		{
			cout << "找到该员工" << endl;
			cout << "该员工编号为" << this->m_EmpArray[find]->id << endl;
			cout << "信息如下：" << endl;
			m_EmpArray[find]->showinfo();
			/*之前用swith函数将worker地址传进了
			m_EmpArray数组，所以数组可以直接调用（调用显示信息接口）*/
		}
		else
		{
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序职工
void workerManager::sort_Emp() {
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{//(冒泡排序：升序 )，选择升序
		for (int i = 0; i < m_EmpNum; i++)
		{
			bool flag = false;
			//int min = i;//定义一个最小值点
			for (int j = m_EmpNum-1; j>i; j--)
			{
				if (m_EmpArray[j]->id<m_EmpArray[j-1]->id)
				{
					//min = j;//将最小值的下标赋给min
					Worker* temp;
					temp = m_EmpArray[j - 1];
					m_EmpArray[j - 1]=m_EmpArray[j];
					m_EmpArray[j]=temp;
					//flag = true;
				}
				if (flag==false)
				{
					return;//若本次遍历没有发生改变，则有序
				}
			}
			//每轮找出一个最小的值和i交换
		/*	if (i!=min)
			{
					Worker* temp;
					temp = m_EmpArray[min];
					m_EmpArray[min]=m_EmpArray[i];
					m_EmpArray[i]=temp;
			}*/
		}
		this->save();
		cout << "完成员工排序" << endl;

	}
	system("pause");
	system("cls");
}

//清空文件
void workerManager::clean_File() {
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int sure = 0;
	cin >> sure;
	if (sure==1)
	{
		//打开模式 iOS：：trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		//覆盖存在的文件 即如果原来文件中有数据原来的数据就被清空了权，
		//清空后再写入就可以了
		ofs.close();
		//虽然文件删除了，但堆区上的指针没释放，下面为释放堆区指针操作
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
			m_FileIsEmpty = true;//将文件改为空标志
		}
		cout << "文件清空成功" << endl;
	}
	else
	{
		cout << "您已返回" << endl;
		return;
	}
	system("pause");
	system("cls");
}

//退出系统
void workerManager::exitSystem(){
	{
		cout << "欢迎下次使用" << endl;
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

