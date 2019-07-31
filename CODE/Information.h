#pragma once
#include<iostream>
#include<string>
using namespace std;

class Information {
protected:
	string m_name, m_adr;             // để các lớp khác kế thừa
	int m_code;
public:
	void inputName();
	void inputAddress();
	void inputCode();
	string setName();
	string setAddress();
	int setCode();
};
