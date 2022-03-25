#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include"Identity.h"
#include"pc_classroom.h"
#include"globalFile.h"
#include"appointFile.h"
using namespace std;

//��ӡ������Ϣ
void printPcInfo(const PcClassroom& p);

//ѧ����
class Student :public Identity
{
public:
	int M_StuId;

	//�����б�
	vector<PcClassroom> vecPc;

	//Ĭ�Ϲ���
	Student();

	//�вι��� ���� : ѧ�� �û��� ����
	Student(int id, string usrName, string pwd);

	//�����˵�
	virtual void operMenu();

	//ԤԼ����
	void  applyAppointment();

	//�жϻ����Ƿ�ԤԼ
	bool checkReserved(int roomid);

	//�鿴�Լ���ԤԼ
	void viewAppointment_Own();

	//�鿴����ԤԼ
	void viewAppointment_All();

	//ȡ��ԤԼ
	void cancelAppointment();
};