#include <bits/stdc++.h>
using namespace std;

int main(){
    int num = 5;

    // int *ptr = &num;

    // cout << "value: " << *ptr << endl;
    // cout << "address: " << ptr << endl;

    // cout << "size of ptr: " << sizeof(ptr) << endl;
    // cout << "size of num: " << sizeof(num) << endl;

    int arr[10]={0,3};

    int *ptr = arr;

    
    cout << arr << endl;
    cout << &arr << endl;
    cout << &arr[0] << endl;
    cout << arr[0] << endl;
    cout << "1st" << *arr << endl;
    cout << *(arr) + 1 << endl;
    cout << *arr + 1 << endl;
    cout << *(arr + 1) << endl;
    cout << endl;

    cout << sizeof(arr) << endl;
    cout << sizeof(*arr) << endl;
    cout << sizeof(&arr[0]) << endl;
    cout << sizeof(arr[0]) << endl;
    cout << endl;

    cout << sizeof(ptr) << endl;
    cout << sizeof(*ptr) << endl;
    cout << sizeof(&ptr) << endl;
    cout << endl;

    cout << ptr << endl;
    cout << *ptr <<endl;

    cout << "************" << endl;

    char temp = 'y';
    char *p = &temp;
    cout << p;

}