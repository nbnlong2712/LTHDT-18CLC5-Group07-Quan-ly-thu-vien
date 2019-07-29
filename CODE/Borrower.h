#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Information.h"
#include"Date.h"                    // không được include"Library.h" nếu không muốn bị lỗi
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
	void outputDateExpire();
	Date extensionDateCard(); // = dateExpire() + 180

	string setName();
	string setAddress();
	int setCode();
	int setDay();
	int setMonth();
	int setYear();
	int &setDay2(int);
	int &setMonth2(int);
	int &setYear2(int);
	string &setName2(string);
	string &setAddress2(string);
	int &setCode2(int);

	vector<Book*>&setBorrowBook();
	void borrowBook(Book*);                   // xử lý file
	void giveBackBook(Book*);                 // xử lý file

	void infoBorrower();
};