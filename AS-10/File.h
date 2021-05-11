#ifndef FILE_H_
#define FILE_H_

#include <iostream>
#include <fstream>

using namespace std;


template <class T>
class File {
	fstream f;
public:
	File();
	void insert(T rec);
	void del(long rn);
	void modify(long rn);
	void search(long rn);
	void displayAll();

};

#endif
