#include"Borrower.h"

string chuan_hoa_borrower(string k)
{
	string k1 = k;
	for (int i = 0; i < k.size(); i++)
	{
		k1[i] = tolower(k1[i]);
	}
	return k1;
}
void Borrower::inputName()
{
	Information::inputName();
}
void Borrower::inputAddress()
{
	Information::inputAddress();
}
void Borrower::inputCode()
{
	Information::inputCode();
}
void Borrower::inputDateCard()
{
	Date::input();
}
void Borrower::inputInfo()
{
	this->inputName();
	this->inputAddress();
	cout << "Nhap ngay tao the thu vien: ";
	this->inputDateCard();
}
Date Borrower::dateExpire()
{
	Date a = this->increase_n_days(m_day, m_month, m_year, 180);
	return a;
}
void Borrower::outputDateExpire()
{
	cout << this->dateExpire().setDay() << "/" << this->dateExpire().setMonth() << "/" << this->dateExpire().setYear();
}
Date Borrower::extensionDateCard()           // = dateExpire() + 180
{
	this->dateExpire() = this->increase_n_days(this->dateExpire().setDay(), this->dateExpire().setMonth(), this->dateExpire().setYear(), 180);
	return this->dateExpire();
}

int Borrower::setDay()
{
	return m_day;
}
int Borrower::setMonth()
{
	return m_month;
}
int Borrower::setYear()
{
	return m_year;
}
int &Borrower::setDay2(int k)
{
	m_day = k;
	return m_day;
}
int &Borrower::setMonth2(int k)
{
	m_month = k;
	return m_month;
}
int &Borrower::setYear2(int k)
{
	m_year = k;
	return m_year;
}
string Borrower::setName()
{
	return m_name;
}
string Borrower::setAddress()
{
	return m_adr;
}
int Borrower::setCode()
{
	return m_code;
}
vector<Book*>&Borrower::setBorrowBook()
{
	return m_book_borrower;
}

void Borrower::borrowBook(Book*B)                            // mượn sách
{
	if (m_book_borrower.size() < 10)                   // số sách mượn không được vượt quá 10 cuốn
	{
		int a = 0;
		for (int i = 0; i < m_book_borrower.size(); i++)
			if (chuan_hoa_borrower(B->setName()) == chuan_hoa_borrower(m_book_borrower[i]->setName()))
				a = 1;
		if (a == 1)
			cout << " Ban da muon sach nay roi!" << endl;
		else
		{
			if (B->setSoLuong() > 0)
			{
				cout << " Muon thanh cong!" << endl;
				B->dateBorrowed();
				m_book_borrower.push_back(B);         // thêm sách vào
				B->setSoLuong()--;
				
				string k1 = to_string(m_code);
				k1 += ".txt";
				if (m_book_borrower.size() <= 1)
				{
					fstream fs(k1, ios::app);
					fs << B->setName() << "," << B->setDay() << "/" << B->setMonth() << "/" << B->setYear();     // ghi thông tin sách vừa mượn ra file
					fs.close();
				}
				else
				{
					fstream fs(k1, ios::app);
					fs << endl << B->setName() << "," << B->setDay() << "/" << B->setMonth() << "/" << B->setYear();
					fs.close();
				}
			}
			else cout << "Het sach!" << endl;
		}
	}
	else
	{
		cout << "Vuot qua so luong cho phep" << endl;
	}
}               
void Borrower::giveBackBook(Book*B)                             //trả sách
{
	if (m_book_borrower.size() == 0)
		cout << endl << " (Khong co sach)" << endl;
	else 
	{
		for (int i = 0; i < m_book_borrower.size(); i++)
		{
			if (chuan_hoa_borrower(B->setName()) == chuan_hoa_borrower(m_book_borrower[i]->setName()))
			{
				int sl = B->setSoLuong();
				sl++;
				B->setSoLuong2(sl);                 // khi trả sách thì số lượng sách đó tăng lên 1
				m_book_borrower[i] = m_book_borrower.back();
				m_book_borrower.pop_back();
				cout << " Tra sach thanh cong!";
			}
		}
	}
	//if (m_book_borrower.size() == 0)                            // nếu số sách mượn đã rỗng thì ko làm con mẹ gì cả
	//{

	//}
	//else
	//{
		string k1 = to_string(m_code);
		k1 += ".txt";
		fstream fs(k1, ios::out);
		for (int i = 0; i < m_book_borrower.size(); i++)        // ghi lại tất cả sách ra file 
		{
			if (i == 0)
			{
				fs << m_book_borrower[i]->setName() << "," << m_book_borrower[i]->setDay() << "/" << m_book_borrower[i]->setMonth() << "/" << m_book_borrower[i]->setYear();
			}
			else fs << endl << m_book_borrower[i]->setName() << "," << m_book_borrower[i]->setDay() << "/" << m_book_borrower[i]->setMonth() << "/" << m_book_borrower[i]->setYear();
		}
		fs.close();
	//}
}                  

string &Borrower::setName2(string k)
{
	m_name = k;
	return m_name;
}
string &Borrower::setAddress2(string k)
{
	m_adr = k;
	return m_adr;
}
int &Borrower::setCode2(int k)
{
	m_code = k;
	return m_code;
}

void Borrower::infoBorrower()
{
	cout << "Ten: " << m_name << endl;
	cout << "Dia chi: " << m_adr << endl;
	cout << "Ma so the: " << m_code << endl;
	cout << "Ngay tao the thu vien: " << m_day << "/" << m_month << "/" << m_year << endl;
	cout << "Ngay het han the thu vien: ";
	this->outputDateExpire();
	cout << endl;
}