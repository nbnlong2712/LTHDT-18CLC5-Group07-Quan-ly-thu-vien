#include<iostream>
#include<string>
#include"Librarian.h"
#include"Book.h"
#include"Library.h"
using namespace std;
#include<iomanip>

int main()
{
	cout << std::setprecision(15);

	Library*L = new Library;
	int luachon;
	cout << "nhap lua chon cua ban: ";
	cin >> luachon;
	while (luachon != 0 && luachon != 1)
	{
		cout << "nhap lai lua chon: ";
		cin >> luachon;
	}
	if (luachon == 1)
	{
		L->addBook();
		while (luachon == 1)
		{
			cout << "Ban co muon add them sach ko? (1:CO / 0:KO): ";
			cin >> luachon;
			system("cls");
			if (luachon == 1)
				L->addBook();
			else break;
		}
	}
	else exit(0);
	L->infoAllBook();
	cout << "Ban co muon tim kiem sach ko? (1:CO / 0:KO)";
	cin >> luachon;
	while (luachon != 0 && luachon != 1)
	{
		cout << "nhap lai lua chon: ";
		cin >> luachon;
	}
	if (luachon == 1)
	{
		while (luachon == 1)  //Tim kiem sach
		{
			cin.ignore();
			int luachon1;
			cout << "Ban muon tim kiem theo loai gi?" << endl;
			cout << "1. Ten sach" << endl;
			cout << "2. Tac gia" << endl;
			cout << "3. Ma sach" << endl;
			cout << "0. Thoat" << endl;
			cout << "=================================" << endl;
			cout << "Moi ban nhap lua chon: ";
			cin >> luachon1;
			while (luachon1 != 1 && luachon1 != 2 && luachon1 != 3 && luachon1 != 0)
			{
				cout << "-nhap lai lua chon: ";
				cin >> luachon1;
			}
			if (luachon1 == 1)
			{
				cin.ignore();
				string*k = new string;
				cout << "nhap ten sach ban muon tim kiem: ";
				getline(cin, *k);
				L->searchNameBook(*k);
				delete k;
			}
			else if (luachon1 == 2)
			{
				cin.ignore();
				string*k = new string;
				cout << "nhap ten tac gia ban muon tim kiem: ";
				getline(cin, *k);
				L->searchAuthorBook(*k);
				delete k;
			}
			else if (luachon1 == 3)
			{
				cin.ignore();
				int*k = new int;
				cout << "nhap ma sach ban muon tim: ";
				cin >> *k;
				L->searchCodeBook(*k);
				delete k;
			}
			else exit(0);
			cout << "Ban co muon tim kiem tiep ko?(1:CO / 0:KO)";
			cin >> luachon;
			system("cls");
			while (luachon != 1 && luachon != 0)
			{
				cout << "-nhap lai lua chon: ";
				cin >> luachon;
			}
		}
	}
	else exit(0);
	return 0;
}