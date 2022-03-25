#include"administrator.h"

//��ӡѧ����Ϣ
void printStu(const Student& s)
{
	cout << "\tѧ�� : " << s.M_StuId << "\t�û��� : " << s.M_UsrName << endl;
}

//��ӡ��ʦ��Ϣ
void printTeacher(const Teacher& t)
{
	cout << "\tְ���� : " << t.M_TeacherId << "\t�û��� : " << t.M_UsrName << endl;
}

//Ĭ�Ϲ���
Administrator::Administrator()
{

}

//�вι���
Administrator::Administrator(string usrName, string pwd)
{
	this->M_UsrName = usrName;
	this->M_Password = pwd;
	this->initVector();
}

//�����˵�
void Administrator::operMenu()
{
	cout << "\t    ����Ա : " << this->M_UsrName << endl;
	cout << "\t��ǰѧ������Ϊ : " << vecStu.size() << endl;
	cout << "\t��ǰ��ʦ����Ϊ : " << vecTeacher.size() << endl;
	cout << "\t��ǰ��������Ϊ : " << vecPc.size() << endl;
	cout << "\t----------------------" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t|     1.����˺�     |" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t|     2.�鿴�˺�     |" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t|     3.��ӻ���     |" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t|     4.�鿴����     |" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t|     5.���ԤԼ     |" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t|     0.�˳���¼     |" << endl;
	cout << "\t|                    |" << endl;
	cout << "\t----------------------" << endl;
}

//����˺�
void Administrator::addAccount()
{
	int option;		//�����û�ѡ��
	cout << "1 -- ѧ��\t2 -- ��ʦ" << endl;
	cout << "����������˺����� : ";
	cin >> option;

	string idTip;	//��ʾѧ�Ż�ְ����
	string errorTip;//�ظ�ʱ��ʾѧ�Ż�ְ����

	string fileName;
	ofstream ofs;

	if (1 == option)
	{
		fileName = STU_FILE;
		idTip =  "������ѧ�� : ";
		errorTip = "ѧ���ظ�,���������� : ";
	}
	else if (2 == option)
	{
		fileName = TEACHER_FILE;
		idTip = "������ְ���� :";
		errorTip = "ְ�����ظ�,���������� : ";
	}
	else
	{
		cout << "\tError ---- ����ѡ����Ч,���ʧ��!" << endl;
		return;
	}

	ofs.open(fileName, ios::out | ios::app);

//��ȡ���˺���Ϣ
	int id;
	string usrName;
	string usrPwd;

	cout << idTip;
	while (true)
	{
		cin >> id;
		bool ret = checkRepetition(id, option);
		if (ret)	//�ظ�
			cout << errorTip;
		else	break;
	}

	cout << "�������û��� : ";
	cin >> usrName;

	cout << "���������� : ";
	cin >> usrPwd;

//���ļ�������˺���Ϣ
	ofs << id << " " << usrName << " " << usrPwd << endl;
	ofs.close();

//���б����������(���´��ļ��л�ȡ����)
	this->initVector();
	
	cout << "\t��ӳɹ�" << endl;
}

//�鿴�����˺�
void Administrator::viewAccount_All()
{
	int option;		//�����û�ѡ��
	cout << "1 -- ѧ��\t2 -- ��ʦ" << endl;
	cout << "������鿴�˺����� : ";
	cin >> option;

	if (1 == option)
	{
		if (!vecStu.size())
		{
			cout << "\t��ǰ��ѧ���˺�" << endl; 
			return;
		}
		cout << "\tѧ����Ϣ :" << endl;
		for_each(vecStu.begin(), vecStu.end(), printStu);
	}
	else if (2 == option)
	{
		if (!vecTeacher.size())
		{
			cout << "\t��ǰ����ʦ�˺�" << endl;
			return;
		}
		cout << "\t��ʦ��Ϣ :" << endl;
		for_each(vecTeacher.begin(), vecTeacher.end(), printTeacher);
	}
	else
	{
		cout << "\tError ---- ����ѡ����Ч,�鿴ʧ��!" << endl;
		return;
	}
}

//��ӻ���
void Administrator::addPcClassroom()
{
	int id;
	int capacity;

	cout << "������������ : ";
	while (true)
	{
		cin >> id;
		bool ret = checkRepetition(id, 3);
		if (ret)
			cout << "��������ظ�,���������� : ";
		else	break;
	}

	cout << "������������� : ";
	cin >> capacity;

	ofstream ofs(PC_FILE, ios::out | ios::app);
	ofs << id << " " << capacity << 0 << endl;	//0 --- ������ʼʱ��Ϊ δռ��
	ofs.close();

	this->initVector();
	cout << "\t��ӳɹ�" << endl;
}

//�鿴������Ϣ
void Administrator::viewPcInfo()
{
	if (!vecPc.size())
	{
		cout << "\t��ǰ�޻���" << endl;
		return;
	}
	else
	{
		cout << "\t������Ϣ :" << endl;
		for_each(vecPc.begin(), vecPc.end(), printPcInfo);
	}
}

//���ԤԼ��¼
void Administrator::clearAppointment()
{
	ofstream ofs(APPOINT_FILE, ios::trunc);
	ofs.close();

	cout << "\tԤԼ��ճɹ�!" << endl;
}

//��ʼ����ʦ ѧ�� �����б�
void Administrator::initVector()
{
//��ȡѧ����Ϣ
	vecStu.clear();
	ifstream ifs(STU_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "\tError ---- �ļ�������!" << endl;
		ifs.close();
		return;
	}

	Student stu;
	while (ifs >> stu.M_StuId && ifs >> stu.M_UsrName && ifs >> stu.M_Password)
		vecStu.push_back(stu);
	ifs.close();

//��ȡ��ʦ��Ϣ
	vecTeacher.clear();
	ifs.open(TEACHER_FILE, ios::in);
	if(!ifs.is_open())
	{
		cout << "\tError ---- �ļ�������!" << endl;
		ifs.close();
		return;
	}

	Teacher teacher;
	while (ifs >> teacher.M_TeacherId && ifs >> teacher.M_UsrName && ifs >> teacher.M_Password)
		vecTeacher.push_back(teacher);
	ifs.close();
//��ȡ������Ϣ
	vecPc.clear();
	ifs.open(PC_FILE, ios::in);
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

//���ѧ�š�ְ���š��������Ƿ��ظ�
bool Administrator::checkRepetition(int id, int idType)
{
	if (1 == idType)
	{//���ѧ��
		for (int i = 0; i < vecStu.size(); i++)
		{
			if (id == vecStu[i].M_StuId)
				return true;
		}
	}
	else if(2 == idType)
	{//���ְ����
		for (int i = 0; i < vecTeacher.size(); i++)
		{
			if (id == vecTeacher[i].M_TeacherId)
				return true;
		}
	}
	else if (3 == idType)
	{
		for (int i = 0; i < vecPc.size(); i++)
		{
			if (id == vecPc[i].M_PcId)
				return true;
		}
	}
	return false;
}
