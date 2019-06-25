#pragma once
#include<iostream>
#include<string>
using namespace std;

class Information {
protected:
	string m_name, m_adr, m_number;
	int m_code, m_age;
public:
	void inputName();
	void inputAddress();
	void inputNumber();
	void inputCode();
	void inputAge();
	string setName();
	string setAddress();
	string setNumber();
	int setCode();
	int setAge();
};
