#pragma once
#include<iostream>
#include<string>
#include"Information.h"
#include"Date.h"                    
#include"Book.h"
using namespace std;

class Borrower: public Information, Date
{
private:
	vector<Book*>m_book_borrower;
public: 
	void inputName();
	void inputAddress();
	void inputCode();
	void inputDateCard();
	void inputInfo();
	Date dateExpire();
	Date extensionDateCard();

	string SetName();
	string setAddress();
	int setCode();
	vector<Book*>&setBorrowBook();
	bool borrowBook(Book*);
	void giveBackBook(Book*);

	void infoBorrower();
};
 