#include <bits/stdc++.h>
using namespace std;

class Human{

    //properties
    public:
    int height;
    int weight;
    int age;

    public:
    int getAge(){
        return this->age;
    }

    void setWeight(int w){
        this->weight = w;
    }

};

class Male: private Human{

    public:
    string colour;

    void sleep(){
        cout << "Male sleeping." << endl;
    }

    void setWeight(int w){
        this->weight = w;
    }

    int getWeight(){
        return this->weight;
    }

};

int main(){
    Male m1;
    m1.setWeight(84);
    m1.colour = "yellow";

    cout << "weight: " << m1.getWeight() << endl;
    cout << "colour: " << m1.colour << endl;
    m1.sleep();
}