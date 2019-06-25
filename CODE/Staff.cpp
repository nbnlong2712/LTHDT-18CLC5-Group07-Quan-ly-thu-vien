#include"Staff.h"

vector<string*>Staff::inputName()
{
	vector<string*>m_staff1;
	fstream fs("StaffName.txt", ios::in);
	while (fs)
	{
		string*k = new string;
		getline(fs, *k, '\n');
		m_staff1.push_back(k);
	}
	fs.close();
	return m_staff1;
}
vector<string*>Staff::inputAddress()
{
	vector<string*>m_staff1;
	fstream fs("StaffAddress.txt", ios::in);
	while (fs)
	{
		string*k = new string;
		getline(fs, *k, '\n');
		m_staff1.push_back(k);
	}
	fs.close();
	return m_staff1;
}
vector<string*>Staff::inputNumber()
{
	vector<string*>m_staff1;
	fstream fs("StaffNumber.txt", ios::in);
	while (fs)
	{
		string*k = new string;
		getline(fs, *k, '\n');
		m_staff1.push_back(k);
	}
	fs.close();
	return m_staff1;
}
vector<int*>Staff::inputAge()
{
	vector<int*>m_staff1;
	fstream fs("StaffAge.txt", ios::in);
	while (fs)
	{
		int*k = new int;
		fs >> *k;
		m_staff1.push_back(k);
	}
	fs.close();
	return m_staff1;
}

void Staff::infoAllStaff()
{
	int n = inputName().size() - 1;
	for (int i = 0; i < n; i++)
	{
		Staff*f = new Staff;
		f->m_name = *inputName()[i];
		f->m_adr = *inputAddress()[i];
		f->m_number = *inputNumber()[i];
		f->m_age = *inputAge()[i];
		m_staff.push_back(f);
	}
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "." << m_staff[i]->m_name << ":" << endl;
		cout << "- " << m_staff[i]->m_adr << endl;
		cout << "- " << m_staff[i]->m_number << endl;
		cout << "- " << m_staff[i]->m_age << endl;
	}
}