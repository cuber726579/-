#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include"Identity.h"
#include"student.h"
#include"teacher.h"
#include"pc_classroom.h"
#include"globalFile.h"
using namespace std;

//��ӡѧ����Ϣ
void printStu(const Student&);

//��ӡ��ʦ��Ϣ
void printTeacher(const Teacher& t);

//����Ա��
class Administrator :public Identity
{
public:
	//ѧ���б�
	vector<Student> vecStu;

	//��ʦ�б�
	vector<Teacher> vecTeacher;

	//�����б�
	vector<PcClassroom> vecPc;

	//Ĭ�Ϲ���
	Administrator();

	//�вι���
	Administrator(string usrName, string pwd);

	//�����˵�
	virtual void operMenu();

	//����˺�
	void addAccount();

	//�鿴�����˺�
	void viewAccount_All();

	//��ӻ���
	void addPcClassroom();

	//�鿴������Ϣ
	void viewPcInfo();

	//���ԤԼ��¼
	void clearAppointment();

	//��ʼ����ʦ��ѧ���������б�
	void initVector();

	//���ѧ�Ż�ְ�����Ƿ��ظ�
	bool checkRepetition(int, int);
};