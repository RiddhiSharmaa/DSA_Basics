#include <bits/stdc++.h>
using namespace std;

class Number{
    private:
    int value;
    public:
    Number(int val = 0){
        value = val;
    }
    void operator+ (Number &other){
        cout << "Hi! there." << endl;
    }

    void operator() (){
        cout << "I'm a bracket." << endl;
    }
};

int main(){
    Number n1(15);
    Number n2(5);
    n1+n2;
    n1();
    return 0;
}