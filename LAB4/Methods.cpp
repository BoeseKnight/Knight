#include <iostream>
#include <string.h>
#include "Class.h"

using namespace std;
void cooking::set_meat() {
    int choice = 0;
    cout << "What meat do you prefer?\nPress 1- beef; 2-pork; 3-chicken.\n";
    do {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cin >> choice;
    } while (!choice || choice > 3 || choice < 1);
    if (choice == 1) {
        meat = "Beef";
    }
    else if (choice == 2) {
        meat = "Pork";
    }
    else {
        meat = "Chicken";
    }

}
void cooking::set_garnish() {
    int choice = 0;
    cout << "What garnish do you prefer?\nPress 1- rice; 2-pasta; 3-potato.\n";
    do {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cin >> choice;
    } while (!choice || choice > 3 || choice < 1);
    if (choice == 1) {
        garnish = "Rice";
    }
    else if (choice == 2) {
        garnish = "Pasta";
    }
    else {
        garnish = "Potato";
    }
}
void cooking::set_desert() {
    int choice;
    cout << "What desert do you prefer?\nPress 1- Napoleon; 2-Teramissu.\n";
    do {
        if (cin.fail()) 
        {
            cin.clear(); 
            cin.ignore();
        }
        cin >> choice;
    } while (!choice || choice > 2 || choice < 1);
    if (choice == 1) {
        desert = "Napoleon";
    }
    else {
        desert = "Teramissu";
    }

}

void dish_meat::set_sauce() {
    int choice = 0;
    cout << "What sauce for your meat do you prefer?\nPress 1- Mushroom 2-Ketchup.\n";
    do {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cin >> choice;
    } while (!choice || choice > 2 || choice < 1);
    if (choice == 1) {
        sauce = "Mushroom";
    }
    else {
        sauce = "Ketchup";
    }

}
void dish_meat::cooking_meat() {
    cout << "\nYour " << meat << " is cooking in the oven on the 180 degrees...\n";
}

void desert_cream::cooking_cream() {
    cout << "\nThe cream for your desert is cooking...\n";
    cream = desert + " cream";
}

void dish_garnish::quantity() {
    cout << "How many portions of garnish do you want?\n";
    do {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cin >> choice;
    } while (!choice);
    water = choice * 1;
    salt = choice * 10;
}
void dish_garnish::cooking_garnish() {
    cout << "Boiling " << water << "L of water to 100 degrees. Pouring " << salt << "g of salt and cooking your " << garnish<<endl;
}

void desert_making:: cooking_desert() {
    cout << "Soaking cakes with "<<cream<<"..."<< " Your " << desert << " is ready. How many pieces do you want?\n";
    cin >> pieces;
    cout << "Cutting "<<desert<<" into "<<pieces<<"... Ready!\n";
}

void serve::order() {
    cout << "\nYour order is: " << meat << " with " << sauce << " sauce with " << choice<<" portions of "<<garnish << ". \nDesert " << desert << ". \nYou're welcome! Have a good appetite!\n";
}
void serve::rating() {
    cout << "Rate me from 1 to 10, please! :)";
    do {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        cin >> rate;
    } while (!rate || rate > 10 || rate < 1);
    cout << "THANKS!";
}