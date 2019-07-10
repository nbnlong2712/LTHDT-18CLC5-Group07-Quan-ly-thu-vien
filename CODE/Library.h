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
	Librarian*m_librarian;
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
	vector<Borrower*>addBorrower();            // Hàm này cũng dùng để tạo thẻ thư viện cho một đọc giả
	vector<Borrower*>setAddBorrower();
	void infoAllBorrower();
	void searchNameBorrower(string k);
	bool searchNameBorrower1(string k);
	void searchAddressBorrower(string k);
	void searchCodeBorrower(int);
	void infoBorrower(Borrower);
// LIBRARIAN
	void addLibrarian();
	Librarian*setLibrarian();
};