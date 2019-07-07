#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Book.h"
#include"Librarian.h"
#include"Borrower.h"
using namespace std;

class Library
{
private:
	string m_name;
	vector<Book*>m_book;
	//vector<Librarian*>m_librarian;
public:
	void inputNameLibrary();
	void print();

	vector<Book*>addBook();
	vector<Book*>setAddBook();
	void infoAllBook();

	void searchNameBook(string k);
	void searchAuthorBook(string k);
	void searchCodeBook(int);
};
