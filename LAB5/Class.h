#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class cooking {
protected:
    string name;
public:
    cooking() {};
  
    cooking(string meal) {
        name = meal;
    }
    virtual ~cooking() {};
    void virtual output() = 0;
    void virtual count() = 0;
};

class dish_meat :public cooking {
protected:
    int spices;
    int grams;
    int choice;
public:
    dish_meat() {
        grams = 200;
        spices = 1;
        choice = 1;
    };
    dish_meat(string meal, int number) :cooking(meal) {
        choice = number;
        grams = 200;
        spices = 1;
    }
    void virtual count() {
        cout << "You need " << choice * spices << " spoon of spices and " << choice * grams << "g of meat to make "<<choice<<" portions of steak\n\n\n";
    }
    void virtual output() {
        cout << "Ingridients of " << name << ": " << spices<<" spoons of spices and " << grams << "g of meat for one portion\n";
    }
    virtual ~dish_meat() {};
};
class desert :public cooking {
protected:
    int cream;
    int cookies;
    int num;
public:
    desert() {
        cream = 250;
        cookies = 15;
        num = 1;
    };
    desert(string meal, int quantity) : cooking(meal) {
        num = quantity;
        cream = 250;
        cookies = 15;
    };
    void virtual count() {
        cout << "You need " << num * cream << "g of cream and " << num * cookies << " cookies to make "<<num<<" portions of "<<name<<"\n\n\n";
    }
    void virtual output() {
        cout << "Ingridients of "<<name<<": " << cream << "g of cream and "<< cookies<< " cookies for one portion\n";
    }
    virtual ~desert() {};
};
class dish_garnish :public dish_meat {
protected:
    int water;
    int salt;
public:
    dish_garnish() {
        water = 1;
        salt = 10;
    }
    dish_garnish(string meal, int number) :dish_meat(meal, number) {
        water = 1;
        salt = 10;
    }
    void virtual count() {
        cout << "You need " << choice * water << "L of water and " << choice * salt << "g of salt for "<<choice<<" portions\n\n\n";
    }
    void virtual output() {
        cout << "Ingridients of " << name << ": " << water << "L of water and " << salt << "g of salt for one portion\n";
    }
    virtual ~dish_garnish() {};
};