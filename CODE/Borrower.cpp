#include"Borrower.h"

string chuan_hoa_Borrower(string k)
{
	string k1 = k;
	for (unsigned i = 0; i < k.size(); i++)
	{
		k1[i] = toupper(k1[i]);
	}
	return k1;
}
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
Date Borrower::dateExpire()
{
	Date a = this->increase_n_days(m_day, m_month, m_year, 180);
	cout << a.setDay() << "/" << a.setMonth() << "/" << a.setYear();
	return a;
}
Date Borrower::extensionDateCard()
{
	this->dateExpire() = this->increase_n_days(this->dateExpire().setDay(), this->dateExpire().setMonth(), this->dateExpire().setYear(), 180);
	return this->dateExpire();
}

string Borrower::SetName()
{	string h = m_name;
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
bool Borrower::borrowBook(Book*B)
{
	if (m_book_borrower.size() < 5)
	{
		int a = 0;
		for (unsigned i = 0; i < m_book_borrower.size(); i++)
			if (chuan_hoa_Borrower(B->setName()) == chuan_hoa_Borrower(m_book_borrower[i]->setName()))
				a = 1;
		if (a == 1)
			return false;
		else
		{
			m_book_borrower.push_back(B);
			return true;
		}
	}
	else
	{
		return false;
	}
}
void Borrower::giveBackBook(Book*B)
{
	for (unsigned i = 0; i < m_book_borrower.size(); i++)
	{
		if (chuan_hoa_Borrower(B->setName()) == chuan_hoa_Borrower(m_book_borrower[i]->setName()))
		{
			m_book_borrower[i] = m_book_borrower.back();
			m_book_borrower.pop_back();
		}
	}
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
