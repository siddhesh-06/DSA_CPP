#include "File.h"
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
File<T>::File()
{
}

template <class T>
void File<T>::insert(T rec)
{

	File<T>::f.open("database.dat", ios::app | ios::binary);
	if (!f)
	{
		cout << "File unable to open !!" << endl;
		f.close();
		return;
	}
	else
	{
		File<T>::f.write((char *)&rec, sizeof(rec));
	}

	File<T>::f.close();
}

template <class T>
void File<T>::del(long rn)
{

	f.open("database.dat", ios::in | ios::binary); //read
	fstream temp;

	temp.open("newDatabase.dat", ios::out | ios::binary); //write

	bool flag = false;

	if (f)
	{
		T s1;
		f.read((char *)&s1, sizeof(s1));
		while (!f.eof())
		{
			if (s1.getRn() != rn)
			{
				temp.write((char *)&s1, sizeof(s1));
			}
			else
			{
				flag = true;
			}
			f.read((char *)&s1, sizeof(s1));
		}

		if (!flag)
		{
			cout << "Student not found !!" << endl;
		}

		temp.close();
		f.close();

		remove("database.dat");
		rename("newDatabase.dat", "database.dat");
	}
	else
	{
		temp.close();
		f.close();

		cout << "Records not found !!" << endl;
	}
}

template <class T>
void File<T>::modify(long rn)
{

	f.open("database.dat", ios::in | ios::binary);
	fstream temp;

	temp.open("newDatabase.dat", ios::out | ios::binary);

	bool flag = false;

	if (f)
	{
		T s1;
		f.read((char *)&s1, sizeof(s1));
		while (!f.eof())
		{

			if (s1.getRn() == rn)
			{
				s1.input();
				temp.write((char *)&s1, sizeof(s1));
				flag = true;
			}
			else
			{
				temp.write((char *)&s1, sizeof(s1));
			}

			f.read((char *)&s1, sizeof(s1));
		}

		if (!flag)
		{
			cout << "Student not found !!" << endl;
		}

		temp.close();
		f.close();

		remove("database.dat");
		rename("newDatabase.dat", "database.dat");
	}
	else
	{
		temp.close();
		f.close();

		cout << "Records not found !!" << endl;
	}
}

template <class T>
void File<T>::search(long rn)
{

	File<T>::f.open("database.dat", ios::in | ios::binary);

	if (!f)
	{
		cout << "File unable to open !!" << endl;
		f.close();
		return;
	}

	bool flag = false;

	T s1;
	File<T>::f.read((char *)&s1, sizeof(s1));

	while (!File<T>::f.eof()) //to end of file
	{
		if (s1.getRn() == rn)
		{
			s1.display();
			flag = true;
			break;
		}
		File<T>::f.read((char *)&s1, sizeof(s1));
	}

	if (!flag)
	{
		cout << "Student not found !!" << endl;
	}

	File<T>::f.close();
}

template <class T>
void File<T>::displayAll()
{

	f.open("database.dat", ios::in | ios::binary);

	if (!f)
	{
		cout << "\nFile not found !!" << endl;
		f.close();
		return;
	}

	T s1;
	f.read((char *)&s1, sizeof(s1));
	while (!f.eof())
	{
		s1.display();
		f.read((char *)&s1, sizeof(s1));
	}

	f.close();
}
