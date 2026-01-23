#include<bits/stdc++.h>
using namespace std;

void move(int arr[], int n){
    int j = 0;
    for (int i = 0; i<n; i++){
        if (arr[i]<0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main(){
    int n = 5;
    int arr[n] = {23, -7, -12, -10, 11};
    int j = 0;
    move(arr, n);
    for (int k = 0; k<n; k++){
        cout << arr[k] << " ";
    }
    return 0;
}