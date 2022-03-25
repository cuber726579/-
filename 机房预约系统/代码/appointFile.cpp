#include"appointFile.h"

//��ȡ����
pair<string, string> Pairing(string str)
{
	int pos = str.find(":");
	if (pos == -1)
	{
		cout << "\tError ---- ԤԼ��������!" << endl;
		exit(1);
	}

	string key = str.substr(0, pos);
	string value = str.substr(pos + 1, str.size() - pos - 1);

	return make_pair(key, value);
}

//Ĭ�Ϲ���
AppointFile::AppointFile()
{
	ifstream ifs(APPOINT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "\tError ---- �ļ�������!" << endl;
		ifs.close();
		return;
	}

	map<string, string> m;

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	//�������� �����Ϊһ�������� : data:1
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
	//��ȡ��������
		pair<string, string> datePair = Pairing(date);
		m.insert(datePair);

	//��ȡ����ʱ���
		pair<string, string> intervalPair = Pairing(interval);
		m.insert(intervalPair);

	//��ȡѧ��
		pair<string, string> stuIdPair = Pairing(stuId);
		m.insert(stuIdPair);

	//��ȡѧ���û���
		pair<string, string> stuNamePair = Pairing(stuName);
		m.insert(stuNamePair);

	//��ȡ����Ļ������
		pair<string, string> roomIdPair = Pairing(roomId);
		m.insert(roomIdPair);

	//��ȡԤԼ״̬
		pair<string, string> statusPair = Pairing(status);
		m.insert(statusPair);

		this->mapAppoint.insert(make_pair(M_Size++, m));
		m.clear();
	}
	ifs.close();

	//���Դ�����
	//for (map<int, map<string, string>>::iterator it = mapAppoint.begin(); it != mapAppoint.end(); it++)
	//{
	//	cout << "�� " << it->first + 1 << " ��ԤԼ��¼ : ";
	//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << "key = " << mit->first << " value = " << mit->second << endl;
	//	}
	//	cout << endl;
	//}
}

//����ԤԼ��¼
void AppointFile::updateAppoint()
{
	if (!this->M_Size)
		return;

	ofstream ofs(APPOINT_FILE, ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cout << "\tError ---- �ļ�������!" << endl;
		ofs.close();
		return;
	}

	for (int i = 0; i < this->M_Size; i++)
	{
		ofs << "date:" << this->mapAppoint[i]["date"] << " ";
		ofs << "interval:" << this->mapAppoint[i]["interval"] << " ";
		ofs << "stuId:" << this->mapAppoint[i]["stuId"] << " ";
		ofs << "stuName:" << this->mapAppoint[i]["stuName"] << " ";
		ofs << "roomId:" << this->mapAppoint[i]["roomId"] << " ";
		ofs << "status:" << this->mapAppoint[i]["status"] << " ";
	}
}
