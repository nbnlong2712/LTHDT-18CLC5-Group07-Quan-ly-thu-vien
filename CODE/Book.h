#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Information.h"
#include<fstream>
#include<vector>
#include<string.h>
#include"Library.h"

class Book 
{
private:
	string m_author, m_name;
	int m_code;
	vector<Book*>m_book;
	Library m_library;
public:
	void input();
	void inputLibrary();

	void infoAllBook();
	
	string searchNameBook(string k);
	void searchAuthorBook(string k);
	void searchCodeBook(int code);

	void infoBook(string k);
};