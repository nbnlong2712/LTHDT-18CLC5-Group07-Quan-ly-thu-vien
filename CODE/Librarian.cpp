#include"Librarian.h"

string chuan_hoa_librarian(string k)     // chuyển tất cả ký tự chuỗi k thành chữ thường
{
	string k1 = k;
	for (int i = 0; i < k.size(); i++)
	{
		k1[i] = tolower(k1[i]);
	}
	return k1;
}
void Librarian::inputName()
{
	Information::inputName();
}
void Librarian::inputAddress()
{
	Information::inputAddress();
}
void Librarian::inputContract()
{
	cout << "Nhap ngay bat dau hop dong: ";
	Date::input();
}
void Librarian::intputSalary()
{
	cout << "Nhap tien luong: ";
	cin >> m_salary;
}

Date Librarian::extensionContract()
{
	int n = 180;
	Date a = m_contract.increase_n_days(m_day, m_month, m_year, n);
	return a;
}
void Librarian::inputInfo()
{
	this->inputName();
	this->inputAddress();
	this->intputSalary();
	this->inputContract();
}

string Librarian::setName()
{
	return m_name;
}
string Librarian::setAddress()
{
	return m_adr;
}
double Librarian::setSalary()
{
	return m_salary;
}
string &Librarian::setName2(string k)
{
	m_name = k;
	return m_name;
}
string &Librarian::setAddress2(string k)
{
	m_adr = k;
	return m_adr;
}
double &Librarian::setSalary2(int k)
{
	m_salary = k;
	return m_salary;
}
int Librarian::setDay()
{
	return m_day;
}
int Librarian::setMonth()
{
	return m_month;
}
int Librarian::setYear()
{
	return m_year;
}
int &Librarian::setDay2(int k)
{
	m_day = k;
	return m_day;
}
int &Librarian::setMonth2(int k)
{
	m_month = k;
	return m_month;
}
int &Librarian::setYear2(int k)
{
	m_year = k;
	return m_year;
}

void Librarian::infoLibrarian()
{
	cout << "-Ten: " << m_name << endl;
	cout << "-Dia chi: " << m_adr << endl;
	cout << "-Luong: " << m_salary << endl;
	cout << "-Bat dau hop dong: ";
	this->output();
	cout << "-Ket thuc hop dong: " << this->extensionContract().setDay() << "/" << this->extensionContract().setMonth() << "/" << this->extensionContract().setYear();
}