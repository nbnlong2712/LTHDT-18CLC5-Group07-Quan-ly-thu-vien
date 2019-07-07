#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Information.h"
#include"Date.h"
using namespace std;
#include"Library.h"

class Librarian : public Information, Date
{
private:
	Library m_library;
	double m_salary;
	Date m_contract;
public:
	 void inputName();
	 void inputAddress();
	 void inputLibrary();
	 void intputSalary();
	 void inputContract();
	 void extensionContract();
	 void info();
};