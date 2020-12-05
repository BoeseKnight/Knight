#include "Artist.h"
#include "Exception.h"

ostream& operator<<(ostream& out, const Artist& art)
{
	try {
		if (art.name == " ")
		{
			throw 2;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	out << art.name << " " << art.num << " " << art.year << " " << art.country << " " << art.direction << endl;
	return out;
}

istream& operator>>(istream& in, Artist& art)
{
	in >> art.name;
	in >> art.num;
	in >> art.country;
	in >> art.direction;
	in >> art.year;
	return in;
}

bool operator==(Artist num1, Artist num2) {
	if (num1.get_name() == num2.get_name() && num1.get_num() == num2.get_num() && num1.get_year() == num2.get_year() &&
		num1.get_country() == num2.get_country() && num1.get_direction() == num2.get_direction()) {
		return true;
	}
	else {
		return false;
	}
}


string Artist::get_name() {
	return this->name;
}
int Artist::get_num() {
	return this->num;
}
int Artist::get_year() {
	return this->year;
}
string Artist::get_country() {
	return this->country;
}
string Artist::get_direction() {
	return this->direction;
}

void Artist::set_name(string temp) {
	this->name = temp;
}
void Artist::set_num(int temp) {
	this->num = temp;
}
void Artist::set_year(int temp) {
	this->year = temp;
}
void Artist::set_country(string temp) {
	this->country = temp;
}
void Artist::set_direction(string temp) {
	this->country = temp;
}