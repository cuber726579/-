#pragma once
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include"globalFile.h"
using namespace std;

//��ȡ����
pair<string, string> Pairing(string str);

class AppointFile
{
public:
	//��¼ԤԼ����
	int M_Size;

	//��¼�б� int Ϊ��¼���� map��ż�¼
	map<int, map<string, string>> mapAppoint;
	
	//Ĭ�Ϲ���
	AppointFile();

	//����ԤԼ��¼
	void updateAppoint();
};