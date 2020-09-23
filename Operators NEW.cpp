#include <iostream>
using namespace std;

class matrix {
	friend ostream& operator<<(ostream &, const matrix &);
private:
	int n, m;
	char** mtrx;
public:
	matrix(int a, int b) {
		m = a;
		n = b;
		mtrx = new char*[m];
		for (int i = 0; i < m; i++) {
			mtrx[i] = new char[n];
		}
	}
	matrix() {
		m = 1;
		n = 1;
		mtrx = new char*[m];
		mtrx[1] = new char[n];
	}
	matrix(matrix &obj) {
		m = obj.m;
		n = obj.n;
		mtrx = new char*[m];
		for (int i = 0; i < m; i++) {
			mtrx[i] = new char[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mtrx[i][j] = obj.mtrx[i][j];
			}
		}
	}
	~matrix() {
		for (int i = 0; i < m; i++) {
			delete mtrx[i];
		}
		delete[]mtrx;
	}
	void MtrxInput() {
		cout << "Enter a number of rows\n";
		cin >> m;
		cout << "Enter a number of columns\n";
		cin >> n;
		mtrx = new char*[m];
		for (int i = 0; i < m; i++) {
			mtrx[i] = new char[n];
		}
		cout << "Enter the elements\n";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mtrx[i][j];
			}
		}
	}
	void MtrxOutput() {
		cout << "\nYour matrix:\n";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << mtrx[i][j] << " ";
			}
		}
	}
	void AccessChange(int a, int b, char value) {
		mtrx[a - 1][b - 1] = value;
	}
	void AccessPrint(int a, int b) { //метод доступа к одиночному элементу(чтение)
		cout << mtrx[a - 1][b - 1];
	}
	char* operator[](int i) {
		return mtrx[i-1];
	}
	char& operator()(int row, int col) {
		return mtrx[row - 1][col - 1];
	}
	matrix& operator= (const matrix &obj)
	{
		m = obj.m;
		n = obj.n;
		mtrx = new char*[m];
		for (int i = 0; i < m; i++) {
			mtrx[i] = new char[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mtrx[i][j] = obj.mtrx[i][j];
			}
		}
		return *this;
	}
};

int main()
{
	int size;
	matrix obj1, *array;
	cout << "Enter a size of array of matrix\n";
	cin >> size;
	array = new matrix[size];
	for (int i = 0; i < size; i++) {
		array[i] = matrix(2, 2);
	}
	for (int i = 0; i < size; i++) {
		array[i].MtrxInput();
	}
	for (int i = 0; i < size; i++) {
		array[i].MtrxOutput();
	}
	delete[] array;
	/*obj1.MtrxInput();
	cout << obj1;
	obj1.AccessChange(1, 3, '5');
	obj1.MtrxOutput();
	obj1(1, 1) = 'G';
	obj1.MtrxOutput();
	obj1[2][1] = 'l';
	obj1.MtrxOutput();*/
	return 0;
}
ostream& operator<< (ostream& output, const matrix& obj)
{
	for (int i = 0; i < obj.m; i++)
	{
		for (int j = 0; j < obj.n; j++)
		{
			output << obj.mtrx[i][j];
		}
		cout << endl;
	}
	output << endl;
	return output;
}