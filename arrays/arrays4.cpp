#include<bits/stdc++.h>
using namespace std;

void shift_by_k(int arr[], int n, int k){
    vector<int>temp;
    for (int i=k; i<n; i++){
        temp.push_back(arr[i]);
    }
    for (int i=n-1; i>=0; i--){
        if (i>=k){
            arr[i] = arr[i-k];}
        else{
            arr[i] = temp[i];
        }
    }
}

int main(){
    int n=6, k=3;
    int arr[n]={1,2,3,4,5,6};
    shift_by_k(arr, n, k);
    for (int i = 0; i<n; i++){
        cout << arr[i] << " "; 
    }
    return 0;
}