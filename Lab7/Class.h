#pragma once
#include <iostream>
#include <string>
using namespace std;
class Exception {
private:
    string warning;
public:
    Exception(string error){
        warning = error;
    };
    const char* what_error() {
        return warning.c_str();
    }
};
class automobile {
private:
    string key;
    string name;
    int mileage;
public:
    automobile(string fio, int mile) {
        name = fio;
        mileage = mile;
    }
    automobile() {
        name = " ";
        mileage = 0;
    }
    ~automobile() {
    }
    bool operator== (automobile atm) {
        return (this->name == atm.name) && (this->mileage == atm.mileage);
    }
    bool operator< (automobile atm) {
        return this->mileage < atm.mileage;
    }
    automobile& operator[](string key) {
        return *this;
    }
    friend ostream& operator <<(std::ostream& out, automobile atm);
};

ostream& operator <<(std::ostream& out, automobile atm) {
    out << "Name: " << atm.name << "  " << "Mileage: " << atm.mileage << " miles";
    return out;
}

template <typename T>
class Associate {
public:
    static int size;
    class Pointer {
    public:
        Pointer* next;
        Pointer* prev;
        T object;
        string key;
        Pointer(string key, T object) {
            size++;
            this->key = key;
            this->object = object;
        }
        Pointer& operator[](int index) {
            Pointer* temp = head;
            int count = 0;
            while (count != index) {
                count++;
                temp = temp->next;
            }
            return temp;
        }
    };
    class Iterator {
    private:
        Pointer* temp;
    public:
        Iterator() {
            temp = nullptr;
        }
        Iterator(Pointer* ptr) {
            temp = ptr;
        }
        Iterator& operator++() {
            temp = temp->next;
            return *this;
        }
        Iterator& operator--() {
            temp = temp->prev;
            return *this;
        }
        Iterator& operator=(Iterator ptr) {
            temp = ptr;
            return *this;
        }
        T& operator*() {
            return temp->object;
        }
        Iterator& operator+(int value) {
            int i = 0;
            while (i < value) {
                temp = temp->next;
                i++;
            }
            return *this;
        }
    };
private:
    Pointer* head;
    Pointer* tail;
    Iterator* headIterator;
    Iterator* tailIterator;
public:
    Associate() {
        head = nullptr;
        tail = nullptr;
        headIterator = nullptr;
        tailIterator = nullptr;
    }
    int getSize() {
        return size;
    }
    void insert(string _key, T object) {
        Pointer* temp = new Pointer(_key, object);
        temp->key = _key;
        temp->next = nullptr;
        if (head == nullptr) {
            temp->prev = nullptr;
            tail = temp;
            head = temp;
            headIterator=new Iterator(head);
        }
        else {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
            tailIterator=new Iterator(tail);
        }
    }
    void duplicate(string _key, T obj) {
        Pointer* temp = head;
        while (temp != nullptr) {
            if (temp->key == _key) {
                throw Exception("Duplicate");
            }
            temp = temp->next;
        }
    }
    void output() {
        if (size != 0) {
            Pointer* temp = head;
            cout << "\n";
            while (temp != nullptr) {
                cout<< temp->object <<  std::endl;
                temp = temp->next;
            }
            cout << "\n";
        }
        else throw Exception("List is empty");
    }
public:
    Associate& operator[](string &key) {
        return *this;
    }

    
    void find(T obj) {
        Pointer* tmp = head; 
        int fl = 0;
        while (tmp != nullptr) {
            if (tmp->object == obj) {
                cout <<"Found: " <<tmp->object<< "   Key of this object: "<<tmp->key;
                fl = 1;
            }
        tmp = tmp->next;
        }
        if (fl == 0) {
            cout << "This object not found :(";
        }
    }
    T& operator[](int index) {
        Pointer* temp = head;
        int count = 0;
        while (count != index) {
            count++;
            temp = temp->next;
        }
        return temp->object;
    }
    Iterator& begin() {
        return *headIterator;
    }

    Iterator& end() {
        return *tailIterator;
    }
};
template <typename T>
void bubble_sort(Associate<T>& list) {
    for (int i = 0; i < list.getSize() - 1; i++) {
        for (int j = 0; j < list.getSize() - 1 - i; j++) {
            if (list[j + 1] < list[j]) {
                T temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

template <typename T>
int Associate<T>::size = 0;


