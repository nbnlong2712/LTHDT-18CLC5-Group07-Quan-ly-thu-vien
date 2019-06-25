#include"Book.h"

string chuan_hoa(string k)
{
	for (int i = 0; i < k.size(); i++)
		k[i] = toupper(k[i]);
	return k;
}

vector<string*>Book::inputName()
{
	vector<string*>m_book1;
	fstream fs("BookName.txt", ios::in);
	while (fs)
	{
		string*k = new string;
		getline(fs, *k, '\n');
		m_book1.push_back(k);
	}
	fs.close();
	return m_book1;
}
vector<string*>Book::inputAuthor()
{
	vector<string*>m_book1;
	fstream fs("BookAuthor.txt", ios::in);
	while (fs)
	{
		string*k = new string;
		getline(fs, *k, '\n');
		m_book1.push_back(k);
	}
	fs.close();
	return m_book1;
}
vector<string*>Book::inputOrigin()
{
	vector<string*>m_book1;
	fstream fs("BookOrigin.txt", ios::in);
	while (fs)
	{
		string*k = new string;
		getline(fs, *k, '\n');
		m_book1.push_back(k);
	}
	fs.close();
	return m_book1;
}
vector<int*>Book::inputAmounts()
{
	vector<int*>m_book1;
	fstream fs("BookAmounts.txt", ios::in);
	while (fs)
	{
		int*k = new int;
		fs >> *k;
		m_book1.push_back(k);
	}
	fs.close();
	return m_book1;
}
vector<int*>Book::inputCode()
{
	vector<int*>m_book1;
	fstream fs("BookCode.txt", ios::in);
	while (fs)
	{
		int*k = new int;
		fs >> *k;
		m_book1.push_back(k);
	}
	fs.close();
	return m_book1;
}
vector<string*>Book::inputCategory()
{
	vector<string*>m_book1;
	fstream fs("BookCategory.txt", ios::in);
	while (fs)
	{
		string*k = new string;
		getline(fs, *k, '\n');
		m_book1.push_back(k);
	}
	fs.close();
	return m_book1;
}
vector<string*>Book::inputLanguage()
{
	vector<string*>m_book1;
	fstream fs("BookLanguage.txt", ios::in);
	while (fs)
	{
		string*k = new string;
		getline(fs, *k, '\n');
		m_book1.push_back(k);
	}
	fs.close();
	return m_book1;
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
string Book::setOrigin()
{
	string k = m_origin;
	return k;
}
int Book::setAmounts()
{
	int k = m_amounts;
	return k;
}
int Book::setCode()
{
	int k = m_code;
	return k;
}
string Book::setCategory()
{
	string k = m_category;
	return k;
}
string Book::setLanguage()
{
	string k = m_language;
	return k;
}

void Book::infoAllBook()
{
	int n = inputName().size() - 1;
	for (int i = 0; i < n; i++)
	{
		Book*a = new Book;
		a->m_name = *inputName()[i];
		a->m_author = *inputAuthor()[i];
		a->m_origin = *inputOrigin()[i];
		a->m_amounts = *inputAmounts()[i];
		a->m_code = *inputCode()[i];
		a->m_category = *inputCategory()[i];
		a->m_language = *inputLanguage()[i];
		m_book.push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << "." << m_book[i]->m_name << ":" << endl;
		cout << " -Author  : " << m_book[i]->m_author << endl;
		cout << " -Origin  : " << m_book[i]->m_origin << endl;
		cout << " -Category: " << m_book[i]->m_category << endl;
		cout << " -Language: " << m_book[i]->m_language << endl;
		cout << " -Amounts : " << m_book[i]->m_amounts << endl;
		cout << " -Code    : " << m_book[i]->m_code << endl << endl;
	}
}

string Book::searchNameBook(string k)
{
	int a = 0;
	for (int i = 0; i < m_book.size(); i++)
	{
		if (chuan_hoa(k) == chuan_hoa(m_book[i]->m_name))
		{
			a = 1;
			return m_book[i]->m_name;
		}
	}
	if (a == 0)
	{
		return "Khong tim thay!";
	}
}

void Book::searchAuthorBook(string k)
{
	int a = 0;
	for (int i = 0; i < m_book.size(); i++)
	{
		if (chuan_hoa(k) == chuan_hoa(m_book[i]->m_author))
		{
			cout << m_book[i]->m_name << endl;
			a = 1;
		}
	}
	if (a == 0) cout << "Khong tim thay!";
}
void Book::searchOriginBook(string k)
{
	int a = 0;
	for (int i = 0; i < m_book.size(); i++)
	{
		if (chuan_hoa(k) == chuan_hoa(m_book[i]->m_origin))
		{
			cout << m_book[i]->m_name << endl;
			a = 1;
		}
	}
	if (a == 0) cout << "Khong tim thay!";
}
void Book::searchCategoryBook(string k)
{
	int a = 0;
	for (int i = 0; i < m_book.size(); i++)
	{
		if (chuan_hoa(k) == chuan_hoa(m_book[i]->m_category))
		{
			cout << m_book[i]->m_name << endl;
			a = 1;
		}
	}
	if (a == 0) cout << "Khong tim thay!";
}
void Book::searchCodeBook(int k)
{
	int a = 0;
	for (int i = 0; i < m_book.size(); i++)
	{
		if (k == m_book[i]->m_code)
		{
			cout << m_book[i]->m_name << endl;
			a = 1;
		}
	}
	if (a == 0) cout << "Khong tim thay!";
}
void Book::searchLanguageBook(string k)
{
	int a = 0;
	for (int i = 0; i < m_book.size(); i++)
	{
		if (chuan_hoa(k) == chuan_hoa(m_book[i]->m_language))
		{
			cout << m_book[i]->m_name << endl;
			a = 1;
		}
	}
	if (a == 0) cout << "Khong tim thay!";
}

void Book::infoBook(string k)
{
	for (int i = 0; i < m_book.size(); i++)
	{
		if (k == m_book[i]->m_name)
		{
			cout << endl << m_book[i]->m_name << ":" << endl;
			cout << " -Author  : " << m_book[i]->m_author << endl;
			cout << " -Origin  : " << m_book[i]->m_origin << endl;
			cout << " -Category: " << m_book[i]->m_category << endl;
			cout << " -Language: " << m_book[i]->m_language << endl;
			cout << " -Amounts : " << m_book[i]->m_amounts << endl;
			cout << " -Code    : " << m_book[i]->m_code << endl << endl;
		}
	}
}