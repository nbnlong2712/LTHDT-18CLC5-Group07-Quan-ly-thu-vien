#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<vector>
#include<string.h>
#include"Date.h"

class Book : public Date         // kế thừa class Date xử lý ngày mượn sách và ngày trả sách
{
private:
	string m_author, m_name;
	int m_code, m_soluong;
public:
	void inputName();
	void inputCode();
	void inputInfo();
	
	void dateBorrowed();        // nhập ngày, tháng, năm mượn sách (cho Borrower)
	void dateGiveBack();        // xuất ngày, tháng, năm trả sách (cho Borrower)

	string setName();
	string setAuthor();
	int setCode();
	int &setSoLuong();
	string &setName2(string);
	string &setAuthor2(string);
	int &setCode2(int);
	int &setSoLuong2(int);
	
	int setDay();
	int setMonth();
	int setYear();
	int &setDay2(int);
	int &setMonth2(int);
	int &setYear2(int);

	void infoBook();            // in ra thông tin của sách 
};