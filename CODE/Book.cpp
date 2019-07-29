#include"Book.h"

string chuan_hoa(string k)         // chuyển tất cả ký tự chuỗi k thành chữ thường
{
	string k1 = k;
	for (int i = 0; i < k.size(); i++)
	{
		k1[i] = tolower(k1[i]);
	}
	return k1;
}

void Book::inputName()
{
	cout << "Nhap ten sach: ";
	getline(cin, m_name);
	while (m_name.size() == 0)               // nếu nhập vào m_name rỗng, thì bắt nhập lại
	{
		cout << "-Khong co ky tu nao! Nhap lai: ";
		getline(cin, m_name);
	}
}
void Book::inputInfo()
{
	cout << "Nhap tac gia: ";
	getline(cin, m_author);
	while (m_author.size() == 0)              // nếu m_author rỗng thì bắt nhập lại
	{
		cout << "-Khong co ky tu nao! Nhap lai: ";
		getline(cin, m_author);
	}
	
	cout << "Nhap so luong sach: ";            // số lượng nếu vượt quá 9999 thì bắt nhập lại (quá nhiều)
	cin >> m_soluong;
	while (m_soluong < 0 || m_soluong>9999)
	{
		cout << "-Nhap lai so luong sach: ";
		cin >> m_soluong;
	}
}
void Book::inputCode()
{
	cout << "Nhap ma sach: ";
	cin >> m_code;
	while (m_code < 1000 || m_code>99999)
	{
		cout << "Khong hop le! Nhap lai ma so: ";
		cin >> m_code;
	}
}

void Book::dateBorrowed()       // hàm nhập ngày, tháng, năm mượn sách
{
	cout << "Nhap ngay, thang, nam muon sach: ";
	Date::input();
} 
void Book::dateGiveBack()       // hàm xuất ngày, tháng, năm trả sách
{
	Date a = this->increase_n_days(m_day, m_month, m_year, 60);
	cout << a.setDay() << "/" << a.setMonth() << "/" << a.setYear();
}

string Book::setName()
{
	return m_name;
}
string Book::setAuthor()
{
	return m_author;
}
int Book::setCode()
{
	return m_code;
}
int &Book::setSoLuong()
{
	return m_soluong;
}
string &Book::setName2(string k)
{
	m_name = k;
	return m_name;
}
string &Book::setAuthor2(string k)
{
	m_author = k;
	return m_author;
}
int &Book::setCode2(int k)
{
	m_code = k;
	return m_code;
}
int &Book::setSoLuong2(int k)
{
	m_soluong = k;
	return m_soluong;
}

int Book::setDay()
{
	return m_day;
}
int Book::setMonth()
{
	return m_month;
}
int Book::setYear()
{
	return m_year;
}
int &Book::setDay2(int k)
{
	m_day = k;
	return m_day;
}
int &Book::setMonth2(int k)
{
	m_month = k;
	return m_month;
}
int &Book::setYear2(int k)
{
	m_year = k;
	return m_year;
}

void Book::infoBook()
{
	cout << "-Ten sach: " << m_name << endl;
	cout << "-Tac gia: " << m_author << endl;
	cout << "-So luong: " << m_soluong << endl;
	cout << "-Ma sach: " << m_code;
}