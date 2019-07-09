#include"Librarian.h"

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
	cout << "Enter date start contract: ";
	Date::input();
}

void Librarian::intputSalary()
{
	cout << "Enter salary: ";
	cin >> m_salary;
}

Date Librarian::extensionContract()
{
	int n = 180;
	Date a = m_contract.increase_n_days(m_day, m_month, m_year, n);
	return a;
}

void Librarian::info()
{
	cout << "-Name: " << m_name << endl;
	cout << "-Adrress: " << m_adr << endl;
	cout << endl;
	cout << "-Salary: " << m_salary << endl;
	cout << "-Start contract: ";
	this->output();
	cout << "-End contract: " << this->extensionContract().setDay() << "/" << this->extensionContract().setMonth() << "/" << this->extensionContract().setYear();
}