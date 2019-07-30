#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Information.h"
#include"Date.h"
using namespace std;

class Librarian : public Information, Date
{
private:
	double m_salary;
	Date m_contract;
public:
	void inputName();
	void inputAddress();
	void intputSalary();
	void inputContract();
	Date extensionContract();
	void inputInfo();

	string setName();
	string setAddress();
	double setSalary();
	string &setName2(string);
	string &setAddress2(string);
	double &setSalary2(double);
	
	int setDay();
	int setMonth();
	int setYear();
	int &setDay2(int);
	int &setMonth2(int);
	int &setYear2(int);

	void infoLibrarian();
};