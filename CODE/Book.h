#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<vector>
#include<string.h>
#include"Date.h"

class Book : public Date
{
private:
	string m_author, m_name;
	int m_code;
public:
	void input();
	void dateBorrowed();
	void dateGiveBack();

	string SetName();
	string setAuthor();
	int setCode();

	void infoBook();
};
