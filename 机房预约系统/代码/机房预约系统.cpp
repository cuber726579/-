#include<iostream>
#include<string>
#include<fstream>
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"administrator.h"
#include"globalFile.h"
using namespace std;

void mainMenu(void);
void adminMenu(Identity*&);
void studentMenu(Identity*&);
void LoginIn(string, int);

//���˵�
void mainMenu(void)
{
	cout << "\t----------------------" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t|     1.ѧ������     |" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t|     2.��    ʦ     |" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t|     3.�� �� Ա     |" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t|     0.��    ��     |" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t----------------------" << endl;
}

//�������Ա�Ӳ˵�
void adminMenu(Identity*& administrator)
{
	cout << "\t��ӭ����Ա " << administrator->M_UsrName << " ��¼!" << endl;
	int option;		//�����û�ѡ��

	while (true)
	{
		administrator->operMenu();

	//������ָ��ǿתΪ����ָ��,�Ե�������ӿ�
		Administrator* admin = (Administrator*)administrator;

		cout << "����������ѡ�� : ";
		cin >> option;
		switch (option)
		{
			case 1:	//����˺�
				admin->addAccount();
				break;
			case 2:	//�鿴�����˺�
				admin->viewAccount_All();
				break;			
			case 3:	//��ӻ���
				admin->addPcClassroom();
				break;
			case 4:	//�鿴������Ϣ
				admin->viewPcInfo();
				break;
			case 5:	//���ԤԼ��¼
				admin->clearAppointment();
				break;
			case 0:	//�˳���¼
				delete admin;
				cout << "\t���˳���¼" << endl;
				return;
			default:
				cout << "\tError ---- ����ѡ����Ч!" << endl;
				break;
		}
		system("pause");
		system("cls");
	}
}

//����ѧ���Ӳ˵�
void studentMenu(Identity*& student)
{
	cout << "\t��ӭѧ�� " << student->M_UsrName << " ��¼!" << endl;
	int option;

	while (true)
	{
		student->operMenu();

		Student* stu = (Student*)student;

		cout << "����������ѡ�� : ";
		cin >> option;
		switch (option)
		{
		case 1:	//����ԤԼ
			stu->applyAppointment();
			break;
		case 2:	//�鿴����ԤԼ
			stu->viewAppointment_Own();
			break;
		case 3:	//�鿴����ԤԼ
			stu->viewAppointment_All();
			break;
		case 4:	//ȡ��ԤԼ
			stu->cancelAppointment();
			break;
		case 0:	//�˳���¼
			delete stu;
			cout << "\t���˳���¼" << endl;
			return;
		default:
			cout << "\tError ---- ����ѡ����Ч!" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

//������ʦ�Ӳ˵�
void teacherMenu(Identity*& teacher)
{
	cout << "\t��ӭ��ʦ " << teacher->M_UsrName << " ��¼!" << endl;
	int option;		//�����û�ѡ��
	while(true)
	{
		teacher->operMenu();

		Teacher*tea = (Teacher*)teacher;

		cout << "����������ѡ�� : ";
		cin >> option;
		switch (option)
		{
		case 1:	//�鿴����ԤԼ
			tea->viewAppointment_All();
			break;
		case 2:	//���ԤԼ
			tea->checkAppointment();
			break;
		case 0:	//�˳���¼
			delete tea;
			cout << "\t���˳���¼" << endl;
			return;
		default:
			cout << "\tError ---- ����ѡ����Ч!" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

//��¼����
void LoginIn(string fileName, int idType)
{
	Identity* usr;

	//�����ļ�
	ifstream ifs(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "\tError ---- �ļ�������!" << endl;
		ifs.close();
		return;
	}

	//�����û���Ϣ
	int id;
	string name;
	string pwd;

	if (1 == idType)
	{
		cout << "������ѧ�� : ";
		cin >> id;
	}
	else if (2 == idType)
	{
		cout << "������ְ���� : ";
		cin >> id;
	}
	
	cout << "�������û��� : ";
	cin >> name;

	cout << "���������� : ";
	cin >> pwd;

	if (1 == idType)
	{//ѧ�������֤
		int fileId;
		string fileName;
		string filePwd;

		while (ifs >> fileId && ifs >> fileName && ifs >> filePwd)
		{
			if (fileId == id && fileName == name && filePwd == pwd)
			{
				cout << "\tѧ����֤��¼�ɹ�!" << endl;
				usr = new Student(id, name, pwd);
				
				system("pause");
				system("cls");

				studentMenu(usr);

				return;
			}
		}
	}
	else if (2 == idType)
	{//��ʦ�����֤
		int fileId;
		string fileName;
		string filePwd;

		while (ifs >> fileId && ifs >> fileName && ifs >> filePwd)
		{
			if (fileId == id && fileName == name && filePwd == pwd)
			{
				cout << "\t��ʦ��֤��¼�ɹ�!" << endl;
				usr = new Teacher(id, name, pwd);

				system("pause");
				system("cls");

				teacherMenu(usr);

				return;
			}
		}
	}
	else
	{//����Ա�����֤
		string fileName;
		string filePwd;

		while (ifs >> fileName && ifs >> filePwd)
		{
			if (fileName == name && filePwd == pwd)
			{
				cout << "\t����Ա��֤��¼�ɹ�!" << endl;
				usr = new Administrator(name, pwd);

				system("pause");
				system("cls");

				adminMenu(usr);

				return;
			}
		}
	}

	cout << "\tError ---- ��֤��¼ʧ��!" << endl;
	return;
}

int main(void)
{
	int option;		//�����û�ѡ��

	while (true)
	{
		cout << "======== ��ӭ�������ԤԼϵͳ ========" << endl;
		mainMenu();

		cout << "����������ѡ�� : ";
		cin >> option;
		switch (option)
		{
		case 1:	//ѧ�����
			LoginIn(STU_FILE, 1);
			break;
		case 2:	//��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:	//����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:	//�˳�ϵͳ
			cout << "\t��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default:
			cout << "\tError ---- ����ѡ����Ч!" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}