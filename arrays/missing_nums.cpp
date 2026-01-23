#include<bits/stdc++.h>
using namespace std;

void missing_nums(int arr[], int n){
    for (int i = 0; i<n; i++){
        int index = abs(arr[i]);
        if (arr[index-1]>0){
            arr[index-1] *= -1;
        }
    }

    for (int i = 0; i<n; i++){
        if (arr[i] > 0){
            cout << i+1 << " ";
        }
    }
}

void approach2(int arr[], int n){
    int i = 0; 
    while (i<n){
        int index = arr[i]-1;
        if (arr[index] != arr[i]){
            swap(arr[i], arr[index]);
        }
        else{
            i++;
        }
    }
    for (int i = 0; i<n; i++){
        if (arr[i] != i+1){
            cout << i+1 << " ";
        }
    }
}

int main(){
    int n = 5;
    int arr[n] = {1, 3, 4, 3, 5};
    int j = 0;
    approach2(arr, n);
    return 0;
}