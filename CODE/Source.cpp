#include<iostream>
#include<string>
#include"Librarian.h"
#include"Book.h"
#include"Library.h"
#include"Borrower.h"
using namespace std;
#include<iomanip>

string chuan_hoa_main(string k)
{
	string k1 = k;
	for (unsigned i = 0; i < k.size(); i++)
	{
		k1[i] = toupper(k1[i]);
	}
	return k1;
}

int main()
{
	cout << std::setprecision(15);

	//Library*L = new Library;
	/*int luachon;
	cout << "nhap lua chon cua ban: ";
	cin >> luachon;
	while (luachon != 0 && luachon != 1)
	{
		cout << "nhap lai lua chon: ";
		cin >> luachon;
	}
	if (luachon == 1)
	{
		L->addBorrower();
		while (luachon == 1)
		{
			cout << "Ban co muon add them doc gia ko? (1:CO / 0:KO): ";
			cin >> luachon;
			system("cls");
			if (luachon == 1)
				L->addBorrower();
			else break;
		}
	}
	else exit(0);
	L->infoAllBorrower();
	cout << "Ban co muon tim kiem doc gia ko? (1:CO / 0:KO)";
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
			cout << "Ban muon tim kiem theo gi?" << endl;
			cout << "1. Ten doc gia" << endl;
			cout << "2. Dia chi doc gia" << endl;
			cout << "3. Ma so the doc gia" << endl;
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
				cout << "nhap ten doc gia ban muon tim kiem: ";
				getline(cin, *k);
				L->searchNameBorrower(*k);
				delete k;
			}
			else if (luachon1 == 2)
			{
				cin.ignore();
				string*k = new string;
				cout << "nhap dia chi doc gia ban muon tim kiem: ";
				getline(cin, *k);
				L->searchAddressBorrower(*k);
				delete k;
			}
			else if (luachon1 == 3)
			{
				cin.ignore();
				int*k = new int;
				cout << "nhap ma so doc gia ban muon tim: ";
				cin >> *k;
				L->searchCodeBorrower(*k);
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
	else exit(0);*/
	/*L->addBook();
	L->addBook();
	L->addBook();
	L->addBook();
	L->addBook();
	L->addBook();
	L->infoAllBook();
	L->addBorrower();
	cin.ignore();
	string*k = new string;
	cout << "nhap ten doc gia muon muon sach: ";
	getline(cin, *k);
	while (L->searchNameBorrower1(*k) != true)           // ten doc gia
	{	
		cout << "nhap lai ten doc gia: ";
		getline(cin, *k);
		string*k = new string;
		if (L->searchNameBook1(*k) == true)
			break;
	}
	string*l = new string;
	cout << "nhap sach muon muon: ";
	getline(cin, *l);
	while (L->searchNameBook1(*l) != true)            // ten sach
	{
		cout << "nhap lai ten sach: ";
		getline(cin, *l);
		string*l = new string;
	}
	for (int i = 0; i < L->setAddBorrower().size(); i++)       // cho muon sach
	{
		if (chuan_hoa_main(*k) == chuan_hoa_main(L->setAddBorrower()[i]->setName()))
		{
			for (int j = 0; j < L->setAddBook().size(); j++)
			{
				if (chuan_hoa_main(*l) == chuan_hoa_main(L->setAddBook()[j]->setName()))
					L->setAddBorrower()[i]->borrowBook(L->setAddBook()[j]);
			}
		}
	}

	int luachon = 1;
	while (luachon == 1)
	{
		while (L->searchNameBook1(*l) != true)            // ten sach
		{
			cout << "nhap lai ten sach: ";
			getline(cin, *l);
			string*l = new string;
		}
		for (int i = 0; i < L->setAddBorrower().size(); i++)       // cho muon sach
		{
			if (chuan_hoa_main(*k) == chuan_hoa_main(L->setAddBorrower()[i]->setName()))
			{
				for (int j = 0; j < L->setAddBook().size(); j++)
				{
					if (chuan_hoa_main(*l) == chuan_hoa_main(L->setAddBook()[j]->setName()))
						L->setAddBorrower()[i]->borrowBook(L->setAddBook()[j]);
				}
			}
		}
		cout << "nhap tiep lua chon: ";
		cin >> luachon;
		if (luachon == 1)
		{
			cin.ignore();
			system("cls");
			string*l = new string;
			cout << "nhap sach muon muon: ";
			getline(cin, *l);
		}
	}
	cout << endl << "khi muon: " << endl;
	for (int i = 0; i < L->setAddBorrower().size(); i++)            // in thong tin
	{
		if (chuan_hoa_main(*k) == chuan_hoa_main(L->setAddBorrower()[i]->setName()))
			L->infoBorrower(*L->setAddBorrower()[i]);
	}
	for (int i = 0; i < L->setAddBorrower().size(); i++)             // tra lai sach
	{
		if (chuan_hoa_main(*k) == chuan_hoa_main(L->setAddBorrower()[i]->setName()))
		{
			for (int j = 0; j < L->setAddBook().size(); j++)
			{
				if (chuan_hoa_main(*l) == chuan_hoa_main(L->setAddBook()[j]->setName()))
					L->setAddBorrower()[i]->giveBackBook(L->setAddBook()[j]);
			}
		}
	}
	cout << endl << "khi tra: " << endl;
	for (int i = 0; i < L->setAddBorrower().size(); i++)    // in thong tin
	{
		if (chuan_hoa_main(*k) == chuan_hoa_main(L->setAddBorrower()[i]->setName()))
			L->infoBorrower(*L->setAddBorrower()[i]);
	}

	delete l;
	delete k;
	delete L;*/

	Library*L = new Library;
	for (int i = 0; i < 6; i++)
		L->addBook();
	cout << endl << "nguoi dung: ";
	Borrower*K = L->addBorrower()[0];

	for (int i = 0; i < 6; i++)
	{
		if (K->borrowBook(L->setAddBook()[i]) == true)
			cout << "muon thanh cong :)";
		else cout << "ko muon dc nua!";
	}
	L->infoBorrower(*K);
	int luachon = 1;
	while (luachon == 1)
	{
		cin.ignore();
		string*k = new string;
		cout << "nhap sach muon tra: ";
		getline(cin, *k);

		for (unsigned i = 0; i < L->setAddBook().size(); i++)
		{
			if (chuan_hoa_main(*k) == chuan_hoa_main(L->setAddBook()[i]->setName()))
				K->giveBackBook(L->setAddBook()[i]);
		}
		cout << "tra tiep ko (1:co / 0:ko): ";
		cin >> luachon;
	}
	L->infoBorrower(*K);
	delete L;
	return 0;
}