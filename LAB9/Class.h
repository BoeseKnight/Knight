#pragma once
#include <iostream>
#include <string>
using namespace std;
namespace mySpace {
	class Exception
	{
	protected:
		int error;
	public:
		Exception()
		{
			error = 0;
		}
		Exception(int _error)
		{
			error = _error;
		}
		~Exception() { };
		void Print()
		{
			if (this->error == 1)
			{
				std::cout << "File isn't open!" << std::endl;
			}
		}
	};
	class automobile {
	private:
		string name;
		int id, mileage;
	public:
		automobile(string fio, int number, int mile) {
			id = number;
			name = fio;
			mileage = mile;
		}
		automobile() {
			id = 0;
			name = " ";
			mileage = 0;
		}
		bool operator> (int choice) { 
			return mileage > choice;
		}
		friend std::ostream& operator<< (std::ostream& out, const automobile& autom) {
			out << autom.name << ' ' << autom.id << ' ' << autom.mileage << '\n';
			return out;
		}
		~automobile() {}
	};
}