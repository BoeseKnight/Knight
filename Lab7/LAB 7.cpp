#include <iostream>
#include "Class.h"
using namespace std;
//Контейнер: ассоциативный контейнер(ключ - строка, значение - объект).
//Итераторы : вывода и обратный.
//Сортировка : сортировка пузырьком(сортировка по значению).

int main() {
    Associate<automobile> autom;
    automobile a;
    try {
        autom.output();
    }
    catch (Exception& ex) {
        cout <<"WARNING! "<< ex.what_error();
    }
    a["Audi"] = automobile("Max", 7500);
    autom.insert("Audi", a);
    a["BMW"] = automobile("Sam", 2000);
    autom.insert("BMW", a);
    a["RENO"] = automobile("John", 5000);
    autom.insert("RENO", a);
    try {
        autom.duplicate("RENO", a);
    }
    catch (Exception& ex) {
        cout << "WARNING! " << ex.what_error();
    }
    autom.output();
    autom.find({ "John", 5000 });
    autom.output();
    auto i = autom.begin();
    *i = { "Bran", 10000 };
    *(i + 1) = { "Van", 8000 };
    autom.output();
    bubble_sort(autom);
    autom.output();
    return 0;
}
