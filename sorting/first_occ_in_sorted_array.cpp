#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n,int k){
    int low = 0;
    int high = n-1;
    int idx = -1;
    while (low<=high){
        int mid = (low+high)/2;
        if (arr[mid] == k){
            idx = mid;
            high = mid-1;
        }
        else if (arr[mid]>k){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return idx;
}

int main() {
    int n = 8;
    int arr[n] = {10,20,30,30,30,30,40,50};
    int k = 30;
    int ans = binary_search(arr, n, k);
    cout << "ans: " << ans; 
    return 0;
}
