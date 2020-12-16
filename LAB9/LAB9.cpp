//Контейнер: ассоциативный контейнер(ключ - строка, значение - объект).
//Итераторы : вывода и обратный.
//Алгоритмы :
//    1.	Сумма целых положительных чисел в строке(числа – слова, содержащие только цифры).
//    2.	функция нахождения первого элемента, который удовлетворяет заданным критериям.
//    3.	функция, которая удаляет элементы, удовлетворяющие условию.


#include <iostream>
#include <map>
#include <string>
#include "Class.h"
#include "Algorithms.h"
using namespace std;
using namespace mySpace;

int main()
{
    mySpace::Algorithm A; 
    cout << "ALGORITHM 1:\n";
    A.alg1();
    map<string, automobile > container;
    map<string, automobile > ::iterator find;
    automobile auto1("Ilya", 5579, 2000);
    automobile auto2("Vova", 4444, 10000);
    automobile auto3("Max", 6969, 1000);
    automobile auto4("Borya", 2233, 12000);
    container.insert(pair<string, automobile>("audi", auto1));
    container.insert(pair<string, automobile>("bmw", auto2));
    container.insert(pair<string, automobile>("merc", auto3));
    container.insert(pair<string, automobile>("reno", auto4));
    cout << "\nCONTAINER :\n";
    for (auto start = container.begin(); start != container.end(); start++) {
        cout << start->first << " " << start->second;
    }
    auto end = container.rbegin();
    auto start = container.rend();
    cout << "\nALGORITHM 2:\n";
    A.alg2(end, start);
    cout << "\nALGORITHM 3:\n";
    A.alg3(container);
    cout << "\nAfter deleting:\n";
    for (auto start = container.begin(); start != container.end(); start++) {
        cout << start->first << " " << start->second;
    }
}