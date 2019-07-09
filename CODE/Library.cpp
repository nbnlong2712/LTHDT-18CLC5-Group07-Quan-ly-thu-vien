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

// BOOK
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
bool Library::searchNameBook1(string k)
{
	int a = 0;
	for (int i = 0; i < m_book.size(); i++)
	{
		if (chuan_hoa1(k) == chuan_hoa1(m_book[i]->setName()))
			a = 1;
	}
	if (a == 1)return true;
	else return false;
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

// BORROWER
vector<Borrower*>Library::addBorrower()
{
	Borrower*p = new Borrower;
	p->inputInfo();
	m_borrower.push_back(p);
	return m_borrower;
	delete p;
}
vector<Borrower*>Library::setAddBorrower()
{
	return m_borrower;
}
void Library::infoAllBorrower()
{
	for (int i = 0; i < m_borrower.size(); i++)
	{
		cout << i + 1 << ". ";
		m_borrower[i]->infoBorrower();
		cout << endl;
	}
}
void Library::searchNameBorrower(string k)
{
	int a = 0;
	for (int i = 0; i < m_borrower.size(); i++)
	{
		if (chuan_hoa1(k) == chuan_hoa1(m_borrower[i]->setName()))
		{
			m_borrower[i]->infoBorrower();
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}
bool Library::searchNameBorrower1(string k)
{
	int a = 0;
	for (int i = 0; i < m_borrower.size(); i++)
	{
		if (chuan_hoa1(k) == chuan_hoa1(m_borrower[i]->setName()))
		{
			a = 1;
		}
	}
	if (a == 1) return true;
	else return false;
}
void Library::searchAddressBorrower(string k)
{
	int a = 0;
	for (int i = 0; i < m_borrower.size(); i++)
	{
		if (chuan_hoa1(k) == chuan_hoa1(m_borrower[i]->setAddress()))
		{
			cout << "-" << m_borrower[i]->setName() << endl;
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}
void Library::searchCodeBorrower(int k)
{
	int a = 0;
	for (int i = 0; i < m_borrower.size(); i++)
	{
		if (k == m_borrower[i]->setCode())
		{
			m_borrower[i]->infoBorrower();
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}
void Library::borowerBook(Borrower &B1, Book B2)
{
	for (int i = 0; i < m_borrower.size(); i++)
	{
		if (chuan_hoa1(B1.setName()) == chuan_hoa1(m_borrower[i]->setName()))
		{
			for (int j = 0; j < m_book.size(); j++)
			{
				if (chuan_hoa1(B2.setName()) == chuan_hoa1(m_book[j]->setName()))
					B1.setBorrowBook().push_back(m_book[j]);
			}
		}
	}
}
void Library::giveBackBook(Borrower&B1, Book B2)
{
	for (int i = 0; i < m_borrower.size(); i++)
	{
		if (chuan_hoa1(B1.setName()) == chuan_hoa1(m_borrower[i]->setName()))
		{
			for (int j = 0; j < B1.setBorrowBook().size(); j++)
			{
				if (chuan_hoa1(B2.setName()) == chuan_hoa1(B1.setBorrowBook()[j]->setName()))
				{
					B1.setBorrowBook()[j] = B1.setBorrowBook().back();
					B1.setBorrowBook().pop_back();
				}
			}
		}
	}
}
void Library::infoBorrower(Borrower B1)
{
	for (int i = 0; i < m_borrower.size(); i++)
	{
		if (chuan_hoa1(B1.setName()) == chuan_hoa1(m_borrower[i]->setName()))
		{
			B1.infoBorrower();
			cout << endl;
			if (B1.setBorrowBook().size() != 0)
			{
				for (int j = 0; j < B1.setBorrowBook().size(); j++)
				{
					cout << j + 1 << "." << B1.setBorrowBook()[j]->setName() << endl;
				}
			}
			else cout << "ko co sach!";
		}
	}
}
