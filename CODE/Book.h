#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Information.h"
#include<fstream>
#include<vector>
#include<string.h>

class Book 
{
private:
	string m_category, m_author, m_language, m_origin, m_name;
	int m_code;
	int m_amounts;
	vector<Book*>m_book;
public:
	vector<string*>inputName();
	vector<string*>inputAuthor();
	vector<string*>inputOrigin();
	vector<int*>inputAmounts();
	vector<int*>inputCode();
	vector<string*>inputCategory();
	vector<string*>inputLanguage();
	
	string setName();
	string setAuthor();
	string setOrigin();
	int setAmounts();
	int setCode();
	string setCategory();
	string setLanguage();

	void infoAllBook();
	
	string searchNameBook(string k);

	

	void searchAuthorBook(string k);
	void searchOriginBook(string k);
	void searchCategoryBook(string k);
	void searchLanguageBook(string k);
	void searchCodeBook(int code);

	void infoBook(string k);
};