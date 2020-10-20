// 4.Функция поиска первого элемента в массиве по заданному ключу.
#include <iostream>
using namespace std;
template <typename T> 
int search(T* array, T key, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;
        }
    } 
    return -1;
}
int main()
{
    int size;
    /*int key, i = 0;
    cout << "Enter a size of array\n";
    bool fail = true;
    do {

        cin >> size;
        if (cin.fail() || cin.rdbuf()->in_avail() > 1) {
            cout << "Error" << endl;
        }
        else
            fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    int *arr=new int[size];
    cout << "Enter a key to find\n"; 
    fail = true;
    do {
       
        cin >> key;
        if (cin.fail() || cin.rdbuf()->in_avail() > 1) {
            cout << "Error" << endl;
        }
        else
            fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    for (i = 0; i < size; i++) {
        fail = true;
        do {
            cin >> arr[i];
            if (cin.fail() || cin.rdbuf()->in_avail() > 1){
                cout << "Error" << endl;
            }
            else
                fail = false;
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        } while (fail);
    }
    if (search<int>(arr, key, size) != -1)
        cout << "The index of the found element is " << search<int>(arr, key, size) << " and it is equal key=" << arr[search<int>(arr, key, size)];
    else cout << "There is no such element((";*/
    cout << "Enter a size of string\n";
    bool fail = true;
    do {
        cin >> size;
        if (cin.fail() || cin.rdbuf()->in_avail() > 1) {
            cout << "Error" << endl;
        }
        else
            fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    char* str = new char[size];
    char key1;
    cout << "Enter a key to find\n";
    cin >> key1;
    cin.ignore();
    cin.getline(str, size);
    search<char>(str, key1, size);
    if (search<char>(str, key1, size) != -1)
        cout << "The index of the found element is " << search<char>(str, key1, size) << " and it is equal key=" << str[search<char>(str, key1, size)];
    else cout << "There is no such element((";
}
