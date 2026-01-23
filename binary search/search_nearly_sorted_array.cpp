#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int target){
    int low = 0;
    int high = n-1;
    while (low <= high){
        int mid = low + (high-low)/2;
        if (arr[mid] == target){
            return mid;
        } else if (arr[mid-1] == target && mid-1 >= 0){
            return mid-1;
        } else if (arr[mid+1] == target && mid+1 < n){
            return mid+1;
        } else if (arr[mid] > target){
            high = mid-2;
        }
        else{
            low = mid+2;
        }
    }
    return -1;
}

int main(){
    int arr[7] = {20, 10, 30, 50, 40, 70, 60};
    cout<< search(arr, 7, 30);
}