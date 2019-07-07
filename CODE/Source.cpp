#include<iostream>
#include<string>
#include"Librarian.h"
#include"Book.h"
using namespace std;

int main()
{
	Librarian*l = new Librarian;
	l->inputName();
	l->inputAddress();
	l->inputLibrary();
	l->intputSalary();
	l->inputContract();
	l->info();
	/*Book k;
	k.input();
	k.inputLibrary();
	k.infoAllBook();*/

	return 0;
}