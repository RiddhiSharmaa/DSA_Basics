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

class Human{

    public:
    int color;
    
    public:
    void speak(){
        cout << "Speaking!" << endl;
    }
};

class Dog: public Animal, public Human{

};

int main(){
    Dog d;
    d.bark();
    d.speak();
    return 0;
}