#include"student.h"

//��ӡ������Ϣ
void printPcInfo(const PcClassroom& p)
{
	cout << "\t��� : " << p.M_PcId << "\t���� : " << p.M_Capacity << endl;
}

//Ĭ�Ϲ���
Student::Student()
{

}

//�вι��� ���� : ѧ�� �û��� ����
Student::Student(int id, string usrName, string pwd)
{
	M_StuId = id;
	M_UsrName = usrName;
	M_Password = pwd;

	vecPc.clear();
	ifstream ifs(PC_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "\tError ---- �ļ�������!" << endl;
		ifs.close();
		return;
	}

	PcClassroom classroom;
	while (ifs >> classroom.M_PcId && ifs >> classroom.M_Capacity)
		vecPc.push_back(classroom);
	ifs.close();
}

//�����˵�
void Student::operMenu()
{
	cout << "\t\tѧ�� : " << this->M_UsrName << endl;
	cout << "\t-----------------------" << endl;
	cout << "\t|                     |" << endl;
	cout << "\t|     1.����ԤԼ      |" << endl;
	cout << "\t|                     |" << endl;
	cout << "\t|     2.�鿴�ҵ�ԤԼ  |" << endl;
	cout << "\t|                     |" << endl;
	cout << "\t|     3.�鿴����ԤԼ  |" << endl;
	cout << "\t|                     |" << endl;
	cout << "\t|     4.ȡ��ԤԼ      |" << endl;
	cout << "\t|                     |" << endl;
	cout << "\t|     0.�˳���¼      |" << endl;
	cout << "\t|                     |" << endl;
	cout << "\t-----------------------" << endl;
}

//ԤԼ����
void Student::applyAppointment()
{
	int date,interval,room;

	cout << "\n1. ��һ  2. �ܶ�  3. ����  4.����  5.���� " << endl;
	cout << "��������������� : ";
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)	break;
		else
			cout << "����������Ч,���������� : ";
	}

	cout << "\n1 . ����\t2 . ����" << endl;
	cout << "�����������ʱ��� : ";
	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2)	break;
		else
			cout << "����������Ч,���������� : ";
	}

	cout << "\t������Ϣ :" << endl;
	for_each(vecPc.begin(), vecPc.end(), printPcInfo);
	cout << "����������Ļ������ : ";
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= vecPc.size())	break;
		else
			cout << "����������Ч,���������� : ";
	}

	ofstream ofs(APPOINT_FILE, ios::out | ios::app);
	ofs << "date:" << date << " "
		<< "interval:" << interval << " "
		<< "stuId:" << this->M_StuId << " "
		<< "stuName:" << this->M_UsrName << " "
		<< "roomId:" << room << " "
		<< "status:" << 1 << endl;	//1��ʾ״̬ �����
	ofs.close();

	cout << "\tԤԼ�ɹ�!" << endl;
}

//�鿴�Լ���ԤԼ
void Student::viewAppointment_Own()
{
	int flag = 0;	//��־�Ƿ��ҵ�ԤԼ��¼
	AppointFile af;

	if (!af.M_Size)
	{
		cout << "\t��ԤԼ��¼" << endl;
		return;
	}

	for (int i = 0; i < af.M_Size; i++)
	{
	//string������ c_str ��Ա������c++����ַ���ת��Ϊc�����ַ���
	//atoi�������ַ�����ת��Ϊ����
		if (this->M_StuId == atoi(af.mapAppoint[i]["stuId"].c_str()))
		{
			cout << "\t\t�� " << ++flag << " ����¼" << endl;
			cout << "ԤԼ����: ��" << af.mapAppoint[i]["date"];
			cout << " " << (af.mapAppoint[i]["interval"] == "1" ? "����" : "����");
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
	if (!flag)
		cout << "\tδ�ҵ�ԤԼ��¼" << endl;
}

//�鿴����ԤԼ
void Student::viewAppointment_All()
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

//ȡ������ԤԼ
void Student::cancelAppointment()
{
	AppointFile af;
	if (!af.M_Size)
	{
		cout << "\t��ԤԼ��¼" << endl;
		return;
	}

	vector<int> v;	//���ѧ���ļ�¼��(index)��Ӧ�����еı��
	int index = 0;	//��ǵ�ǰѧ���ļ�¼��
	for (int i = 0; i < af.M_Size; i++)
	{
		if (this->M_StuId == atoi(af.mapAppoint[i]["stuId"].c_str()))
			if ("1" == af.mapAppoint[i]["status"] || "2" == af.mapAppoint[i]["status"])
			{//ֻ��ȡ�� ����� �� ��˳ɹ� ��ԤԼ��¼
				if(0 == index)
					cout << "    ��ǰ��ȡ����ԤԼ : " << endl;
				v.push_back(i);

				cout << "\t\t�� " << ++index << " ����¼" << endl;
				cout << "ԤԼ����: ��" << af.mapAppoint[i]["date"];
				cout << " " << (af.mapAppoint[i]["interval"] == "1" ? "����" : "����");
				cout << "\t������: " << af.mapAppoint[i]["roomId"];

				string status = "\t״̬: ";
				if ("1" == af.mapAppoint[i]["status"])
					status += "�����";
				else if ("2" == af.mapAppoint[i]["status"])
					status += "ԤԼ�ɹ�";

				cout << status << endl << endl;
			}
	}

	if (!index)
	{
		cout << "\tδ�ҵ���ȡ����ԤԼ��¼" << endl;
		return;
	}

	int cancelNum;
	cout << "��������Ҫȡ����ԤԼ�� : ";
	while (true)
	{
		cin >> cancelNum;
		if (cancelNum >= 1 && cancelNum <= v.size())	break;
		else
			cout << "��������,���������� : ";
	}

	int option;
	cout << "\t1 --- ȷ��\t2 --- ȡ��" << endl;
	cout << "�Ƿ�ȷ��ȡ����ԤԼ : ";
	while (true)
	{
		cin >> option;
		if (option == 1 || option == 2)	break;
		else
			cout << "��������,���������� : ";
	}

	if (2 == option)
	{
		cout << "\t��ȡ��" << endl;
		return;
	}
	else
	{
	//�޸�״̬������
		af.mapAppoint[v[cancelNum-1]]["status"] = "0";
		af.updateAppoint();
		cout << "\t��ȡ��ѡ�е�ԤԼ��¼" << endl;
	}
}
