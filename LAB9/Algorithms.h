#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <stack>
#include "Class.h"
using namespace std;
namespace mySpace {
    class Algorithm {
    public:
        void alg1() {
            int a, count = 0, sum = 0, num=0;
            string line;
            ifstream file("read.txt");
            if (!file)
            {
                std::cerr << "Uh oh, SomeText.txt could not be opened for reading!" << std::endl;
                exit(1);
            }
            /*ofstream ofile("write.txt");*/
            getline(file, line);
            cout <<"String is: "<< line<<endl;
            file.seekg(0);
            while (!file.eof()) {
                file >> line;
                for (int i = 0; i < line.length(); i++) {
                    if (line[i] >= '0' && line[i] <= '9') {
                        count++;
                    }
                }
                /*cout <<"Str: "<< line<<endl;
                cout<<"Length: "<<line.length()<<endl;
                cout <<"Count: "<< count<<endl;*/
                if (count == line.length()) {
                    num = atoi(line.c_str());
                    /*ofile << line;*/
                    sum += num;
                }
                count = 0;
            }
            cout <<"Sum of positive numbers: "<< sum<<endl;
        }
        template<typename Iterator>
        void alg2(Iterator& end, Iterator& start) {
            int choice = 0, count=0;
            cout << "Enter a mileage to find:\n";
            cin >> choice;
            Iterator answer;
            while (end!=start) {
                if (end->second > choice) {
                    answer = end;
                    count++;
                }
                 /*cout << end->first << " " << end->second;*/
                 end++;
            }
            if (count == 0) {
                cout << "The element, which mileage higher than " << choice << " wasn't found ";
            }
            else {
                cout << "The first element, that has mileage higher than " << choice << ": " << answer->second<<endl;
            }
        }
        void alg3(map<string, automobile> &container) {
            string choice;
            cout << "\nEnter a key to delete:\n";
            rewind(stdin);
            cin >> choice;
            container.erase(choice);
        }
    };
}