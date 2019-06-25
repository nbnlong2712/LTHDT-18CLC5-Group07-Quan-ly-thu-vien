#include<iostream>
using namespace std;
#include<string>
#include"Information.h"
#include<fstream>
#include"Book.h"
#include<stdlib.h>
#include"Staff.h"

int main()
{
	Book*k = new Book;
	k->inputName();
	k->inputAuthor();
	k->inputOrigin();
	k->inputAmounts();
	k->inputCode();
	k->inputCategory();
	k->inputLanguage();
	k->infoAllBook();
	string k1;
	int xoa;
	cout << "Ban co muon tim kiem ko(1: CO/ 0: KHONG): ";
	cin >> xoa;
	while (xoa != 1 && xoa != 0)
	{
		cout << "De nghi nhap lai: ";
		cin >> xoa;
	}
	
	int xoa2 = 1;
	if (xoa == 1)
	{
		while (xoa2 == 1)
		{
			if (xoa == 1)
			{
				system("cls");
				cout << "nhap sach ban muon tim kiem: ";
				cin.ignore();
				getline(cin, k1);
				cout << "Ket qua tim kiem: " << endl << "-> ";
				cout << k->searchNameBook(k1) << endl;
				if (k->searchNameBook(k1) != "Khong tim thay!")
				{
					cout << "Ban co muon xem thong tin sach khong(1:CO \ 0:KHONG): ";
					int xoa3;
					cin >> xoa3;
					while (xoa3 != 1 && xoa3 != 0)
					{
						cout << "De nghi nhap lai: ";
						cin >> xoa3;
					}
					if (xoa3 == 1)
						k->infoBook(k->searchNameBook(k1));
					else continue;
				}
			}
			cout <<endl<< "Ban co muon tim kiem tiep khong (1:CO \ 0:KHONG): ";
			cin >> xoa2;
			while (xoa2 != 1 && xoa2 != 0)
			{
				cout << "Nhap lai: ";
				cin >> xoa2;
			}
			if (xoa2 == 1)
				continue;
			else exit(0);
		}
	}
	else exit(0);
	/*Staff*f = new Staff;
	f->inputName();
	f->infoAllStaff();*/
	return 0;
}