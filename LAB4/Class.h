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
    cooking(string mt, string grnsh, string dsrt) {
        meat = mt;
        garnish = grnsh;
        desert = dsrt;
    }
    ~cooking() {};
    void set_meat();
    void set_garnish();
    void set_desert();
};

class dish_meat :public virtual cooking {
protected:
    string sauce;
public:
    dish_meat() {};
    dish_meat(string mt, string grnsh, string dsrt, string sc) : cooking(mt, grnsh, dsrt) {
        sauce = sc;
    }
    ~dish_meat() {};
    void set_sauce();
    void cooking_meat();
};
class desert_cream :public virtual cooking {
protected:
    string cream;
public:
    desert_cream() {};
    desert_cream(string mt, string grnsh, string dsrt, string crm) : cooking(mt, grnsh, dsrt) {
        cream = crm;
    };
    ~desert_cream() {};
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
    dish_garnish(string mt, string grnsh, string dsrt, string sc, int chc, int wtr, int slt): dish_meat(mt,  grnsh, dsrt,  sc) {
        choice = chc;
        water = wtr;
        salt = slt;
    }
    ~dish_garnish() {};
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
    desert_making(string mt, string grnsh, string dsrt, string crm, int pcs): desert_cream(mt, grnsh, dsrt, crm) {
        pieces = pcs;
    };
    ~desert_making() {};
    void cooking_desert();
};
class serve : public desert_making, public dish_garnish {
protected:
    int rate;
public:
    serve() {
        rate = 10;
    };
    serve(string mt, string grnsh, string dsrt, string sc, int chc, int wtr, int slt, string crm, int pcs, int rt):dish_garnish( mt,  grnsh,  dsrt,  sc,  chc,  wtr,  slt), desert_making(mt, grnsh, dsrt, crm, pcs) {
        rate = rt;
    };
    ~serve() {};
    void order();
    void rating();
};