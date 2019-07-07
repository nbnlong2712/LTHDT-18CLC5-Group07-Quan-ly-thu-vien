#include"Date.h"


void Date::input()
{
	cout << "Enter day, month, year:";
	cin >> m_day;
	cin >> m_month;
	cin >> m_year;
	while (m_year < 0)
	{
		cout << " - Enter year again: ";
		cin >> m_year;
	}
	while (m_month < 1 || m_month>12)
	{
		cout << " - Enter month again: ";
		cin >> m_month;
	}
	while (m_day < 1 || m_day>31)
	{
		cout << " - Enter day again: ";
		cin >> m_day;
	}
	if ((m_year % 4 == 0 && m_year % 400 == 0) || (m_year % 4 == 0 && m_year % 100 != 0)) // Leap year
	{
		while (m_month == 2 && (m_day < 1 || m_day>29))
		{
			cout << " - Enter day again: ";
			cin >> m_day;
		}
	}
	else if ((m_year % 4 == 0 && m_year % 100 == 0 && m_year % 400 != 0) || m_year % 4 != 0)   // Normal year
	{
		while (m_month == 2 && (m_day < 1 || m_day>28))
		{
			cout << " - Enter day again: ";
			cin >> m_day;
		}
	}
	if (m_month != 2 && ((m_month > 0 && m_month < 7 && m_month % 2 == 0) || (m_month > 7 && m_month <= 12 && m_month % 2 != 0)))
	{
		while (1 > m_day || m_day > 30)
		{
			cout << " - Enter day again: ";
			cin >> m_day;
		}
	}
	else if (m_month != 2 && ((m_month > 0 && m_month < 8 && m_month % 2 != 0) || (m_month > 7 && m_month <= 12 && m_month % 2 == 0)))
	{
		while (1 > m_day || m_day > 31)
		{
			cout << " - Enter day again: ";
			cin >> m_day;
		}
	}
}

int Date::setDay()
{
	int h = m_day;
	return h;
}
int Date::setMonth()
{
	int h = m_month;
	return h;
}
int Date::setYear()
{
	int h = m_year;
	return h;
}
void Date::output()
{
	cout << m_day << "/" << m_month << "/" << m_year << endl;
}

