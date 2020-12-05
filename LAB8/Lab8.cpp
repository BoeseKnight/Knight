#include <iostream>
#include <fstream>
#include <string>

#include "Exception.h"
#include "File.h"
#include"Artist.h"

using namespace std;



int main()
{
    Artist u1("Ilya", 1780, "Belarus", "Drama", 6);
    Artist u2("Max", 1900, "Russia", "Fantasy", 7);
    Artist u3("Conor", 2000, "Germany", "Novel", 2);
    Artist u4("Marat", 1200, "France", "Science", 1);
    Artist flg[4] = { u1,u2,u3,u4 };
    File f1("D:\\1.txt", txt);
    f1.open("w");
    f1.set_size(4);
    f1 << u1;
    f1 << u2;
    f1 << u3;
    f1 << u4;
    f1.close();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "\n\n";
    File f2("D:\\2.txt", bin);
    f2.open("w");
    f2.set_size(4);
    f2 << u1;
    f2 << u2;
    f2 << u3;
    f2 << u4;
    f2.close();
    f2.open("r");
    cout << f2;
    f2.close();
    cout << "\n\n";
    File f3("D:\\3.bin", bin);
    f3.open("w");
    f3.set_size(4);
    f3 << u1;
    f3 << u2;
    f3 << u3;
    f3 << u4;
    f3.close();
    f3.open("r");
    cout << f3;
    f3.close();
    cout << "\n\n";

    int a = 0, line = 0;
    /*do {
        cout << "Enter the line that you want to change:" << endl;
        cin >> line;
        f2.edit(line, flg);
        f2.open("r");
        cout << f2;
        f2.close();
        cout << "Do you want to change anything else?\n1 - yes\n0 - no" << endl;
        rewind(stdin);
        cin >> a;
    } while (a);*/
    cout << "Sort by name:" << endl;
    f1.bubble_sort_name();
    f1.open("r");
    cout << f1;
    f1.close();

    cout << "Sort by num:" << endl;
    f1.bubble_sort_num();
    f1.open("r");
    cout << f1;
    f1.close();
    cout << "Sort by year:" << endl;
    f1.bubble_sort_year();
    f1.open("r");
    cout << f1;
    f1.close();


    return 0;
}