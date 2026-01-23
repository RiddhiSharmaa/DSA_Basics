#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int low, int high, int target){
    if (low>high){
        return -1;
    }
    int mid = low + (high - low)/2;
    if (arr[mid] == target){
        return mid;
    }
    else if (arr[mid] > target){
        return binary_search(arr, low, mid-1, target);
    }
    else{
        return binary_search(arr, mid+1, high, target);
    }
}

int first_occ(int arr[], int n, int target){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while (low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target){
            ans = mid;
            high = mid-1;
        }
        else if (mid > target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    int n = 7;
    int arr[n] ={1, 2, 4, 4, 4, 5, 6};
    cout << first_occ(arr, n, 4);
}