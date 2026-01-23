#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int k){
    int low=0;
    int high=n-1;
    while (low<=high){
        int mid=(low+high)/2;
        if (arr[mid]==k){
            return mid;
        }
        else if (arr[mid]>k){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
    }
    return -1;
}

int binary_search1(int arr[], int n, int k, int low, int high){
    if (low>high){
        return -1;
    }
    int mid=(low+high)/2;
    if (arr[mid]==k){
        return mid;
    }
    if (arr[mid]>k){
        return binary_search1(arr, n, k, low, mid-1);
    }
    return binary_search1(arr, n, k, mid+1, high);
}

int main(){
    int n=8;
    int arr[n]={3,4,6,7,9,12,16,17};
    int k=16;
    cout<<binary_search1(arr, n, k, 0, n-1);
}