#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Identity.h"
#include"appointFile.h"
using namespace std;

//��ʦ��
class Teacher :public Identity
{
public:
	int M_TeacherId;

	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int id,string usrName,string pwd);

	//�����˵�
	virtual void operMenu();

	//�鿴����ԤԼ
	void viewAppointment_All();

	//���ԤԼ
	void checkAppointment();
};
