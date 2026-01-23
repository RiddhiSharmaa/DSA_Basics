#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int n){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while (low <= high){
        int mid = low + (high-low)/2;
        if (mid % 2 == 0){
            if (mid+1<n && arr[mid] == arr[mid+1]){
                low = mid+2;
            }
            else{
                ans = arr[mid];
                high = mid-1;
            }
        } else{
            if (mid-1>=0 && arr[mid] == arr[mid-1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return ans;
}

int main(){
    int arr[15] = {10,10,2,2,5,5,6,6,3,20,20,11,11,10,10};
    cout<< search(arr, 15);
}