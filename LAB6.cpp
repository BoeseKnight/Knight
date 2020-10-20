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
}
int main()
{
    int size, key,i=0;
    cout << "Enter a size of array\n";
    cin >> size;
    int *arr=new int[size];
    cout << "Enter a key to find\n";
    cin >> key;
    for (i = 0; i < size; i++) {
        bool fail = true;
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
    cout<<"The index of the found element is "<<search<int>(arr, key, size)<<" and it is equal key="<<arr[search<int>(arr, key, size)];
}
