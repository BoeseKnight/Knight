#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Artist {
private:
	string name;
	int year;
	string country;
	string direction;
	int num;
public:
	Artist() {
		this->name = " ";
		this->year = 10;
		this->country = "bel";
		this->direction = "fant";
		this->num = 10;
	}
	Artist(string name, int year, string country, string direction, int num) {
		this->name = name;
		this->year = year;
		this->country = country;
		this->direction = direction;
		this->num = num;
	}
	friend ostream& operator<<(ostream& out, const Artist& art);
	friend istream& operator>>(istream& in, Artist& art);
	friend bool operator==(const Artist num1, const Artist num2);

	string get_name();
	int get_year();
	int get_num();
	string get_country();
	string get_direction();

	void set_name(string);
	void set_country(string);
	void set_year(int);
	void set_num(int);
	void set_direction(string);
};

