#pragma once
#include<iostream>
using namespace std;

//��ݳ������
class Identity
{
public:
	string M_UsrName;
	string M_Password;

	//�����˵� ���麯��
	virtual void operMenu() = 0;
};