#include<bits/stdc++.h>
using namespace std;

//brute: longest subarray with sum k
int sum_k1(int arr[], int n, int k){
    int len=0;
    for (int i=0; i<n; i++){
        int sum=0;
        for (int j=i; j<n; j++){
            sum=sum+arr[j];
            if (sum==k){
            len=max(len, j-i+1);
            }
        }        
    }
    return len;
}

//better
int sum_k2(int arr[], int n, int k){

}

int main(){
    int n=8, k=3;
    int arr[n]={1,2,3,1,1,1,2,3};
    cout<<sum_k1(arr,n,k);
    return 0;
}