#include <bits/stdc++.h>
using namespace std;

class Animal{

    public:
    int age;
    int weight;

    public:
    void bark(){
        cout << "Barking!" << endl;
    }
};

class Dog: public Animal{

};

class Poodle: public Dog{

};

int main(){
    Poodle P;
    P.bark();
    return 0;
}