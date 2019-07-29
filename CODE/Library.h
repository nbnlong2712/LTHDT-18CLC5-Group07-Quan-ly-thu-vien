#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"Borrower.h"
#include"Book.h"
#include"Librarian.h"
using namespace std;

class Library
{
private:
	vector<Library*>m_library;          // lưu danh sách thư viện
	int m_maso;
	string m_name;                        
	vector<Book*>m_book;                 // lưu danh sách sách trong thư viện
	vector<Borrower*>m_borrower;          // lưu danh sách đọc giả của thư viện
	Librarian m_librarian;                // lưu thủ thư của thư viện
public:
//========LIBRARY========//
	void CapNhat_Library();
	void inputNameLibrary();
	void inputMasoLibrary();                  // của Library là mã số, không phải code
	void addLibrary();
	vector<Library*>&setLib();
	void infoLibrary();
	string setName();
	int setMaso();
	int &setMaso2(int);                       // mã số nhỏ hơn 99
	string &setName2(string);
//========BOOK========//
	void CapNhat_Book();                      // Lấy từ file vào
	void GhiSLSach();                         // Ghi lại số lượng sách mới sau khi có người mượn sách ra file
	vector<Book*>addBook();                   // xử lý file               
	vector<Book*>&setAddBook();
	void infoAllBook();
	void searchNameBook(string k);
	void searchAuthorBook(string k);
	void searchCodeBook(int);
//========BORROWER========//
	void CapNhat_Borrower();                  // Lấy từ file vào
	vector<Borrower*>addBorrower();           // Hàm này cũng dùng để tạo thẻ thư viện cho một đọc giả - create library card 
	vector<Borrower*>&setAddBorrower();
	void infoAllBorrower();
	void searchNameBorrower(string k);
	void searchAddressBorrower(string k);
	void searchCodeBorrower(int);
	void infoBorrower(Borrower);
	void deleteLibraryCard(Borrower*);        // Xử lý file
//========LIBRARIAN========//
	void CapNhat_Librarian();                 // Xử lý file
	void addLibrarian();
	Librarian setLibrarian();
};