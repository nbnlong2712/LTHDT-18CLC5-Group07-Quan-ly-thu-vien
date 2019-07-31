#include"Information.h"

void Information::inputName()             // Nhập tên
{
	cout << "Nhap ten: ";
	getline(cin, m_name);
	while (m_name.size() == 0)
	{
		cout << "-Khong co ky tu nao! Nhap lai: ";
		getline(cin, m_name);
	}
}
void Information::inputAddress()          // Nhập địa chỉ
{
	cout << "Nhap dia chi: ";
	getline(cin, m_adr);
	while (m_adr.size() == 0)
	{
		cout << "-Khong co ky tu nao! Nhap lai: ";
		getline(cin, m_adr);
	}
}
void Information::inputCode()            // Nhập mã số
{   
	cout << "Nhap ma so: ";
	cin >> m_code;
	while (m_code < 0 || m_code>99999)
	{
		cout << "Khong hop le! Nhap lai ma so: ";
		cin >> m_code;
	}
}

string Information::setName()
{
	string k = m_name;
	return k;
}
string Information::setAddress()
{
	string k = m_adr;
	return k;
}
int Information::setCode()
{
	int k = m_code;
	return k;
}
