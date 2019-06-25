#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"Information.h"
#include"Date.h"
#include<vector>

class Staff: public Information, Date
{
private:
	double m_salary;
	vector<Staff*>m_staff;
public:
	vector<string*>inputName();
	vector<string*>inputAddress();
	vector<string*>inputNumber();
	vector<int*>inputAge();

	void infoAllStaff();
	string infoStaff();
};