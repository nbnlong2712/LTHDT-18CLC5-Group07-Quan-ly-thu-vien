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
	 void info();
};