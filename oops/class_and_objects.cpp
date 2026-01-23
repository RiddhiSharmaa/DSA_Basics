#include <bits/stdc++.h>
using namespace std;

class Hero{

    //properties
    private:
    int health;
    public:
    char *name;
    char level;
    static int timetocomplete;

    //default constructor
    Hero(){
        cout << "Constructor called." << endl;
        name = new char[100];
    }

    //parameterized constructor
    Hero(int health, char level){
        this->health = health; //this->health points to health of wes upar jo khali hai, and health(RHS) is the input number
        this->level = level;   // so basically Wes ki health mei user given health waala number daal rhe hai
        name = new char[100];
    }

    //copy constructor
    Hero(Hero& temp){
        char *ch= new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "Copy Constructor called." << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    ~Hero() {
        delete[] name;
    }

    int gethealth(){
        return health;
    }

    char getlevel(){
        return level;
    }

    void sethealth(int n){
        health = n;
    }

    void setlevel(char ch){
        level = ch;
    }

    void setname(char name[]){
        strcpy(this->name, name);
    }

    static int random(){
        return timetocomplete;
    }
};

int Hero::timetocomplete = 5;

int main(){
    // //static allocation
    // Hero Michael(10,'B');
    // cout << "health of Michael: " << Michael.gethealth() << endl;
    // cout << "level of Michael: " << Michael.level << endl;
    // cout<<"\n";

    // Hero R(Michael);
    // cout << "health of R: " << R.gethealth() << endl;
    // cout << "level of R: " << R.level << endl;
    // cout<<"\n";
    
    //static allocation
    Hero Wes;
    char name[7] = "Wesley";
    Wes.sethealth(99);
    Wes.setlevel('A');
    Wes.setname(name);

    cout << "size: " << sizeof(Wes)<<endl;

    cout << "health of Wes: " << Wes.gethealth() << endl;
    cout << "level of Wes: " << Wes.level << endl;

    Hero Ryan(Wes);

    Wes.name[0]='K';
    cout << "name of Wes: " << Wes.name << endl;
    cout<<"\n";

    
    cout << "health of Ryan: " << Ryan.gethealth() << endl;
    cout << "level of Ryan: " << Ryan.level << endl;
    cout << "name of Ryan: " << Ryan.name << endl;
    cout<<"\n";

    Hero Adam=Wes;
    cout << "health of Adam: " << Adam.gethealth() << endl;
    cout << "level of Adam: " << Adam.level << endl;
    cout << "name of Adam: " << Adam.name << endl;
    cout<<"\n";

    //dynamic allocation
    Hero *Marshall = new Hero;
    Marshall->sethealth(85);
    Marshall->setlevel('A');

    cout << "health of Marshall: " << Marshall->gethealth() << endl;
    cout << "level of Marshall: " << Marshall->level << endl;
    cout<<"\n";

    cout << "time to complete: " << Hero::timetocomplete << endl;

    cout << Hero::random()<<endl;
    
    return 0;
}