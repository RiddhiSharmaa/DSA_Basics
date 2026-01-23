#include <bits/stdc++.h>
using namespace std;

void update(int* p){
    *p = *p+1;
    cout << "inside: " << p << endl;
}

int getSum(int arr[], int n){

    cout << "size: " << sizeof(arr) << endl;
    int sum = 0;
    for (int i = 0; i<n; i++){
        sum += arr[i];
    }
    return sum;
}

int main(){
    int num = 5;
    int *p = &num;

    int arr[5]= {1,2,3,4,5};

    cout << getSum(arr, 5);

    //p = p+1;

    // cout << "outside before: " << p << " " << num << endl;
    // update(p);
    // cout << "outside after: " << p << " " << num << endl;
}