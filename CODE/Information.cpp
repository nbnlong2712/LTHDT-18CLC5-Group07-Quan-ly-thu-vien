#include"Information.h"

void Information::inputName()
{
	cout << "Enter name: ";
	getline(cin, m_name);
}
void Information::inputAddress()
{
	cout << "Enter address: ";
	getline(cin, m_adr);
}
void Information::inputCode()
{
	cout << "Enter code: ";
	cin >> m_code;
	while (m_code < 0 || m_code>99999)
	{
		cout << "Invalid! Enter again code: ";
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
