#include"Book.h"

void Book::input()
{
	int n;
	cout << "Enter amounts of book: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		Book*k = new Book;
		cout << "Enter name: ";
		getline(cin, k->m_name);
		cout << "Enter author: ";
		getline(cin, k->m_author);
		cout << "Enter code: ";
		cin >> k->m_code;
		m_book.push_back(k);
	}
}
void Book::inputLibrary()
{
	m_library.inputNameLibrary();
}
void Book::infoAllBook()
{
	m_library.print();
	cout << endl;
	for (int i = 0; i < m_book.size(); i++)
	{
		cout <<i+1<<"-Name: " << m_book[i]->m_name << endl;
		cout << "-Author: " << m_book[i]->m_author << endl;
		cout << "-Code: " << m_book[i]->m_code << endl << endl;
	}
}