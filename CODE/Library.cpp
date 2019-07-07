#include"Library.h"

string chuan_hoa1(string k)
{
	string k1 = k;
	for (int i = 0; i < k.size(); i++)
	{
		k1[i] = toupper(k1[i]);
	}
	return k1;
}
void Library::inputNameLibrary()
{
	cout << "Enter library name: ";
	getline(cin, m_name);	
}

void Library::print()
{
	cout << "Library name: " << m_name << endl;
}

vector<Book*>Library::addBook()   //  BOOK
{
	Book*p = new Book;
	p->input();
	m_book.push_back(p);
	return m_book;
	delete p;
}
vector<Book*>Library::setAddBook()
{
	return m_book;
}
void Library::infoAllBook()
{
	for (int i = 0; i < m_book.size(); i++)
	{
		cout << i + 1 << ". ";
		m_book[i]->infoBook();
		cout << endl;
	}
}

void Library::searchNameBook(string k)
{
	int a = 0;
	for (int i = 0; i < m_book.size(); i++)
	{
		if (chuan_hoa1(k) == chuan_hoa1(m_book[i]->setName()))
		{
			m_book[i]->infoBook();
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}

void Library::searchAuthorBook(string k)
{
	int a = 0;
	for (int i = 0; i < m_book.size(); i++)
	{
		if (chuan_hoa1(k) == chuan_hoa1(m_book[i]->setAuthor()))
		{
			cout << "-" << m_book[i]->setName() << endl;
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}
void Library::searchCodeBook(int k)
{
	int a = 0;
	for (int i = 0; i < m_book.size(); i++)
	{
		if (k == m_book[i]->setCode())
		{
			m_book[i]->infoBook();
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}