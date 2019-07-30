#include"Library.h"

//========LIBRARY========//

string chuan_hoa1(string k)
{
	string k1 = k;
	for (unsigned i = 0; i < k.size(); i++)
	{
		k1[i] = tolower(k1[i]);
	}
	return k1;
}
void Library::CapNhat_Library()
{
	fstream fs("Library.txt", ios::in);
	while (fs.eof() != 1)
	{
		Library*L = new Library;
		
		string k;      
		getline(fs, k, ',');        // lưu tên thư viện
		if (k.size() == 0)
			continue;
		L->setName2(k);
		
		int k1;
		fs >> k1;
		L->setMaso2(k1);

		string k2;
		getline(fs, k2);

		m_library.push_back(L);
	}
	fs.close();
}
void Library::inputNameLibrary()
{
	cout << "Nhap ten thu vien: ";
	getline(cin, m_name);
	while (m_name.size() == 0)
	{
		cout << "-Khong co ky tu nao! Nhap lai: ";
		getline(cin, m_name);
	}
}
void Library::inputMasoLibrary()
{
	cout << "Nhap ma so thu vien (0->99): ";
	cin >> m_maso;
	while (m_maso < 0 || m_maso>99)
	{
		cout << "-Nhap lai ma so thu vien: ";
		cin >> m_maso;
	}
}
void Library::addLibrary()
{
	Library*L = new Library;
	L->inputNameLibrary();
	int a = 0;
	while (a == 0)
	{
		a = 1;
		for (unsigned i = 0; i < m_library.size(); i++)
		{
			if ((chuan_hoa1(L->setName()) == chuan_hoa1(m_library[i]->setName())) || (L->setName().size() <= 1)) // check trùng tên 
				a = 0;                                                                                           // hoặc tên không có ký tự
		}
		if (a == 0)
		{
			cout << "Ten da su dung hoac khong hop le! ";
			L->inputNameLibrary();
		}
	}

	L->inputMasoLibrary();
	int b = 0;
	while (b == 0)
	{
		b = 1;
		for (unsigned i = 0; i < m_library.size(); i++)
		{
			if (L->setMaso() == m_library[i]->setMaso())          // check trùng mã số thư viện
				b = 0;
		}
		if (b == 0)
		{
			cout << "Ma so bi trung!";
			L->inputMasoLibrary();
		}
	}

	m_library.push_back(L);
	if (m_library.size() <= 1)
	{
		fstream fs("Library.txt", ios::app);
		fs << L->setName() << "," << L->setMaso();
		fs.close();
	}
	else if (m_library.size() > 1)
	{
		fstream fs("Library.txt", ios::app);
		fs << endl << L->setName() << "," << L->setMaso();
		fs.close();
	}
	string k1, k2, k3, k4;
	k1 = L->setName() + "Book.txt";
	k2 = L->setName() + "BookAmounts.txt";
	k3 = L->setName() + "Borrower.txt";
	k4 = L->setName() + "Librarian.txt";
	fstream f1(k1, ios::out);
	f1.close();
	fstream f2(k2, ios::out);
	f2.close();
	fstream f3(k3, ios::out);
	f3.close();                    // Tạo các file lưu trữ các thành phần của thư viện vừa tạo
	fstream f4(k4, ios::out);
	f4.close();
}
vector<Library*>&Library::setLib()          // = setAddLibrary();
{
	return m_library;
}
void Library::infoLibrary()
{
	for (unsigned i = 0; i < m_library.size(); i++)
	{
		cout << i + 1 << "." << m_library[i]->setName() << endl;
		cout << " - Ma so thu vien: " << m_library[i]->setMaso() << endl << endl;
	}
}
string Library::setName()
{
	return m_name;
}
int Library::setMaso()
{
	return m_maso;
}
int &Library::setMaso2(int k)
{
	m_maso = k;
	return m_maso;
}
string &Library::setName2(string k)              // Để lưu chuỗi được lấy từ file vào
{
	m_name = k;
	return m_name;
}

