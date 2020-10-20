#include <iostream>
#include <string.h>
#include "Class.h"
using namespace std;


int main()
{
    int i = 0;
    int size;
    bool fail = true;
    cout << "Enter a size of array.\n";
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
    cooking** mas = new cooking*[size];
    for (i = 0; i < size/3; i++) {
        mas[i] = new desert("Napoleon", i);
        mas[i]->count();
    }
    for (i = size/3; i < (size*2)/3; i++) {
        mas[i] = new dish_meat("Beef", i);
        mas[i]->count();
    }
    for (i = (size * 2) / 3; i < size; i++) {
        mas[i] = new dish_garnish("Rice", i);
        mas[i]->count();
    }
    /*desert a("Napoleon", 2);
    a.output();
    a.count();
    dish_meat b("Beef", 3);
    b.output();
    b.count();
    dish_garnish c("Rice", 2);
    c.output();
    c.count();*/

}
