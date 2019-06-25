#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Information.h"
#include"Date.h"
#include<vector>

class Borrower:public Information, Date
{
private:
	string m_job, m_job_address;
	vector<Borrower*>m_borrower;
public:
};