void Library::deleteLibrary(Library*L)
{
	for (unsigned i = 0; i < m_library.size(); i++)
	{
		if (L->setMaso() == m_library[i]->setMaso())
		{
			remove((L->setName() + "Book.txt").c_str());
			remove((L->setName() + "BookAmounts.txt").c_str());
			remove((L->setName() + "Borrower.txt").c_str());
			remove((L->setName() + "Librarian.txt").c_str());
			for (unsigned j = 0; j < L->setAddBorrower().size(); j++)
			{
				string k;
				k = to_string(L->setAddBorrower()[j]->setCode());
				k += ".txt";
				remove(k.c_str());
			}
			m_library[i] = m_library.back();
			m_library.pop_back();
		}
	}
	fstream fs("Library.txt", ios::out);
	for (unsigned i = 0; i < m_library.size(); i++)
	{
		if (i == 0)
		{
			fs << m_library[i]->setName() << "," << m_library[i]->setMaso();
		}
		else
		{
			fs << endl << m_library[i]->setName() << "," << m_library[i]->setMaso();
		}
	}
	fs.close();
}

//========BOOK========//

void Library::CapNhat_Book()
{
	string B, BA;       // Book và BookAmounts
	B = m_name + "Book.txt";
	BA = m_name + "BookAmounts.txt";
	fstream fs1(B, ios::in);
	fstream fs2(BA, ios::in);
	string k1;
	getline(fs1, k1);
	if (k1.size() == 0)            // check empty file (file rỗng)
	{
		cout << "";
		fs1.close();
		fs2.close();
	}
	else
	{
		fstream fs1(B, ios::in);
		fstream fs2(BA, ios::in);
		while (fs1.eof() != 1)
		{
			Book*B = new Book;
			string k;         //lay ten
			getline(fs1, k, ',');
			if (k.size() == 0)
				continue;
			B->setName2(k);     
			
			string m;          //lay tac gia
			getline(fs1, m, ',');
			B->setAuthor2(m);

			int l;            //lay ma so
			fs1 >> l;
			B->setCode2(l);
			getline(fs1, k, '\n');

			m_book.push_back(B);
		}
		int i = 0;
		while (fs2.eof() != 1)       // lấy số lượng
		{
			int sl;
			fs2 >> sl;
			m_book[i]->setSoLuong2(sl);
			i++;
		}
		fs1.close();
		fs2.close();
	}
}
vector<Book*>Library::addBook()   //  thêm sách mới vào thư viện
{
	string B, BA;       // Book và BookAmounts
	B = m_name + "Book.txt";
	BA = m_name + "BookAmounts.txt";
	Book*p = new Book;
	
	p->inputName();
	int b = 0;
	while (b == 0)
	{
		b = 1;
		for (unsigned i = 0; i < m_book.size(); i++)                     // check tên sách chống trùng lặp
		{
			if (chuan_hoa1(p->setName()) == chuan_hoa1(m_book[i]->setName()))
				b = 0;
		}
		if (b == 0)
		{
			cout << "-Sach da co trong thu vien! ";
			p->inputName();
		}
	}
	
	p->inputInfo();
	p->inputCode();
	int a = 0;
	while (a == 0)
	{
		a = 1;
		for (unsigned i = 0; i < m_book.size(); i++)
		{
			if (p->setCode() == m_book[i]->setCode())                //check mã code chống trùng lặp
				a = 0;
		}
		if (a == 0)
		{
			cout << "-Ma code da duoc su dung! ";
			p->inputCode();
		}
	}
	m_book.push_back(p);
	if (m_book.size() <= 1)
	{
		fstream fs1(B, ios::app);
		fstream fs2(BA, ios::app);
		fs1 << p->setName() << "," << p->setAuthor() << "," << p->setCode();
		fs2 << p->setSoLuong();
		fs1.close();
		fs2.close();
	}
	else if (m_book.size() > 1)
	{
		fstream fs1(B, ios::app);
		fstream fs2(BA, ios::app);
		fs1 << endl << p->setName() << "," << p->setAuthor() << "," << p->setCode();
		fs2 << endl << p->setSoLuong();
		fs1.close();
		fs2.close();
	}
	return m_book;
}
vector<Book*>&Library::setAddBook()
{
	return m_book;
}
void Library::infoAllBook()
{
	if (m_book.size() == 0)
		cout << endl << "   (Khong co sach)" << endl;
	else 
	{
		for (unsigned i = 0; i < m_book.size(); i++)
		{
			cout << i + 1 << ". ";
			m_book[i]->infoBook();
			cout << endl << endl;
		}
	}
}
void Library::searchNameBook(string k)
{
	int a = 0;
	for (unsigned i = 0; i < m_book.size(); i++)
	{
		if ((chuan_hoa1(m_book[i]->setName())).find(chuan_hoa1(k)) <= (m_book[i]->setName().size()))
		{
			cout << i + 1 << ".";
			m_book[i]->infoBook();
			cout << endl << endl;
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}
void Library::searchAuthorBook(string k)
{
	int a = 0;
	for (unsigned i = 0; i < m_book.size(); i++)
	{
		if (chuan_hoa1(m_book[i]->setAuthor()).find(chuan_hoa1(k)) <= m_book[i]->setAuthor().size())
		{
			cout << i + 1 << ".";
			m_book[i]->infoBook();
			cout << endl;
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}
void Library::searchCodeBook(int k)
{
	int a = 0;
	for (unsigned i = 0; i < m_book.size(); i++)
	{
		if (((to_string(m_book[i]->setCode())).find(to_string(k))) <= (to_string(m_book[i]->setCode()).size()))
		{
			cout << i + 1 << ".";
			m_book[i]->infoBook();
			cout << endl;
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}
void Library::GhiSLSach()
{
	string k1 = m_name + "BookAmounts.txt";
	fstream fs(k1, ios::out);
	for (unsigned i = 0; i < m_book.size(); i++)
	{
		if (i == 0)
		{
			fs << m_book[i]->setSoLuong();
		}
		else fs << endl << m_book[i]->setSoLuong();
	}
	fs.close();
}

//========BORROWER========// 

vector<Borrower*>Library::addBorrower()        // xử lý file
{
	Borrower*p = new Borrower;
	p->inputInfo();                                            // nhập thông tin
	p->inputCode();                                            // nhập mã số
	int a = 0;
	string k1, k2, k3;
	int code;
	//p->setCode2(code);
	while (a == 0)
	{
		a = 1;
		k1 = to_string(m_maso);                                //   Đặt lại 
		k2 = to_string(p->setCode());                          // mã số cho 
		k3 = k1 + k2;                                          // đúng với 
		code = stoi(k3);                                       // thư viện đó
		p->setCode2(code);                                     // mã số mới = mã thư viện + mã số cũ
		for (unsigned i = 0; i < m_borrower.size(); i++)
		{
			if (p->setCode() == m_borrower[i]->setCode())      // check mã số chống trùng   
				a = 0;
		}
		if (a == 0)
		{
			cout << "-Ma code da duoc su dung! Nhap lai: ";
			p->inputCode();
		}
	}
	
	string kk;
	kk = this->m_name + "Borrower.txt";                        // Ghi thông tin đọc giả vừa thêm ra file
	if (m_borrower.size() < 1)
	{
		fstream ff(kk, ios::app);
		ff << p->setName() << "," << p->setAddress() << "," << p->setCode() << "," << p->setDay() << "/" << p->setMonth() << "/" << p->setYear();
		ff.close();
	}
	else
	{
		fstream ff(kk, ios::app);
		ff << endl << p->setName() << "," << p->setAddress() << "," << p->setCode() << "," << p->setDay() << "/" << p->setMonth() << "/" << p->setYear();
		ff.close();
	}

	string k4 = to_string(p->setCode()) + ".txt";       // Tạo file lưu danh sách sách đã mượn (trong file lưu "mã số sách,ngày mượn")
	fstream fs(k4, ios::out);
	fs.close();

	m_borrower.push_back(p);
	return m_borrower;
	delete p;
}
void Library::CapNhat_Borrower()
{
	string LB = this->m_name + "Borrower.txt";
	fstream F1(LB, ios::in);
	string check;
	getline(F1, check);
	if (check.size() == 0)
	{
		cout << "";
		F1.close();
	}
	else {
		fstream F1(LB, ios::in);
		while (F1.eof() != 1)           // file "LB.txt" lưu danh sách đọc giả theo dạng (tên,địa chỉ,mã số,day/month/year)
		{
			Borrower*B = new Borrower;
			string k1;                     // lấy tên
			getline(F1, k1, ',');
			if (k1.size() == 0)
				continue;
			B->setName2(k1);

			string k2;                    // lấy địa chỉ
			getline(F1, k2, ',');
			B->setAddress2(k2);

			int k3;                       // lấy mã số
			F1 >> k3;
			B->setCode2(k3);
			F1.seekg(1, 1);

			int day;                       // lấy ngày tạo thẻ
			F1 >> day;
			B->setDay2(day);
			F1.seekg(1, 1);

			int month;                       // lấy tháng tạo thẻ
			F1 >> month;
			B->setMonth2(month);
			F1.seekg(1, 1);

			int year;                       // lấy năm tạo thẻ
			F1 >> year;
			B->setYear2(year);
			getline(F1, k1,'\n');

			m_borrower.push_back(B);
		}
		F1.close();
	}
	for (unsigned i = 0; i < m_borrower.size(); i++)                 // lấy thông tin từng đọc giả (sách mượn, ngày mượn)
	{
		string*maso = new string;
		*maso = to_string(m_borrower[i]->setCode());
		*maso += ".txt";
		fstream fs(*maso, ios::in);
		string check1;
		getline(fs, check1);
		if (check1.size() == 0){
			cout << "";
			fs.close();
		}
		else {
			fstream fs(*maso, ios::in);            // file "maso.txt" lưu thông tin mượn sách của đọc giả dưới dạng (tên sách,day/month/year)
			while (fs.eof() != 1)
			{
				Book*Bo = new Book;
				string h1;                     // lấy tên sách
				getline(fs, h1, ',');
				if (h1.size() == 0)
					continue;
				Bo->setName2(h1);

				int day;                       // lấy ngày mượn
				fs >> day;
				Bo->setDay2(day);
				fs.seekg(1, 1);

				int month;                       // lấy tháng mượn
				fs >> month;
				Bo->setMonth2(month);
				fs.seekg(1, 1);

				int year;                       // lấy năm mượn
				fs >> year;
				Bo->setYear2(year);
				string hh;
				getline(fs, hh, '\n');

				m_borrower[i]->setBorrowBook().push_back(Bo);
			}
			fs.close();
		}
	}
}
vector<Borrower*>&Library::setAddBorrower()
{
	return m_borrower;
}
void Library::infoAllBorrower()
{
	for (unsigned i = 0; i < m_borrower.size(); i++)
	{
		cout << i + 1 << ". ";
		m_borrower[i]->infoBorrower();
		cout << endl << endl;
	}
}
void Library::searchNameBorrower(string k)
{
	int a = 0;
	for (unsigned i = 0; i < m_borrower.size(); i++)
	{
		if ((chuan_hoa1(m_borrower[i]->setName())).find(chuan_hoa1(k)) <= (m_borrower[i]->setName().size()))
		{
			cout << i + 1 << ".";
			m_borrower[i]->infoBorrower();
			cout << endl << endl;
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}
void Library::searchAddressBorrower(string k)
{
	int a = 0;
	for (unsigned i = 0; i < m_borrower.size(); i++)
	{
		if ((chuan_hoa1(m_borrower[i]->setAddress())).find(chuan_hoa1(k)) <= (m_borrower[i]->setAddress().size()))
		{
			cout << i + 1 << ".";
			m_borrower[i]->infoBorrower();
			cout << endl << endl;
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}
void Library::searchCodeBorrower(int k)
{
	int a = 0;
	for (unsigned i = 0; i < m_borrower.size(); i++)
	{
		if (((to_string(m_borrower[i]->setCode())).find(to_string(k))) <= (to_string(m_borrower[i]->setCode()).size()))
		{
			cout << i + 1 << ".";
			m_borrower[i]->infoBorrower();
			cout << endl << endl;
			a = 1;
		}
	}
	if (a == 0)
		cout << "Khong tim thay!";
}
void Library::infoBorrower(Borrower B1)
{
	for (unsigned i = 0; i < m_borrower.size(); i++)
	{
		if ((chuan_hoa1(B1.setName()) == chuan_hoa1(m_borrower[i]->setName())) && (B1.setCode() == m_borrower[i]->setCode()))
		{
			B1.infoBorrower(); // thong tin
			cout << "-Sach dang muon: " << endl;

			if (B1.setBorrowBook().size() != 0)
			{
				for (unsigned j = 0; j < B1.setBorrowBook().size(); j++)
				{
					cout << j + 1 << "." << B1.setBorrowBook()[j]->setName() << endl;
					cout << " -Ngay muon: " << B1.setBorrowBook()[j]->setDay() << "/" << B1.setBorrowBook()[j]->setMonth() << "/" << B1.setBorrowBook()[j]->setYear() << endl;
					cout << " -Ngay tra: ";
					B1.setBorrowBook()[j]->dateGiveBack();
					cout << endl;
				}
			}
			else cout << "(ko co sach!)";
		}
	}
}
void Library::deleteLibraryCard(Borrower*B)       
{
	string k = to_string(B->setCode());
	k += ".txt";
	for (unsigned i = 0; i < m_borrower.size(); i++)
	{
		if (B->setCode() == m_borrower[i]->setCode())
		{
			for (unsigned i = 0; i < B->setBorrowBook().size(); i++)
			{
				B->setBorrowBook()[i]->setSoLuong()++;
				B->setBorrowBook()[i]->setSoLuong2(B->setBorrowBook()[i]->setSoLuong());
			}
			m_borrower[i] = m_borrower.back();
			m_borrower.pop_back();
		}
	}
	if (m_borrower.size() == 0)
		cout << "";
	else
	{
		string k1 = m_name + "Borrower.txt";          // ghi lại thông tin tất cả đọc giả ra file
		fstream FS(k1, ios::out);
		for (unsigned i = 0; i < m_borrower.size(); i++)
		{
			if (i == 0)
				FS << m_borrower[i]->setName() << "," << m_borrower[i]->setAddress() << "," << m_borrower[i]->setCode() << "," << m_borrower[i]->setDay() << "/" << m_borrower[i]->setMonth() << "/" << m_borrower[i]->setYear();
			else
				FS << endl << m_borrower[i]->setName() << "," << m_borrower[i]->setAddress() << "," << m_borrower[i]->setCode() << "," << m_borrower[i]->setDay() << "/" << m_borrower[i]->setMonth() << "/" << m_borrower[i]->setYear();
		}
		FS.close();
	}
	remove(k.c_str());
}         

//========LIBRARIAN========//

void Library::CapNhat_Librarian()
{
	string k = m_name + "Librarian.txt";
	fstream fs(k, ios::in);
	string check;
	getline(fs, check);
	if (check.size() == 0)
	{
		cout << "";
		fs.close();
	}
	else
	{
		fstream fs(k, ios::in);              // lấy thông tin con phò thủ thư (tên, địa chỉ, lương, day/month/year)
		while (fs.eof() != 1)
		{
			string k1;                       // lấy tên
			getline(fs, k1, ',');
			if (k1.size() == 0)
				continue;
			m_librarian.setName2(k1);

			string k2;                       // lấy địa chỉ
			getline(fs, k2, ',');
			m_librarian.setAddress2(k2);

			double k3;                       // lấy tiền lương
			fs >> k3;
			m_librarian.setSalary2(k3);
			fs.seekg(1, 1);

			int day;                         // lấy ngày
			fs >> day;
			m_librarian.setDay2(day);
			fs.seekg(1, 1);

			int month;                       // lấy tháng
			fs >> month;
			m_librarian.setMonth2(month);
			fs.seekg(1, 1);

			int year;                        // lấy năm
			fs >> year;
			m_librarian.setYear2(year);
		}
		fs.close();
	}
}
void Library::addLibrarian()
{
	string k = m_name + "Librarian.txt";
	m_librarian.inputInfo();
	fstream fs(k, ios::out);
	fs << m_librarian.setName() << "," << m_librarian.setAddress() << "," << m_librarian.setSalary() << "," << m_librarian.setDay() << "/" << m_librarian.setMonth() << "/" << m_librarian.setYear();
	fs.close();
}
Librarian Library::setLibrarian()
{
	return m_librarian;
}