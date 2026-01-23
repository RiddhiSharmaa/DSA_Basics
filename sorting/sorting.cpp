#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for (int i=0; i<=n-2; i++){
        int minimum_index=i;
        for (int j=i; j<=n-1; j++){
            if (arr[minimum_index]>arr[j]){
                minimum_index=j;
            }
        }
        int temp=arr[minimum_index];
        arr[minimum_index]=arr[i];
        arr[i]=temp;
    }
}

void bubble_sort(int arr[], int n){
    for (int i=n-1; i>=0; i--){
        bool did_swap=false;
        for (int j=0; j<=i-1; j++){
            if (arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                did_swap=true;
            }
        }
        if (did_swap==false){
            break;
        }
    }
}

void insertion_sort(int arr[], int n){
    for (int i=0; i<=n-1; i++){
        for (int j=i; j>=1; j--){
            if (arr[j-1]>arr[j]){
                int temp=arr[j-1];
                arr[j-1]=arr[j];
                arr[j]=temp;
            }
            else{
                break;
            }
        }
    }
}

void recursive_bubble_sort(int arr[], int n){
    if (n==1){
        return;
    }
    for (int j=0; j<=n-2; j++){
        if (arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    recursive_bubble_sort(arr, n-1);
}

void recursive_insertion_sort(int arr[], int n, int i){
    if (i==n){
        return;
    }
    for (int j=i; j>=1; j--){
        if (arr[j-1]>arr[j]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
        }
        else{
            break;
        }
    }
    recursive_insertion_sort(arr, n, i+1);
}

int main(){
    int n=7;
    int arr[n]={4,8,9,2,5,6,7};
    insertion_sort(arr,n);
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}