void Date::increase_n_days(int day, int month, int year, int n)
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
	cout << endl << "Your time when increase " << n << " day: " << day << "/" << month << "/" << year << endl;
}
void Date::decrease_n_days(int day, int month, int year, int n1)
{
	int n = n1;
	if (n < day)
		day -= n;
	else if (n == day)
	{
		if ((year % 4 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) // Leap year
		{
			if (month == 3)
			{
				day = 29;
				month--;

			}
			else if (month == 1)
			{
				day = 31;
				month = 12;
				year--;
			}
			else if ((month >= 2 && month <= 8 && month % 2 == 0) || (month >= 9 && month <= 11 && month % 2 != 0))
			{
				day = 31;
				month--;
			}
			else if ((month >= 5 && month <= 7 && month % 2 != 0) || (month >= 10 && month <= 12 && month % 2 == 0))
			{
				day = 30;
				month--;
			}
		}
		else if ((year % 4 == 0 && year % 100 == 0 && year % 400 != 0) || year % 4 != 0)   // Normal year
		{
			if (month == 3)
			{
				day = 28;
				month--;
			}
			else if (month == 1)
			{
				day = 31;
				month = 12;
				year--;
			}
			else if ((month >= 2 && month <= 8 && month % 2 == 0) || (month >= 9 && month <= 11 && month % 2 != 0))
			{
				day = 31;
				month--;
			}
			else if ((month >= 5 && month <= 7 && month % 2 != 0) || (month >= 10 && month <= 12 && month % 2 == 0))
			{
				day = 30;
				month--;
			}
		}
	}
	else if (n > day)
	{
		n -= day;
		month--;
		if (month < 1)
		{
			month = 12;
			year--;
		}
		day = n;
		//month--;
		if ((year % 4 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) // Leap year
		{
			while (n != 0)
			{
				if (month == 2 && day > 29)
				{
					day -= 29;
					month--;
				}
				if (month == 2 && day <= 29)
				{
					if (day - 29 == 0)
					{
						day = 31;
						month--;
					}
					else if (day<29) day = 29 - day;
					n = 0;
					break;
				}
				if (month != 2 && ((month > 0 && month < 8 && month % 2 != 0) || (month > 7 && month <= 12 && month % 2 == 0)) && day > 31)
				{
					day -= 31;
					if (month == 1)                 //Cho nay can sua
					{
						month = 12;
						year--;
					}
					else month--;
				}
				if (month != 2 && ((month > 0 && month < 8 && month % 2 != 0) || (month > 7 && month <= 12 && month % 2 == 0)) && day <= 31)
				{
					if (day - 31 == 0)
					{
						if (month == 3)
						{
							day = 29;
							month--;
						}
						else if (month != 3 && month != 1)
						{
							day = 30;
							month--;
						}
						else if (month == 1)
						{
							day = 31;
							month = 12;
							year--;
						}
					}
					else if (day<31) day = 31 - day;
					n = 0;
					break;
				}
				if (month != 2 && ((month > 0 && month < 7 && month % 2 == 0) || (month > 7 && month <= 12 && month % 2 != 0)) && day > 30)
				{
					day -= 30;
					month--;
				}
				if (month != 2 && ((month > 0 && month < 7 && month % 2 == 0) || (month > 7 && month <= 12 && month % 2 != 0)) && day <= 30)
				{
					if (day - 30 == 0)
					{
						day = 31;
						month--;
					}
					else if (day<30) day = 30 - day;
					n = 0;
					break;
				}
			}
		}
		else if ((year % 4 == 0 && year % 100 == 0 && year % 400 != 0) || year % 4 != 0)   // Normal year
		{
			while (n != 0)
			{
				if (month == 2 && day > 28)
				{
					day -= 28;
					month--;
				}
				if (month == 2 && day <= 28)
				{
					if (day - 28 == 0)
					{
						day = 31;
						month--;
					}
					else day = 28 - day;
					n = 0;
					break;
				}
				if (month != 2 && ((month > 0 && month < 8 && month % 2 != 0) || (month > 7 && month <= 12 && month % 2 == 0)) && day > 31)
				{
					day -= 31;
					if (month == 1)
					{
						month = 12;       //cho nay can sua
						year--;
					}
					else month--;
				}
				if (month != 2 && ((month > 0 && month < 8 && month % 2 != 0) || (month > 7 && month <= 12 && month % 2 == 0)) && day <= 31)
				{
					if (day - 31 == 0)
					{
						if (month == 3)
						{
							day = 28;
							month--;
						}
						else if (month != 3 && month != 1)
						{
							day = 30;
							month--;
						}
						else if (month == 1)
						{
							day = 31;
							month = 12;
							year--;
						}
					}
					else day = 31 - day;
					n = 0;
					break;
				}
				if (month != 2 && ((month > 0 && month < 7 && month % 2 == 0) || (month > 7 && month <= 12 && month % 2 != 0)) && day > 30)
				{
					day -= 30;
					month--;
				}
				if (month != 2 && ((month > 0 && month < 7 && month % 2 == 0) || (month > 7 && month <= 12 && month % 2 != 0)) && day <= 30)
				{
					if (day - 30 == 0)
					{
						day = 31;
						month--;
					}
					else day = 30 - day;
					n = 0;
					break;
				}
			}
		}
	}
	cout << endl << "Your time when decrease " << n1 << " day: " << day << "/" << month << "/" << year << endl;
}

int Date::compare(Date D1)
{
	if (m_year > D1.m_year)
		return 1;
	else if (m_year < D1.m_year)
		return -1;
	else if (m_year == D1.m_year)
	{
		if (m_month > D1.m_month)
			return 1;
		else if (m_month < D1.m_month)
			return -1;
		else if (m_month == D1.m_month)
		{
			if (m_day > D1.m_day)
				return 1;
			else if (m_day < D1.m_day)
				return -1;
			else if (m_day == D1.m_day)
				return 0;
		}
	}
}
