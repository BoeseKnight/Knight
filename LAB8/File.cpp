#include "File.h"
#include "Artist.h"
#include "Exception.h"

File& operator<<(File& file, const char* s)
{
	try {
		if (!file.file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	string str = s;
	file.file << str;
	return file;
}

fstream& operator<<(fstream& out, Artist& art) {
	try {
		if (!out.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	int a = out.tellg();
	string art_name = art.get_name();
	size_t len1 = art_name.length() + 1;

	int num = art.get_num();
	int year = art.get_year();

	string country = art.get_country();
	size_t len2 = country.length() + 1;

	string direction = art.get_direction();
	size_t len3 = direction.length() + 1;

	out.write((char*)(&len1), sizeof(len1));
	out.write((char*)(art_name.c_str()), len1);

	out.write((char*)(&num), sizeof(num));
	out.write((char*)(&year), sizeof(year));

	out.write((char*)(&len2), sizeof(len2));
	out.write((char*)(country.c_str()), len2);

	out.write((char*)(&len3), sizeof(len3));
	out.write((char*)(direction.c_str()), len3);

	return out;
}

File& operator<<(File& file, Artist& art)
{
	int pos = 0, a = 0, size = 0;
	try {
		if (!file.file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	if (file.key == txt) {
		file.file << art.get_name() << " " << art.get_num() << " " << art.get_year() << " " << art.get_country() << " " << art.get_direction()<<endl;
	}
	else if (file.key == bin) {
		string name = art.get_name();
		size_t len1 = name.length() + 1;

		int num = art.get_num();
		int year = art.get_year();

		string country = art.get_country();
		size_t len2 = country.length() + 1;

		string direction = art.get_direction();
		size_t len3 = direction.length() + 1;

		file.file.write((char*)(&len1), sizeof(len1));
		file.file.write((char*)(name.c_str()), len1);

		file.file.write((char*)(&num), sizeof(num));
		file.file.write((char*)(&year), sizeof(year));

		file.file.write((char*)(&len2), sizeof(len2));
		file.file.write((char*)(country.c_str()), len2);

		file.file.write((char*)(&len3), sizeof(len3));
		file.file.write((char*)(direction.c_str()), len3);
	}
	return file;
}



ostream& operator<<(ostream& out, File& file)
{
	int a = 0;
	try {
		if (!file.file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	if (file.key == txt) {
		string str;
		while (!file.file.eof()) {
			getline(file.file, str);
			a = file.file.tellg();
			cout << str << endl;
		}
	}
	else if (file.key == bin) {
		int i = 0;
		int size = 0, step = 0;
		while (i < file.size) {
			int num;
			int year;

			size_t len;

			file.file.read((char*)(&len), sizeof(len));
			char* name = new char[len];

			file.file.read((char*)(name), len);
			name[len - 1] = '\0';

			file.file.read((char*)(&num), sizeof(int));
			file.file.read((char*)(&year), sizeof(int));

			file.file.read((char*)(&len), sizeof(len));
			char* country = new char[len];

			file.file.read((char*)(country), len);
			country[len - 1] = '\0';

			file.file.read((char*)(&len), sizeof(len));
			char* direction = new char[len];

			file.file.read((char*)(direction), len);
			direction[len - 1] = '\0';

			cout << name << " " << num << " " << year << " " << country << " " << direction << endl;

			delete[] name;
			delete[] country;
			delete[] direction;
			i++;

		}
	}
	return out;
}



void File::edit(int line, Artist mas[]) {
	this->open("wr");

	int a, b;

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
		return;
	}
	Artist tmp;
	if (this->key == txt) {
		string temp;
		for (int i = 0; i < line - 1; i++) {
			getline(this->file, temp);
		}
		getline(this->file, temp, ' ');
		tmp.set_name(temp);
		getline(this->file, temp, ' ');
		tmp.set_num(stoi(temp));
		getline(this->file, temp, ' ');
		tmp.set_year(stoi(temp));
		getline(this->file, temp);
		tmp.set_country(temp);
		getline(this->file, temp);
		tmp.set_direction(temp);
	}
	else if (this->key == bin) {
		size_t len;
		for (int i = 0; i < line; i++) {
			this->file.read((char*)(&len), sizeof(len));
			char* n = new char[len];
			string name;
			string country;
			int num = 0;
			int year = 0;
			string direction;

			this->file.read((char*)(n), len);
			name = n;
			name[len - 1] = '\0';
			this->file.read((char*)(&num), sizeof(int));
			this->file.read((char*)(&year), sizeof(int));


			this->file.read((char*)(&len), sizeof(len));
			this->file.read((char*)(n), len);
			country = n;
			country[len - 1] = '\0';

			this->file.read((char*)(&len), sizeof(len));
			this->file.read((char*)(n), len);
			direction = n;
			direction[len - 1] = '\0';

			tmp.set_name(name);
			tmp.set_num(num);
			tmp.set_year(year);
			tmp.set_country(country);
			tmp.set_direction(direction);
		}
		a = file.tellg();
	}

	cout << "What do you want to change?\n1 - name\n2-num\n3-year\n4-country\n5-direction" << endl;
	int choice;
	cin >> choice;
	cout << "Put new data: ";
	switch (choice) {
	case 1: {
		string a;
		rewind(stdin);
		cin >> a;
		tmp.set_name(a);
		break;
	}
	case 2: {
		int a;
		cin >> a;
		tmp.set_num(a);
		break;
	}
	case 3: {
		int a;
		cin >> a;
		tmp.set_year(a);
		break;
	}
	case 4: {
		string a;
		cin >> a;
		tmp.set_country(a);
		break;
	}
	case 5: {
		string a;
		cin >> a;
		tmp.set_direction(a);
		break;
	}
	}
	a = file.tellg();
	file.seekg(0, ios_base::end);
	b = file.tellg();
	this->file.seekg(0, ios_base::beg);
	if (this->key == txt) {
		string temp;
		for (int i = 0; i < line - 1; i++) {
			getline(this->file, temp);
		}
		int pos = this->file.tellg();
		this->file.seekg(pos, ios_base::beg);
		this->file << tmp;
		return;
	}
	else if (this->key == bin) {
		for (int i = 0; i < line - 1; i++) {

			size_t len;
			this->file.read((char*)(&len), sizeof(len));
			char* n = new char[len];
			string name;
			string country;
			int num = 0;
			int year = 0;
			string direction;
			this->file.read((char*)(n), len);
			name = n;
			name[len] = '\0';
			this->file.read((char*)(&num), sizeof(int));
			this->file.read((char*)(&year), sizeof(int));
			this->file.read((char*)(n), len);
			country = n;
			country[len] = '\0';
			this->file.read((char*)(n), len);
			direction = n;
			direction[len] = '\0';

			this->file.read((char*)(&len), sizeof(len));
			this->file.read((char*)(&n), len);

			delete[]n;
		}
		int pos = this->file.tellg();

		char* last = new char[b - a];
		this->file.read((char*)last, b - a);

		this->close();
		this->open("w");
		pos = this->file.tellg();
		file << tmp;
		for (int i = 0; i < get_size(); i++) {
			if (i != line - 1)
				file << mas[i];
			else {
				mas[i].set_name(tmp.get_name());
				mas[i].set_num(tmp.get_num());
				mas[i].set_year(tmp.get_year());
				mas[i].set_country(tmp.get_country());
				mas[i].set_direction(tmp.get_direction());
			}
		}
	}

	this->close();
}



void File::bubble_sort_name() {
	string temp;
	string j1, j2;
	int pos;
	this->open("wr");
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
		return;
	}
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = 0; j < this->size - i - 1; j++) {
			this->file.seekg(0, ios_base::beg);
			for (int k = 0; k < j; k++) {
				getline(this->file, j1);
			}
			getline(this->file, j1, ' ');
			getline(this->file, j2);
			getline(this->file, j2, ' ');
			if (j1 > j2) {
				this->file.seekg(0, ios_base::beg);
				pos = this->file.tellg();
				for (int k = 0; k <= j; k++) {
					getline(this->file, j1);
					pos = this->file.tellg();
				}
				temp = j1;
				getline(this->file, j2);
				this->file.seekg(0, ios_base::beg);
				for (int k = 0; k < j; k++) {
					getline(this->file, j1);
				}
				pos = this->file.tellg();
				this->file.seekg(pos, ios_base::beg);
				this->file << j2 << '\n';
				this->file << temp << '\n';
			}
		}
	}
	this->close();
}
//
void File::bubble_sort_num() {
	string temp;
	string j1, j2;
	int i1, i2;
	int pos;
	this->open("wr");
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
		return;
	}
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = 0; j < this->size - i - 1; j++) {
			this->file.seekg(0, ios_base::beg);
			for (int k = 0; k < j; k++) {
				getline(this->file, j1);
			}
			getline(this->file, j1, ' ');
			getline(this->file, j1, ' ');
			getline(this->file, j2);
			getline(this->file, j2, ' ');
			getline(this->file, j2, ' ');
			i1 = stoi(j1);
			i2 = stoi(j2);
			if (i1 > i2) {
				this->file.seekg(0, ios_base::beg);
				pos = this->file.tellg();
				for (int k = 0; k <= j; k++) {
					getline(this->file, j1);
					pos = this->file.tellg();
				}
				temp = j1;
				getline(this->file, j2);
				this->file.seekg(0, ios_base::beg);
				for (int k = 0; k < j; k++) {
					getline(this->file, j1);
				}
				pos = this->file.tellg();
				this->file.seekg(pos, ios_base::beg);
				this->file << j2 << '\n';
				this->file << temp << '\n';
			}
		}
	}
	this->close();
}
//
void File::bubble_sort_year() {
	string temp;
	string j1, j2;
	int i1, i2;
	int pos;
	this->open("wr");
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
		return;
	}
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = 0; j < this->size - i - 1; j++) {
			this->file.seekg(0, ios_base::beg);
			for (int k = 0; k < j; k++) {
				getline(this->file, j1);
			}
			getline(this->file, j1, ' ');
			getline(this->file, j1, ' ');
			getline(this->file, j1, ' ');
			getline(this->file, j2);
			getline(this->file, j2, ' ');
			getline(this->file, j2, ' ');
			getline(this->file, j2, ' ');
			i1 = stoi(j1);
			i2 = stoi(j2);
			if (i1 > i2) {
				this->file.seekg(0, ios_base::beg);
				pos = this->file.tellg();
				for (int k = 0; k <= j; k++) {
					getline(this->file, j1);
					pos = this->file.tellg();
				}
				temp = j1;
				getline(this->file, j2);
				this->file.seekg(0, ios_base::beg);
				for (int k = 0; k < j; k++) {
					getline(this->file, j1);
				}
				pos = this->file.tellg();
				this->file.seekg(pos, ios_base::beg);
				this->file << j2 << '\n';
				this->file << temp << '\n';
			}
		}
	}
	this->close();
}

