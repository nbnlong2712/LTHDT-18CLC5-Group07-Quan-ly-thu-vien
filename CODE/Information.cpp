#include"Information.h"

void Information::inputName()
{
	cout << "Enter your name: ";
	getline(cin, m_name);
}
void Information::inputAddress()
{
	cout << "Enter your address: ";
	getline(cin, m_adr);
}
void Information::inputNumber()
{
	cout << "Enter your number: ";
	getline(cin, m_number);
}
void Information::inputCode()
{
	cout << "Enter your code: ";
	cin >> m_code;
	while (m_code < 0 || m_code>99999)
	{
		cout << "Invalid! Enter again your code: ";
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
string Information::setNumber()
{
	string k = m_number;
	return k;
}
int Information::setCode()
{
	int k = m_code;
	return k;
}
void Information::inputAge()
{
	int k;
	cout << "Enter age: ";
	cin >> k;
	while (k < 0 || k>100)
	{
		cout << "Invalid! Enter again age: ";
		cin >> k;
	}
}
int Information::setAge()
{
	int k = m_age;
	return k;
}