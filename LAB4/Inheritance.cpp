#include <iostream>
#include <string.h>
#include "Class.h"
using namespace std;


int main()
{
    serve a("beef","rice", "napoleon", "ketchup", 1, 100, 20, "cream", 3, 10);
    a.set_meat();
    a.set_garnish();
    a.set_desert();
    a.cooking_meat();
    a.set_sauce();
    a.quantity();
    a.cooking_garnish();
    a.cooking_cream();
    a.cooking_desert();
    a.order();
    a.rating();
}
