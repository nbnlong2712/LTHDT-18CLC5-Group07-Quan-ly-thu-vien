#include"Librarian.h"

void Librarian::inputName()
{
	Information::inputName();
}

void Librarian::inputAddress()
{
	Information::inputAddress();
}

void Librarian::inputLibrary()
{
	m_library.inputNameLibrary();
}

void Librarian::inputContract()
{
	Date::input();
}

void Librarian::intputSalary()
{
	cout << "Enter salary: ";
	cin >> m_salary;
}

void Librarian::extensionContract()
{
	int n = 365;
	m_contract.increase_n_days(m_day, m_month, m_year, n);
}

void Librarian::info()
{
	cout <<"-Name: "<< m_name << endl;
	cout << "-Adrress: " << m_adr << endl;
	m_library.print();
	cout << endl;
	cout << "-Salary: " << m_salary << endl;
	cout << "-Start contract: ";
	this->output();
	cout << "-End contract: ";
	this->extensionContract();
}