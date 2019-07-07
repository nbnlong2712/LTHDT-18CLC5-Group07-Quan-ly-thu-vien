#include"Library.h"

void Library::inputNameLibrary()
{
	cout << "Enter library name: ";
	getline(cin, m_name);	
}

void Library::print()
{
	cout << "Library name: " << m_name << endl;
}