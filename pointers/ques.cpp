#include <bits/stdc++.h>
using namespace std;

int main(){
    int f = 12;
    int k = 14;
    int* p = &k;
    *p = f;
    cout << *p;
}