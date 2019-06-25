#include"Date.h"

void Date::input()
{
	//cout << "Enter day, month, year:";
	cin >> day;
	cin >> month;
	cin >> year;
	while (year < 0)
	{
		cout << " - Enter year again: ";
		cin >> year;
	}
	while (month < 1 || month>12)
	{
		cout << " - Enter month again: ";
		cin >> month;
	}
	while (day < 1 || day>31)
	{
		cout << " - Enter day again: ";
		cin >> day;
	}
	if ((year % 4 == 0 && year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) // Leap year
	{
		while (month == 2 && (day < 1 || day>29))
		{
			cout << " - Enter day again: ";
			cin >> day;
		}
	}
	else if ((year % 4 == 0 && year % 100 == 0 && year % 400 != 0) || year % 4 != 0)   // Normal year
	{
		while (month == 2 && (day < 1 || day>28))
		{
			cout << " - Enter day again: ";
			cin >> day;
		}
	}
	if (month != 2 && ((month > 0 && month < 7 && month % 2 == 0) || (month > 7 && month <= 12 && month % 2 != 0)))
	{
		while (1 > day || day > 30)
		{
			cout << " - Enter day again: ";
			cin >> day;
		}
	}
	else if (month != 2 && ((month > 0 && month < 8 && month % 2 != 0) || (month > 7 && month <= 12 && month % 2 == 0)))
	{
		while (1 > day || day > 31)
		{
			cout << " - Enter day again: ";
			cin >> day;
		}
	}
}
int Date::setDay()
{
	int h = day;
	return h;
}
int Date::setMonth()
{
	int h = month;
	return h;
}
int Date::setYear()
{
	int h = year;
	return h;
}
void Date::output()
{
	cout << day << "/" << month << "/" << year << endl;
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
	if (year > D1.year)
		return 1;
	else if (year < D1.year)
		return -1;
	else if (year == D1.year)
	{
		if (month > D1.month)
			return 1;
		else if (month < D1.month)
			return -1;
		else if (month == D1.month)
		{
			if (day > D1.day)
				return 1;
			else if (day < D1.day)
				return -1;
			else if (day == D1.day)
				return 0;
		}
	}
}
