#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Information.h"
#include"Date.h"
#include"Borrower.h"
using namespace std;

class Librarian : public Information, Date
{
private:
	double m_salary;
	Date m_contract;
	vector<Borrower*>&m_borrower_librarian;
public:
	void inputName();
	void inputAddress();
	void intputSalary();
	void inputContract();
	Date extensionContract();
	void inputInfo();
	vector<Borrower*>&setBorrowerLibrarian();

	void deleteLibraryCard(Borrower*);

	void info();
};