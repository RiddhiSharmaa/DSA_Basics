#include <bits/stdc++.h>
using namespace std;

int decimal_to_binary(int n){
    int binary = 0;
    int place = 1;
    while (n>0){
        int bit = (n & 1);
        binary = bit*place + binary;
        place = place*10;
        n= n>>1;
    }
    return binary;
}

int binary_to_decimal(int n){
    int decimal = 0;
    int place = 1;
    while (n>0){
        int bit = n%10;
        decimal = decimal + bit*place;
        place = place*2;
        n = n/10;
    }
    return decimal;
}

int main(){
    int n = 10;
    cout << decimal_to_binary(n) << endl;
    cout << binary_to_decimal(1010) << endl;
    return 0;
}