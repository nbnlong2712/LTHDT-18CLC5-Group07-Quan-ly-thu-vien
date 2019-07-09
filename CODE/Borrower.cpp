#include"Borrower.h"

void Borrower::inputName()
{
	cin.ignore();
	Information::inputName();
}
void Borrower::inputAddress()
{
	Information::inputAddress();
}
void Borrower::inputCode()
{
	Information::inputCode();
}
void Borrower::inputDateCard()
{
	Date::input();
}
void Borrower::inputInfo()
{
	this->inputName();
	this->inputAddress();
	this->inputCode();
	cout << "Enter day renew card: ";
	this->inputDateCard();
}
void Borrower::dateExpire()
{
	Date a = this->increase_n_days(m_day, m_month, m_year, 180);
	cout << a.setDay() << "/" << a.setMonth() << "/" << a.setYear();
}

string Borrower::setName()
{
	string h = m_name;
	return h;
}
string Borrower::setAddress()
{
	string h = m_adr;
	return h;
}
int Borrower::setCode()
{
	int h = m_code;
	return h;
}
vector<Book*>&Borrower::setBorrowBook()
{
	return m_book_borrower;
}

void Borrower::infoBorrower()
{
	cout << "Name: " << m_name << endl;
	cout << "Address: " << m_adr << endl;
	cout << "Card code: " << m_code << endl;
	cout << "Date renew card: " << m_day << "/" << m_month << "/" << m_year << endl;
	cout << "Date expire card: ";
	this->dateExpire();
	cout << endl;
}