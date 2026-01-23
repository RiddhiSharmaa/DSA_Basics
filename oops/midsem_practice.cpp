#include <bits/stdc++.h>
using namespace std;

class Bank{
private:
    int balance;
public:
    Bank(int balance){
        this -> balance = balance;
    }

    void deposit(int amt){
        balance += amt;
    }

    void withdraw(int amt){
        balance -= amt;
    }

    int getBalance(){
        return balance;
    }
};

int main(){
    Bank b(10000);
    cout << b.getBalance() << endl;

    b.deposit(500);
    cout << b.getBalance() << endl;

    b.withdraw(500);
    cout << b.getBalance() << endl;

    return 0;
}