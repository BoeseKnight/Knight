#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Exception.h"
#include "Artist.h"
using namespace std;

enum Key {
	none = 0,
	txt,
	bin
};

class File
{
private:
	fstream file;
	string path;
	Key key; //none txt bin
	int size;
public:
	File() :path("Space"), key(none), size(0) {}
	File(string path, Key key) {
		this->path = path;
		this->key = key;
		this->size = 0;
	}
	~File() { file.close(); }
	void open(string mode) {
		switch (key) {
		case txt: {
			if (mode == "r") {
				file.open(path, ios_base::in);
			}
			else if (mode == "add") {
				file.open(path, ios_base::app);
			}
			else if (mode == "w") {
				file.open(path, ios_base::out);
			}
			else if (mode == "wr") {
				file.open(path, ios_base::in | ios_base::out);
			}
		}
				break;
		case bin: {
			if (mode == "r") {
				file.open(path, ios_base::binary | ios_base::in);
			}
			else if (mode == "add") {
				file.open(path, ios_base::binary | ios_base::app);
			}
			else if (mode == "w") {
				file.open(path, ios_base::binary | ios_base::out);
			}
			else if (mode == "wr") {
				file.open(path, ios_base::binary | ios_base::in | ios_base::out);
			}
		}
				break;
		}
		try {
			if (!file.is_open())
			{
				throw 1;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
			exit(-1);
			return;
		}
	}
	void close() {
		file.close();
	}
	void begin() {
		file.seekg(0, ios_base::beg);
	}
	void set_size(int s) {
		size = s;
	}
	int get_size() {
		return	size;
	}
	void bubble_sort_name();
	void bubble_sort_num();
	void bubble_sort_year();

	void edit(int line, Artist[]);
	Artist return_art() {
		string str;
		int i1;
		Artist art;

		getline(this->file, str, ' ');
		art.set_name(str);
		getline(this->file, str, ' ');
		art.set_country(str);
		getline(this->file, str, ' ');
		art.set_direction(str);
		getline(this->file, str, ' ');
		i1 = stoi(str);
		art.set_num(i1);
		getline(this->file, str, ' ');
		i1 = stoi(str);
		art.set_year(i1);
		return art;
	}
	friend File& operator<<(File& file, Artist& art);
	friend File& operator<<(File& file, const char* s);
	friend ostream& operator<<(ostream& out, File& file);

};



