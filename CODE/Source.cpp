#include<iostream>
#include<string>
#include"Librarian.h"
#include"Book.h"
#include"Library.h"
#include"Borrower.h"
#include<conio.h>
using namespace std;
#include<iomanip>
#include <conio.h>

string chuan_hoa_main(string k)
{
	string k1 = k;
	for (unsigned i = 0; i < k.size(); i++)
	{
		k1[i] = tolower(k1[i]);
	}
	return k1;
}
string viet_hoa(string k)
{
	string k1 = k;
	for (unsigned i = 0; i < k.size(); i++)
	{
		k1[i] = toupper(k1[i]);
	}
	return k1; 
}

//	KHI MƯỢN SÁCH HOẶC XÓA ĐỌC GIẢ THÌ CẦN GỌI HÀM CẬP NHẬT SỐ LƯỢNG RA FILE

int main()
{
	cout << std::setprecision(15);
	Library*L = new Library;
	L->CapNhat_Library();                                 // cập nhật lại những gì người dùng đã làm trong lần sử dụng trước
	for (unsigned i = 0; i < L->setLib().size(); i++)
	{
		L->setLib()[i]->CapNhat_Book();
		L->setLib()[i]->CapNhat_Borrower();
		L->setLib()[i]->CapNhat_Librarian();
	}

	Library*lib = new Library;                                     // đối tượng tạo để chốc lát nữa chỉ định thư viện

	int page = 0;
	int luachon = 1;
	int luachon_tv = 0;                                       // xử lý lựa chọn trong trang 0 - trang thư viện
	int luachon_sach = 0;                                     // xử lý lựa chọn trong trang sách
	int luachon_docgia = 0;                                   // xử lý lựa chọn trong trang đọc giả
	int luachon_thuthu = 0;                                   // xử lý lựa chọn trong trang thủ thư
														  // (có thể chưa đúng và bị sửa đổi sau này)
	while (luachon == 1)
	{
		// PAGE 0                        // trang này đưa ra menu lựa chọn thao tác với thư viện
		if (page == 0)
		{
			string luachon0;
			system("cls");
			cout << endl << "             QUAN LY THU VIEN" << endl << endl << endl;
			cout << "1. TAO THU VIEN" << endl;
			cout << "2. XEM THU VIEN" << endl;
			cout << "3. Thoat" << endl;
			cout << "=====================" << endl;
			cout << "-> Moi chon chuc nang: ";          // chọn chức năng 1, 2, 3
			getline(cin, luachon0);
			if (luachon0 != "1" && luachon0 != "2" && luachon0 != "3")
				continue;
			if (luachon0 == "1")
				page = 1;                         // trang 1 là trang nhập thư viện
			else if (luachon0 == "2")
				page = 2;
			else if (luachon0 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// TRANG 1                       // trang này tạo mới thư viện
		if (page == 1)                                
		{
			system("cls");
			cout << endl << "          TAO THU VIEN " << endl << endl;
			string luachon1;
			cout << "-> Moi ban tao thu vien: " << endl << endl;
			L->addLibrary();                           // create a new library in the big library 
			cout << "=====================" << endl;
			cout << "1. Trang truoc" << endl;
			cout << "2. Thoat" << endl;
			cout << "=====================" << endl;
			cout << "-> Moi nhap lua chon: ";
			cin.ignore();
			getline(cin, luachon1);
			while (luachon1 != "1" && luachon1 != "2")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon1);
			}
			if (luachon1 == "1")
				page = 0;
			else if (luachon1 == "2")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 2                        // trang này để chọn thư viện cần xem thông tin và sử dụng các nghiệp vụ  
		if (page == 2)                                                                          
		{
			system("cls");
			cout << endl << "          XEM THU VIEN " << endl << endl;
			string luachon2;
			cout << " Danh sach thu vien: " << endl << endl;
			L->infoLibrary();
			cout << "================================" << endl;
			cout << "1. Xem thong tin thu vien cu the" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "================================" << endl;
			cout << "-> Moi nhap lua chon: ";
			getline(cin, luachon2);
			while (luachon2 != "1" && luachon2 != "2" && luachon2 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon2);
			}
			if (luachon2 == "1")
			{
				string k2;
				cout << "Nhap ten thu vien ban muon xem: ";
				getline(cin, k2);
				int linh = 1;
				while (linh == 1)
				{
					for (unsigned i = 0; i < L->setLib().size(); i++)
					{
						if (chuan_hoa_main(k2) == chuan_hoa_main(L->setLib()[i]->setName()))
						{
							lib = new Library;
							lib = L->setLib()[i];
							linh = 0;
							page = 3;
						}
					}
					if (linh == 1)
					{
						cout << "-Thu vien ban nhap khong co! Nhap lai: ";
						getline(cin, k2);
					}
				}
			}
			else if (luachon2 == "2")
				page = 0;
			else if (luachon2 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 3                        // page này để lựa chọn các chức năng xử lý nghiệp vụ
		if (page == 3)                        
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << "1. Them va xoa" << endl;
			cout << "2. Muon va tra sach" << endl;
			cout << "3. Xem thong tin" << endl;
			cout << "4. Tim kiem" << endl;
			cout << "5. Trang truoc" << endl;
			cout << "6. Thoat" << endl;
			cout << "====================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon3;
			getline(cin, luachon3);
			if (luachon3 != "1" && luachon3 != "2" && luachon3 != "3" && luachon3 != "4" && luachon3 != "5" && luachon3 != "6")
				continue;
			if (luachon3 == "1")
				page = 4;
			else if (luachon3 == "2")
				page = 13;
			else if (luachon3 == "3")
				page = 16;
			else if (luachon3 == "4")
				page = 20;
			else if (luachon3 == "5")
				page = 2;
			else if (luachon3 == "6")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 4                        // page này để xử lý nghiệp vụ trong THÊM VÀ XÓA
		if (page == 4)         
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> THEM VA XOA" << endl << endl;
			cout << "1. Them" << endl;
			cout << "2. Xoa" << endl;
			cout << "3. Trang truoc" << endl;
			cout << "4. HOME" << endl;
			cout << "5. Thoat" << endl;
			cout << "=================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon4;
			getline(cin, luachon4);
			if (luachon4 != "1" && luachon4 != "2" && luachon4 != "3" && luachon4 != "4" && luachon4 != "5")
				continue;
			if (luachon4 == "1")
				page = 5;
			else if (luachon4 == "2")
				page = 11;
			else if (luachon4 == "3")
				page = 3;
			else if (luachon4 == "4")
				page = 0;
			else if (luachon4 == "5")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 5                        // trang này để danh sách xử lý nghiệp vụ trong phần THÊM
		if (page == 5)                           
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> THEM" << endl << endl;
			cout << "1. Sach" << endl;
			cout << "2. Doc gia" << endl;
			cout << "3. Nhan vien thu thu" << endl;
			cout << "4. Trang truoc" << endl;
			cout << "5. Thoat" << endl;
			cout << "======================" << endl;
			string luachon5;
			cout << "-> Moi nhap lua chon: ";
			getline(cin, luachon5);
			if (luachon5 != "1" && luachon5 != "2" && luachon5 != "3" && luachon5 != "4" && luachon5 != "5")
				continue;
			if (luachon5 == "1")
				page = 6;
			else if (luachon5 == "2")
				page = 9;
			else if (luachon5 == "3")
				page = 10;
			else if (luachon5 == "4")
				page = 4;
			else if (luachon5 == "5")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}
		 
		// PAGE 6                        // xử lý nghiệp vụ trong THÊM >> SÁCH
		if (page == 6)                   
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> THEM : SACH" << endl << endl;
			cout << "1. Them sach moi" << endl;
			cout << "2. Them so luong sach" << endl;
			cout << "3. Trang truoc" << endl;
			cout << "4. Thoat" << endl;
			cout << "======================" << endl;
			string luachon6;
			cout << "-> Moi nhap lua chon: ";
			getline(cin, luachon6);
			if (luachon6 != "1" && luachon6 != "2" && luachon6 != "3" && luachon6 != "4")
				continue;
			if (luachon6 == "1")
				page = 7;
			else if (luachon6 == "2")
				page = 8;
			else if (luachon6 == "3")
				page = 5;
			else if (luachon6 == "4")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 7                        // trang này để thực hiện nghiệp vụ thêm sách mới vào thư viện
		if (page == 7)                 
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> THEM : THEM SACH MOI" << endl << endl;
			cout << "-> Moi ban them sach moi: " << endl;
			lib->addBook();
			cout << "=========================" << endl << endl;
			cout << "1. Tiep tuc them sach moi" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=========================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon7;
			cin.ignore();
			getline(cin, luachon7);
			while (luachon7 != "1" && luachon7 != "2" && luachon7 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				cin >> luachon7;
			}
			if (luachon7 == "1")
				page = 7;
			else if (luachon7 == "2")
				page = 6;
			else if (luachon7 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 8                        // trang này để mua thêm số lượng sách
		if (page == 8)                                  
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> THEM : THEM SO LUONG SACH" << endl << endl;
			string k8;
			cout << "-> Moi nhap ten sach can nhap them so luong: ";
			getline(cin, k8);
			int linh8 = 0;
			while (linh8 == 0)
			{
				for (unsigned i = 0; i < lib->setAddBook().size(); i++)
				{
					if (chuan_hoa_main(k8) == chuan_hoa_main(lib->setAddBook()[i]->setName()))
					{
						linh8 = 1;
						cout << endl;
						lib->setAddBook()[i]->infoBook();
						cout << endl << "====================" << endl;
						cout << "-> Moi nhap so luong: ";
						int soluong8;
						cin >> soluong8;
						while (soluong8 < 1 || soluong8>999)
						{
							cout << "   - So luong khong hop le! Nhap lai: ";
							cin >> soluong8;
						}
						soluong8 += lib->setAddBook()[i]->setSoLuong();
						lib->setAddBook()[i]->setSoLuong2(soluong8);
						lib->GhiSLSach();
					}
				}
				if (linh8 == 0)
				{
					cout << "   - Ten sach khong co! Nhap lai: ";
					getline(cin, k8);
				}
			}
			cout << "=========================" << endl << endl;
			cout << "1. Tiep tuc them so luong sach" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=========================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon8;
			cin.ignore();
			getline(cin, luachon8);
			while (luachon8 != "1" && luachon8 != "2" && luachon8 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon8);
			}
			if (luachon8 == "1")
				page = 8;
			else if (luachon8 == "2")
				page = 6;
			else if (luachon8 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 9                        // xử lý nghiệp vụ phần THÊM >> ĐỌC GIẢ
		if (page == 9)                     
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> THEM : DOC GIA" << endl << endl;
			cout << "-> Moi them doc gia: " << endl;
			lib->addBorrower();
			cout << "=========================" << endl << endl;
			cout << "1. Tiep tuc them doc gia" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=========================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon9;
			cin.ignore();
			getline(cin, luachon9);
			while (luachon9 != "1" && luachon9 != "2" && luachon9 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon9);
			}
			if (luachon9 == "1")
				page = 9;
			else if (luachon9 == "2")
				page = 5;
			else if (luachon9 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 10                       //  trang này dùng để xử lý việc thêm hoặc thay mới nhân viên thủ thư
		if (page == 10)                  
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> THEM : NHAN VIEN THU THU" << endl << endl;
			int linh10_2 = 0;
			if (lib->setLibrarian().setName().size() != 0)
			{
				lib->setLibrarian().infoLibrarian();
				cout << endl << "====================" << endl;
				cout << " Ban co muon thay nhan vien thu thu moi khong? (1: CO | 0: KHONG): ";
				string luachon10_1;
				getline(cin, luachon10_1);
				if (luachon10_1 != "1" && luachon10_1 != "0")
					continue;
				if (luachon10_1 == "1")
				{
					cout << endl << "====================" << endl;
					cin.ignore();
					lib->addLibrarian();
				}
				else if (luachon10_1 == "0")
				{
					cout << "";
					linh10_2 = 1;
				}
			}
			else if (lib->setLibrarian().setName().size() == 0)
			{
				cout << "-> Moi nhap nhan vien thu thu: " << endl;
				lib->addLibrarian();
			}
			cout << "====================" << endl;
			cout << "1. Trang truoc" << endl;
			cout << "2. Thoat" << endl;
			cout << "====================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon10;
			if (linh10_2 == 0)
				cin.ignore();
			getline(cin, luachon10);
			while (luachon10 != "1" && luachon10 != "2")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon10);
			}
			if (luachon10 == "1")
				page = 5;
			else if (luachon10 == "2")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 11                       // trang này để có thao tác nghiệp vụ xóa 
		if (page == 11)                
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> XOA" << endl << endl;
			cout << "1. Doc gia" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "===============" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon11;
			getline(cin, luachon11);
			if (luachon11 != "1" && luachon11 != "2" && luachon11 != "3")
				continue;
			if (luachon11 == "1")
				page = 12;
			else if (luachon11 == "2")
				page = 4;
			else if (luachon11 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 12                       // trang này để xóa, hủy thẻ đọc giả
		if (page == 12)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> XOA : DOC GIA" << endl << endl;
			cout << "-> Moi nhap ma so the doc gia muon xoa: ";
			int masothe12;
			cin >> masothe12;
			int linh12 = 0;
			while (linh12 == 0)
			{
				for (unsigned i = 0; i < lib->setAddBorrower().size(); i++)
				{
					if (masothe12 == lib->setAddBorrower()[i]->setCode())
					{
						lib->deleteLibraryCard(lib->setAddBorrower()[i]); 
						lib->GhiSLSach();          // sau khi xóa thì đọc giả đó phải trả lại số sách đã mượn, cần ghi lại số sách mới ra file
						linh12 = 1;
						break;
					}
				}
				if (linh12 == 0)
				{
					cout << "   - Ma so khong ton tai! Nhap lai: ";
					cin >> masothe12;
				}
			}
			cout << "=======================" << endl;
			cout << "1. Tiep tuc xoa doc gia" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=======================" << endl;
			string luachon12;
			cout << "-> Moi nhap lua chon: ";
			cin.ignore();
			getline(cin, luachon12);
			while (luachon12 != "1" && luachon12 != "2" && luachon12 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon12);
			}
			if (luachon12 == "1")
				page = 12;
			else if (luachon12 == "2")
				page = 11;
			else if (luachon12 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 13                       // trang này menu nghiệp vụ trong MƯỢN VÀ TRẢ SÁCH
		if (page == 13)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> MUON VA TRA SACH" << endl << endl;
			cout << "1. Muon sach" << endl;
			cout << "2. Tra sach" << endl;
			cout << "3. Trang truoc" << endl;
			cout << "4. Thoat" << endl;
			cout << "===============" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon13;
			getline(cin, luachon13);
			if (luachon13 != "1" && luachon13 != "2" && luachon13 != "3" && luachon13 != "4")
				continue;
			if (luachon13 == "1")
				page = 14;
			else if (luachon13 == "2")
				page = 15;
			else if (luachon13 == "3")
				page = 3;
			else if (luachon13 == "4")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 14                       // trang này để đọc giả MƯỢN SÁCH
		if (page == 14)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> MUON SACH" << endl << endl;
			cout << "-> Nhap ma so doc gia muon muon sach: ";
			int masothe14;
			cin >> masothe14; 
			int size_1, linh14_2 = 0;
			int linh14 = 0;
			int linh14_1 = 0;
			while (linh14 == 0)
			{
				for (unsigned i = 0; i < lib->setAddBorrower().size(); i++)
				{
					if (masothe14 == lib->setAddBorrower()[i]->setCode())
					{
						linh14 = 1;
						string k14;
						cin.ignore();
						cout << "-> Nhap ten sach muon muon: ";
						getline(cin, k14);
						linh14_1 = 0;
						while (linh14_1 == 0)
						{
							for (unsigned j = 0; j	 < lib->setAddBook().size(); j++)
							{
								if (chuan_hoa_main(k14) == chuan_hoa_main(lib->setAddBook()[j]->setName()))
								{
									size_1 = lib->setAddBorrower()[i]->setBorrowBook().size();
									linh14_1 = 1;
									lib->setAddBorrower()[i]->borrowBook(lib->setAddBook()[j]);
									lib->GhiSLSach();
									if (size_1 != lib->setAddBorrower()[i]->setBorrowBook().size())
										linh14_2 = 1;
								}
							}
							if (linh14_1 == 0)
							{
								cout << "   - Ten sach khong ton tai! Nhap lai: ";
								getline(cin, k14);
							}
						}
					}
				}
				if (linh14 == 0)
				{
					cout << "   - Ma so doc gia khong co! Nhap lai: ";
					cin >> masothe14;
				}
			}
			cout << "=====================" << endl;
			cout << "1. Tiep tuc muon sach" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=====================" << endl;
			if (linh14_2 == 1)
				cin.ignore();
			string luachon14;
			cout << "-> Moi nhap lua chon: ";
			getline(cin, luachon14);
			while (luachon14 != "1" && luachon14 != "2" && luachon14 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon14);
			}
			if (luachon14 == "1")
				page = 14;
			else if (luachon14 == "2")
				page = 13;
			else if (luachon14 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 15                       // trang này để đọc giả TRẢ SÁCH
		if (page == 15)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> TRA SACH" << endl << endl;
			cout << "-> Nhap ma so doc gia muon tra sach: ";
			int masothe15;
			cin >> masothe15;
			int linh15 = 0;
			int linh15_1 = 0;
			while (linh15 == 0)
			{
				for (unsigned i = 0; i < lib->setAddBorrower().size(); i++)
				{
					if (masothe15 == lib->setAddBorrower()[i]->setCode())
					{
						if (lib->setAddBorrower()[i]->setBorrowBook().size() == 0)
						{
							cout << endl << " (Khong co sach)" << endl;
							linh15 = 1;
							cin.ignore();
							break;
						}
						linh15 = 1;
						string k15;
						cin.ignore();
						cout << "-> Nhap ten sach muon tra: ";
						getline(cin, k15);
						linh15_1 = 0;
						while (linh15_1 == 0)
						{
							for (unsigned j = 0; j < lib->setAddBorrower()[i]->setBorrowBook().size(); j++)
							{
								if (chuan_hoa_main(k15) == chuan_hoa_main(lib->setAddBorrower()[i]->setBorrowBook()[j]->setName()))
								{
									linh15_1 = 1;
									lib->setAddBorrower()[i]->giveBackBook(lib->setAddBorrower()[i]->setBorrowBook()[j]);
									lib->GhiSLSach();
								}
							}
							if (linh15_1 == 0)
							{
								cout << "   - Ten sach khong ton tai! Nhap lai: ";
								getline(cin, k15);
							}
						}
					}
				}
				if (linh15 == 0)
				{
					cout << "   - Ma so doc gia khong co! Nhap lai: ";
					cin >> masothe15;
				}
			}
			cout << endl << "=====================" << endl;
			cout << "1. Tiep tuc tra sach" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=====================" << endl;
			string luachon15;
			cout << "-> Moi nhap lua chon: ";
			getline(cin, luachon15);
			while (luachon15 != "1" && luachon15 != "2" && luachon15 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon15);
			}
			if (luachon15 == "1")
				page = 15;
			else if (luachon15 == "2")
				page = 13;
			else if (luachon15 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 16                       // trang chứa menu các nghiệp vụ xem thông tin
		if (page == 16)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> XEM THONG TIN" << endl << endl;
			cout << "1. Sach" << endl;
			cout << "2. Doc gia" << endl;
			cout << "3. Nhan vien thu thu" << endl;
			cout << "4. Trang truoc" << endl;
			cout << "5. HOME" << endl;
			cout << "6. Thoat" << endl;
			cout << "=======================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon16;
			getline(cin, luachon16);
			if (luachon16 != "1" && luachon16 != "2" && luachon16 != "3" && luachon16 != "4" && luachon16 != "5" && luachon16 != "6")
				continue;
			if (luachon16 == "1")
				page = 17;
			else if (luachon16 == "2")
				page = 18;
			else if (luachon16 == "3")
				page = 19;
			else if (luachon16 == "4")
				page = 3;
			else if (luachon16 == "5")
				page = 0;
			else if (luachon16 == "6")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 17                       // trang này chứa thông tin tất cả các sách trong thư viện
		if (page == 17)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> XEM THONG TIN : SACH" << endl << endl;
			if (lib->setAddBook().size() == 0)
				cout << " (Khong co sach)" << endl;
			else lib->infoAllBook();
			cout << endl << "=================" << endl;
			cout << "1. Trang truoc" << endl;
			cout << "2. Thoat" << endl;
			cout << "=================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon17;
			getline(cin, luachon17);
			if (luachon17 != "1"&&luachon17 != "2")
				continue;
			if (luachon17 == "1")
				page = 16;
			else if (luachon17 == "2")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 18                       // trang này để xem thông tin đọc giả
		if (page == 18)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> XEM THONG TIN : DOC GIA" << endl << endl;
			if (lib->setAddBorrower().size() == 0)
				cout << " (Khong co doc gia)" << endl;
			else { lib->infoAllBorrower(); }
			cout << endl << "==========================" << endl;
			cout << "1. Xem thong tin chi tiet" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "==========================" << endl;
			string luachon18;
			cout << "-> Moi nhap lua chon: ";
			getline(cin, luachon18);
			if (luachon18 != "1"&&luachon18 != "2"&&luachon18 != "3")
				continue;
			if (luachon18 == "1")
				page = 27;
			else if (luachon18 == "2")
				page = 16;
			else if (luachon18 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 19                       // trang này để xem thông tin nhân viên thủ thư
		if (page == 19)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> XEM THONG TIN : NHAN VIEN THU THU" << endl << endl;
			if (lib->setLibrarian().setName().size() == 0)
				cout << " (Khong co nhan vien thu thu)" << endl;
			else lib->setLibrarian().infoLibrarian();
			cout << endl << "==================" << endl;
			cout << "1. Trang truoc" << endl;
			cout << "2. Thoat" << endl;
			cout << "==================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon19;
			getline(cin, luachon19);
			if (luachon19 != "1"&&luachon19 != "2")
				continue;
			if (luachon19 == "1")
				page = 16;
			else if (luachon19 == "2")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 20                       // trang này là menu chứa các nghiệp vụ TÌM KIẾM          
		if (page == 20)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> TIM KIEM" << endl << endl;
			cout << "1. Sach" << endl;
			cout << "2. Doc gia" << endl;
			cout << "3. Trang truoc" << endl;
			cout << "4. HOME" << endl;
			cout << "5. Thoat" << endl;
			cout << "===============" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon20;
			getline(cin, luachon20);
			if (luachon20 != "1"&&luachon20 != "2"&&luachon20 != "3"&&luachon20 != "4"&&luachon20 != "5")
				continue;
			if (luachon20 == "1")
				page = 21;
			else if (luachon20 == "2")
				page = 25;
			else if (luachon20 == "3")
				page = 3;
			else if (luachon20 == "4")
				page = 0;
			else if (luachon20 == "5")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 21                       // trang này chứa các phương thức tìm kiếm SÁCH
		if (page == 21)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> TIM KIEM : SACH" << endl << endl;
			cout << "1. Theo ten sach" << endl;
			cout << "2. Theo tac gia" << endl;
			cout << "3. Theo ma so" << endl;
			cout << "4. Trang truoc" << endl;
			cout << "5. Thoat" << endl;
			cout << "=================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon21;
			getline(cin, luachon21);
			if (luachon21 != "1" && luachon21 != "2" && luachon21 != "3" && luachon21 != "4" && luachon21 != "5")
				continue;
			if (luachon21 == "1")
				page = 22;
			else if (luachon21 == "2")
				page = 23;
			else if (luachon21 == "3")
				page = 24;
			else if (luachon21 == "4")
				page = 20;
			else if (luachon21 == "5")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 22                       // trang này để TÌM KIẾM SÁCH theo TÊN
		if (page == 22)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> TIM KIEM SACH : THEO TEN SACH" << endl << endl;
			if (lib->setAddBook().size() == 0)
				cout << " (Khong co sach)" << endl;
			else 
			{
				string k22;
				cout << "-> Nhap ten sach muon tim kiem: ";
				getline(cin, k22);
				lib->searchNameBook(k22);
			}
			cout << endl << endl << "=====================" << endl;
			cout << "1. Tiep tuc tim kiem" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=====================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon22;
			getline(cin, luachon22);
			while (luachon22 != "1"&&luachon22 != "2"&&luachon22 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon22);
			}
			if (luachon22 == "1")
				page = 22;
			else if (luachon22 == "2")
				page = 21;
			else if (luachon22 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 23                       // trang này để TÌM KIẾM SÁCH theo TÁC GIẢ
		if (page == 23)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> TIM KIEM SACH : THEO TAC GIA" << endl << endl;
			if (lib->setAddBook().size() == 0)
				cout << " (Khong co sach)" << endl;
			else
			{
				string k23;
				cout << "-> Nhap tac gia cua sach muon tim kiem: ";
				getline(cin, k23);
				lib->searchAuthorBook(k23);
			}
			cout << endl << endl << "=====================" << endl;
			cout << "1. Tiep tuc tim kiem" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=====================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon23;
			getline(cin, luachon23);
			while (luachon23 != "1"&&luachon23 != "2"&&luachon23 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon23);
			}
			if (luachon23 == "1")
				page = 23;
			else if (luachon23 == "2")
				page = 21;
			else if (luachon23 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 24                       // trang này để TÌM KIẾM SÁCH theo MÃ SỐ 
		if (page == 24)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> TIM KIEM SACH : THEO MA SO" << endl << endl;
			int linh24_1 = 0;
			if (lib->setAddBook().size() == 0)
			{
				cout << " (Khong co sach)" << endl;
				linh24_1 = 1;
			}
			else
			{
				int maso24;
				cout << "-> Nhap ma so cua sach muon tim kiem: ";
				cin >> maso24;
				lib->searchCodeBook(maso24);
			}
			cout << endl << endl << "=====================" << endl;
			cout << "1. Tiep tuc tim kiem" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=====================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon24;
			if(linh24_1==0)
				cin.ignore();
			getline(cin, luachon24);
			while (luachon24 != "1"&&luachon24 != "2"&&luachon24 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon24);
			}
			if (luachon24 == "1")
				page = 24;
			else if (luachon24 == "2")
				page = 21;
			else if (luachon24 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 25                       // trang này chứa các phương thức tìm kiếm ĐỌC GIẢ
		if (page == 25)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> TIM KIEM : DOC GIA" << endl << endl;
			cout << "1. Theo ten doc gia" << endl;
			cout << "2. Theo dia chi" << endl;
			cout << "3. Theo ma so the" << endl;
			cout << "4. Trang truoc" << endl;
			cout << "5. Thoat" << endl;
			cout << "=================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon25;
			getline(cin, luachon25);
			if (luachon25 != "1" && luachon25 != "2" && luachon25 != "3" && luachon25 != "4" && luachon25 != "5")
				continue;
			if (luachon25 == "1")
				page = 26;
			else if (luachon25 == "2")
				page = 28;
			else if (luachon25 == "3")
				page = 29;
			else if (luachon25 == "4")
				page = 20;
			else if (luachon25 == "5")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 26                       // trang này để TÌM KIẾM ĐỌC GIẢ theo TÊN
		if (page == 26)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> TIM KIEM DOC GIA : THEO TEN DOC GIA" << endl << endl;
			if (lib->setAddBorrower().size() == 0)
				cout << " (Khong co doc gia)" << endl;
			else
			{
				string k26;
				cout << "-> Nhap ten doc gia muon tim kiem: ";
				getline(cin, k26);
				lib->searchNameBorrower(k26);
			}
			cout << endl << "=====================" << endl;
			cout << "1. Tiep tuc tim kiem" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=====================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon26;
			getline(cin, luachon26);
			while (luachon26 != "1"&&luachon26 != "2"&&luachon26 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon26);
			}
			if (luachon26 == "1")
				page = 26;
			else if (luachon26 == "2")
				page = 25;
			else if (luachon26 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 27                       // trang này để xem chi tiết thông tin cá nhân và tình trạng mượn sách của đọc giả
		if (page == 27)
		{
			system("cls");
			int masothe27;
			int linh27_1 = 0;
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> XEM THONG TIN CHI TIET : DOC GIA " << endl << endl;
			if (lib->setAddBorrower().size() == 0)
			{
				cout << " (Khong co doc gia)" << endl;
				linh27_1 = 1;
			}
			else
			{
				cout << "-> Nhap ma so the doc gia can xem chi tiet: ";
				cin >> masothe27;
				int linh27 = 0;
				while (linh27 == 0)
				{
					for (unsigned i = 0; i < lib->setAddBorrower().size(); i++)
					{
						if (masothe27 == lib->setAddBorrower()[i]->setCode())
						{
							linh27 = 1;
							lib->infoBorrower(*lib->setAddBorrower()[i]);
						}
					}
					if (linh27 == 0)
					{
						cout << "   - Ma so the khong dung! Nhap lai: ";
						cin >> masothe27;
					}
				}
			}
			cout << endl << "=================================" << endl;
			cout << "1. Tiep tuc xem thong tin doc gia" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=================================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon27;
			if (linh27_1 == 0)
				cin.ignore();
			getline(cin, luachon27);
			while (luachon27 != "1"&&luachon27 != "2"&&luachon27 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon27);
			}
			if (luachon27 == "1")
				page = 27;
			else if (luachon27 == "2")
				page = 18;
			else if (luachon27 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 28                       // trang này để TÌM KIẾM ĐỌC GIẢ theo ĐỊA CHỈ
		if (page == 28)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> TIM KIEM DOC GIA : THEO DIA CHI" << endl << endl;
			if (lib->setAddBorrower().size() == 0)
				cout << " (Khong co doc gia)" << endl;
			else
			{
				string k28;
				cout << "-> Nhap dia chi cua doc gia muon tim kiem: ";
				getline(cin, k28);
				lib->searchAddressBorrower(k28);
			}
			cout << endl << endl << "=====================" << endl;
			cout << "1. Tiep tuc tim kiem" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=====================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon28;
			getline(cin, luachon28);
			while (luachon28 != "1"&&luachon28 != "2"&&luachon28 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon28);
			}
			if (luachon28 == "1")
				page = 28;
			else if (luachon28 == "2")
				page = 25;
			else if (luachon28 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}

		// PAGE 29                       // trang này để TÌM KIẾM ĐỌC GIẢ theo MÃ SỐ THẺ
		if (page == 29)
		{
			system("cls");
			cout << endl << "         THU VIEN " << viet_hoa(lib->setName()) << endl << endl;
			cout << ">>> TIM KIEM DOC GIA : THEO MA SO THE" << endl << endl;
			int linh29_1 = 0;
			if (lib->setAddBorrower().size() == 0)
			{
				cout << " (Khong co doc gia)" << endl;
				linh29_1 = 1;
			}
			else
			{
				int maso29;
				cout << "-> Nhap ma so the doc gia muon tim kiem: ";
				cin >> maso29;
				lib->searchCodeBorrower(maso29);
			}
			cout << endl << endl << "=====================" << endl;
			cout << "1. Tiep tuc tim kiem" << endl;
			cout << "2. Trang truoc" << endl;
			cout << "3. Thoat" << endl;
			cout << "=====================" << endl;
			cout << "-> Moi nhap lua chon: ";
			string luachon29;
			if (linh29_1 == 0)
				cin.ignore();
			getline(cin, luachon29);
			while (luachon29 != "1"&&luachon29 != "2"&&luachon29 != "3")
			{
				cout << "   - Nhap lai lua chon: ";
				getline(cin, luachon29);
			}
			if (luachon29 == "1")
				page = 29;
			else if (luachon29 == "2")
				page = 25;
			else if (luachon29 == "3")
			{
				cout << endl << "Cam on da su dung!";
				_getch();
				exit(0);
			}
		}
	}
	return 0;
}