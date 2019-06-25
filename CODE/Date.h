#pragma once
#include<iostream>
#include<string>
using namespace std;

class Date
{
protected:
	int day, month, year;
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
