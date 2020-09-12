#include <iostream>
#include <string>
using namespace std;

class automobile {
    friend class STO;
    friend void output(automobile);
    private:
    string name;
    int id, mileage;
    public:
    automobile(string fio, int number, int mile) {
        id = number;
        name = fio;
        mileage = mile;
    }
    automobile() {
        id = 0;
        name = " ";
        mileage = 0;
    }
    void setId() {
        cout << "Enter an ID of auto\n";
        cin >> id;
    }
    void setName() {
        cout << "Enter a name of auto\n";
        cin.ignore();
        getline(cin, name);
    }
    void setMileage() {
        cout << "Enter a mileage of auto\n";
        cin >> mileage;
    }
    friend void output(automobile);
    ~automobile() {
        cout << "Destructor has called\n";
    }
};

class STO {
public:
    void resetMileage(automobile& car);
};


int main() {
    int length;
    cin >> length;

    automobile* array=new automobile[length];
    for (int i = 0; i < length; i++) {
        array[i].setId();
        array[i].setName();
        array[i].setMileage();
    }
    for (int i = 0; i < length; i++) {
        output(array[i]);
    }
    /*automobile audi("Ilya", 7788, 255);
    automobile mercedes("Ilya", 7788, 255);
    automobile bmw;
    STO mechanic;
    audi.setId();
    audi.setName();
    audi.setMileage();
    bmw.setId();
    bmw.setName();
    bmw.setMileage();
    mercedes.setId();
    mercedes.setName();
    mercedes.setMileage();
    system("cls");
    output(audi);
    output(bmw);
    output(mercedes);
    mechanic.resetMileage(audi);
    mechanic.resetMileage(bmw);
    mechanic.resetMileage(mercedes);
    output(audi);
    output(bmw);
    output(mercedes);*/
    return 0;
}

void  STO::resetMileage(automobile& car) {
    cout << "Enter a mileage of auto\n";
    cin >> car.mileage;
}

void output(automobile car) {
    cout << "ID:" << car.id << endl;
    cout << "Name:" << car.name << endl;
    cout << "Mileage:" << car.mileage << endl;
}
