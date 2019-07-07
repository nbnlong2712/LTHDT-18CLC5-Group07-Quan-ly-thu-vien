#pragma once
#include<iostream>
#include<string>
using namespace std;

class Date
{
protected:
	int m_day, m_month, m_year;
public:
	void input();
	void output();
	int setDay();
	int setMonth();
	int setYear();
	void increase_n_days(int day, int month, int year, int n);
	void decrease_n_days(int day, int month, int year, int n);
	int compare(Date);
};
