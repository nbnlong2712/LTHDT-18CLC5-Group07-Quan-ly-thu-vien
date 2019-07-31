#include"Date.h"


void Date::input()
{
	cin >> m_day;
	cin >> m_month;
	cin >> m_year;
	while (m_year < 0)
	{
		cout << " - Nhap lai nam: ";
		cin >> m_year;
	}
	while (m_month < 1 || m_month>12)
	{
		cout << " - Nhap lai thang: ";
		cin >> m_month;
	}
	while (m_day < 1 || m_day>31)
	{
		cout << " - Nhap lai ngay: ";
		cin >> m_day;
	}
	if ((m_year % 4 == 0 && m_year % 400 == 0) || (m_year % 4 == 0 && m_year % 100 != 0)) // Leap year
	{
		while (m_month == 2 && (m_day < 1 || m_day>29))
		{
			cout << " - Nhap lai ngay: ";
			cin >> m_day;
		}
	}
	else if ((m_year % 4 == 0 && m_year % 100 == 0 && m_year % 400 != 0) || m_year % 4 != 0)   // Normal year
	{
		while (m_month == 2 && (m_day < 1 || m_day>28))
		{
			cout << " - Nhap lai ngay: ";
			cin >> m_day;
		}
	}
	if (m_month != 2 && ((m_month > 0 && m_month < 7 && m_month % 2 == 0) || (m_month > 7 && m_month <= 12 && m_month % 2 != 0)))
	{
		while (1 > m_day || m_day > 30)
		{
			cout << " - Nhap lai ngay: ";
			cin >> m_day;
		}
	}
	else if (m_month != 2 && ((m_month > 0 && m_month < 8 && m_month % 2 != 0) || (m_month > 7 && m_month <= 12 && m_month % 2 == 0)))
	{
		while (1 > m_day || m_day > 31)
		{
			cout << " - Nhap lai ngay: ";
			cin >> m_day;
		}
	}
}

int Date::setDay()
{
	return m_day;
}
int Date::setMonth()
{
	return m_month;
}
int Date::setYear()
{
	return m_year;
}

void Date::output()
{
	cout << m_day << "/" << m_month << "/" << m_year << endl;
}

Date Date::increase_n_days(int day, int month, int year, int n)
{
	day += n;
	if ((year % 4 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) // Leap year
	{
		while ((month == 2 && day > 29) || ((month != 2 && ((month > 0 && month < 7 && month % 2 == 0) || (month > 7 && month <= 12 && month % 2 != 0))) && day > 30) || ((month != 2 && ((month > 0 && month < 8 && month % 2 != 0) || (month > 7 && month <= 12 && month % 2 == 0))) && day > 31))
		{
			if (month == 2)
			{
				day -= 29;
				month++;
			}
			else if (month != 2 && ((month > 0 && month < 8 && month % 2 != 0) || (month > 7 && month <= 12 && month % 2 == 0)))
			{
				day -= 31;
				month++;
			}
			else if (month != 2 && ((month > 0 && month < 7 && month % 2 == 0) || (month > 7 && month <= 12 && month % 2 != 0)))
			{
				day -= 30;
				month++;
			}
			if (month > 12)
			{
				year = year + (month / 12);
				month = month % 12;
			}
		}
	}
	else if ((year % 4 == 0 && year % 100 == 0 && year % 400 != 0) || year % 4 != 0)   // Normal year
	{
		while ((month == 2 && day > 28) || ((month != 2 && ((month > 0 && month < 7 && month % 2 == 0) || (month > 7 && month <= 12 && month % 2 != 0))) && day > 30) || ((month != 2 && ((month > 0 && month < 8 && month % 2 != 0) || (month > 7 && month <= 12 && month % 2 == 0))) && day > 31))
		{
			if (month == 2)
			{
				day -= 28;
				month++;
			}
			else if (month != 2 && ((month > 0 && month < 8 && month % 2 != 0) || (month > 7 && month <= 12 && month % 2 == 0)))
			{
				day -= 31;
				month++;
			}
			else if (month != 2 && ((month > 0 && month < 7 && month % 2 == 0) || (month > 7 && month <= 12 && month % 2 != 0)))
			{
				day -= 30;
				month++;
			}
			if (month > 12)
			{
				year = year + (month / 12);
				month = month % 12;
			}
		}
	}
	Date k;
	k.m_day = day;
	k.m_month = month;
	k.m_year = year;
	return k;
}