//void File::insertionSort_name() // сортировка вставками
//{
//	string temp, j1, j2, j3; // временная переменная для хранения значения элемента сортируемого массива
//	int pos1,pos2, item=0;// индекс предыдущего элемента
//	this->open("wr");
//	try {
//		if (!file.is_open())
//		{
//			throw 1;
//		}
//	}
//	catch (int i)
//	{
//		Exception ex(i);
//		ex.Print();
//		return;
//	}
//	for ( int counter = 1; counter < this->size - 1; counter++)
//	{
//		this->file.seekg(0, ios_base::beg);
//		getline(this->file, temp, ' ');
//		for (int k = 0; k < counter; k++) {
//			getline(this->file, temp);
//			getline(this->file, temp, ' ');
//		} // инициализируем временную переменную текущим значением элемента массива
//		item = counter - 1;
//		this->file.seekg(0, ios_base::beg);
//		getline(this->file, j1, ' ');
//		for (item = 0; item < counter - 1; item++) {
//			getline(this->file, j1);
//			getline(this->file, j1, ' ');
//		}
//		while (item >= 0 && j1>temp/*arrayPtr[item] > temp*/) // пока индекс не равен 0 и предыдущий элемент массива больше текущего
//		{
//			this->file.seekg(0, ios_base::beg);
//			getline(this->file, j1, ' ');
//			for (int k = 0; k < item; k++) {
//				getline(this->file, j1);
//				pos1 = this->file.tellg();
//				getline(this->file, j1, ' ');
//			}
//			getline(this->file, j2);
//			pos2 = this->file.tellg();
//			getline(this->file, j2, ' ');
//			this->file.seekg(pos1, ios_base::beg);
//			this->file << temp << '\n';
//			this->file.seekg(pos2, ios_base::beg);
//			this->file << j1 << '\n';
//			arrayPtr[item + 1] = arrayPtr[item]; // перестановка элементов массива
//			arrayPtr[item] = temp;
//			item--;
//		}
//	}
//}