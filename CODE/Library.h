#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Borrower.h"
#include"Book.h"
#include"Librarian.h"
using namespace std;

class Library
{
private:
	string m_name;
	vector<Book*>m_book;
	vector<Borrower*>m_borrower;
public:
	void inputNameLibrary();
	void print();
// BOOK
	vector<Book*>addBook();                  
	vector<Book*>setAddBook();
	void infoAllBook();
	void searchNameBook(string k);
	bool searchNameBook1(string k);
	void searchAuthorBook(string k);
	void searchCodeBook(int);
// BORROWER
	vector<Borrower*>addBorrower();
	vector<Borrower*>setAddBorrower();
	void infoAllBorrower();
	void searchNameBorrower(string k);
	bool searchNameBorrower1(string k);
	void searchAddressBorrower(string k);
	void searchCodeBorrower(int);
	void borowerBook(Borrower&, Book);
	void giveBackBook(Borrower&, Book);
	void infoBorrower(Borrower);
};