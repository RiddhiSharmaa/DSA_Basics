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

int main(){
    Dog d;
    d.bark();
    return 0;
}