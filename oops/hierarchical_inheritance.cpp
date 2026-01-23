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

class Poodle: public Animal{
    public:
    void roll(){
        cout << "Poodle rolls." << endl;
    }
};

class ShihTzu: public Animal{
    public:
    void sit(){
        cout << "Shih Tzu sits." << endl;
    }
};

int main(){
    Animal A;
    A.bark();
    cout << "\n";

    Poodle P;
    P.bark();
    P.roll();
    cout << "\n";

    ShihTzu S;
    S.bark();
    S.sit();
    cout << "\n";

    return 0;
}