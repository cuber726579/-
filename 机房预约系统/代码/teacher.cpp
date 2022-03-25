#include"teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int id, string usrName, string pwd)
{
	M_TeacherId = id;
	M_UsrName = usrName;
	M_Password = pwd;
}

void Teacher::operMenu()
{
	cout << "\t\t��ʦ : " << this->M_UsrName << endl;
	cout << "\t-----------------------" << endl;
	cout << "\t|                     |" << endl;
	cout << "\t|     1.�鿴ȫ��ԤԼ  |" << endl;
	cout << "\t|                     |" << endl;
	cout << "\t|     2.���ԤԼ      |" << endl;
	cout << "\t|                     |" << endl;
	cout << "\t|     0.ע����¼      |" << endl;
	cout << "\t|                     |" << endl;
	cout << "\t-----------------------" << endl;
}

void Teacher::viewAppointment_All()
{
	AppointFile af;
	if (!af.M_Size)
	{
		cout << "\t��ԤԼ��¼" << endl;
		return;
	}

	for (int i = 0; i < af.M_Size; i++)
	{
		cout << "\t\t�� " << i + 1 << " ����¼" << endl;
		cout << "ԤԼ����: ��" << af.mapAppoint[i]["date"];
		cout << " " << (af.mapAppoint[i]["interval"] == "1" ? "����" : "����");
		cout << "\tԤԼѧ��ѧ��: " << af.mapAppoint[i]["stuId"];
		cout << "\t������: " << af.mapAppoint[i]["roomId"];

		string status = "\t״̬: ";
		if ("0" == af.mapAppoint[i]["status"])
			status += "��ȡ��ԤԼ";
		else if ("1" == af.mapAppoint[i]["status"])
			status += "�����";
		else if ("2" == af.mapAppoint[i]["status"])
			status += "ԤԼ�ɹ�";
		else
			status += "ԤԼʧ��,���δͨ��";
		cout << status << endl << endl;
	}
}

void Teacher::checkAppointment()
{
	AppointFile af;
	if (!af.M_Size)
	{
		cout << "\t��ԤԼ��¼" << endl;
		return;
	}

	vector<int> v;
	int index = 0;
	for (int i = 0; i < af.M_Size; i++)
		if ("1" == af.mapAppoint[i]["status"])
		{
			if (0 == index)
				cout << "    ����˵�ԤԼ : " << endl;
			v.push_back(i);

			cout << "\t\t�� " << ++index << " ����¼" << endl;
			cout << "ԤԼ�û�ѧ��: " << af.mapAppoint[i]["stuId"];
			cout << "\tԤԼ����: ��" << af.mapAppoint[i]["date"];
			cout << " " << (af.mapAppoint[i]["interval"] == "1" ? "����" : "����");
			cout << "\t������: " << af.mapAppoint[i]["roomId"] << endl << endl;
		}

	if (!index)
	{
		cout << "\tδ�ҵ���Ҫ��˵�ԤԼ" << endl;
		return;
	}

	int checkNum;
	cout << "��������Ҫ��˵�ԤԼ�� : ";
	while (true)
	{
		cin >> checkNum;
		if (checkNum >= 1 && checkNum <= v.size())	break;
		else
			cout << "��������,���������� : ";
	}

	int option;
	cout << "\t1 --- ͨ��\t2 --- ��ͨ��" << endl;
	cout << "�Ƿ�ȷ��ͨ����ԤԼ : ";
	while (true)
	{
		cin >> option;
		if (option == 1 || option == 2)	break;
		else
			cout << "��������,���������� : ";
	}

	if (2 == option)
	{
		af.mapAppoint[v[checkNum - 1]]["status"] = "-1";
		af.updateAppoint();
		cout << "\tδͨ��ѡ�е�ԤԼ��¼" << endl;
	}
	else
	{
		//�޸�״̬������
		af.mapAppoint[v[checkNum - 1]]["status"] = "2";
		af.updateAppoint();
		cout << "\t��ͨ��ѡ�е�ԤԼ��¼" << endl;
	}
}
