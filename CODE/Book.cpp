#include"Book.h"

string chuan_hoa(string k)
{
	string k1 = k;
	for (int i = 0; i < k.size(); i++)
	{
		k1[i] = toupper(k1[i]);
	}
	return k1;
}
void Book::input()
{
	cin.ignore();
	cout << "Enter name: ";
	getline(cin, m_name);
	cout << "Enter author: ";
	getline(cin, m_author);
	cout << "Enter code: ";
	cin >> m_code;
}
void Book::dateBorrowed()
{
	cout << "Enter date borrow: ";
	Date::input();
}
void Book::dateGiveBack()
{
	Date a = this->increase_n_days(m_day, m_month, m_year, 60);
	cout << a.setDay() << "/" << a.setMonth() << "/" << a.setYear();
}

string Book::setName()
{
	string k = m_name;
	return k;
}
string Book::setAuthor()
{
	string k = m_author;
	return k;
}
int Book::setCode()
{
	int k = m_code;
	return k;
}

void Book::infoBook()
{
	cout << "-Name: " << m_name << endl;
	cout << "-Author: " << m_author << endl;
	cout << "-Code: " << m_code << endl << endl;
}