#include"Librarian.h"

string chuan_hoa_librarian(string K)
{
	string k1 = k;
	for (int i = 0; i < k.size(); i++)
	{
		k1[i] = toupper(k1[i]);
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
void Librarian::inputInfo()
{
	this->inputName();
	this->inputAddress();
	this->intputSalary();
	this->inputContract();
}
vector<Borrower*>&Librarian::setBorrowerLibrarian()
{
	return m_borrower_librarian;
}


void Librarian::deleteLibraryCard(Borrower*B)
{
	for (unsigned i = 0; i < m_borrower_librarian.size(); i++)
	{
		if (chuan_hoa_librarian(B->setName()) == chuan_hoa_librarian(m_borrower_librarian[i]->setName()))
		{
			m_borrower_librarian[i] = m_borrower_librarian.back();
			m_borrower_librarian.pop_back();
		}
	}
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
