#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class cooking {
protected:
    string meat;
    string garnish;
    string desert;
public:
    cooking() {};
    cooking(string a, string b, string c) {
        meat = a;
        garnish = b;
        desert = c;
    }
    void set_meat();
    void set_garnish();
    void set_desert();
};

class dish_meat :public virtual cooking {
protected:
    string sauce;
public:
    dish_meat() {};
    dish_meat(string a, string b, string c, string d) : cooking(a, b, c) {
        sauce = d;
    }
    void set_sauce();
    void cooking_meat();
};
class desert_cream :public virtual cooking {
protected:
    string cream;
public:
    desert_cream() {};
    desert_cream(string a) {
        cream = a;
    };
    void cooking_cream();
};
class dish_garnish :public dish_meat {
protected:
    int choice;
    int water;
    int salt;
public:
    dish_garnish() {
        choice = 1;
        water = 1;
        salt = 1;
    }
    dish_garnish(int a, int b, int c) {
        choice = a;
        water = b;
        salt = c;
    }
    void quantity();
    void cooking_garnish();
};
class desert_making :public desert_cream {
protected:
    int pieces;
public:
    desert_making() {
        pieces = 1;
    };
    desert_making(int a) {
        pieces = a;
    };
    void cooking_desert();
};
class serve : public desert_making, public dish_garnish {
protected:
    int rate;
public:
    serve() {
        rate = 10;
    };
    void order();
    void rating();
};