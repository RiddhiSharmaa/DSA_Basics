#include<bits/stdc++.h>
using namespace std;

void insert(int num, int arr[], int &cnt, int n){
    if (cnt==n){
        cout<<"overflow!";
        return;
    }
    else{
        arr[cnt]=num;
        cnt++;
    }

}

void insert_at_i(int num, int arr[], int &cnt, int n, int position){
    for (int i=cnt-1; i>=position-1; i--){
        arr[i+1]=arr[i];
    }
    cnt++;
    arr[position-1]=num;
}

void insert_at_beginning(int num, int arr[], int &cnt, int n){
    for (int i=cnt-1; i>=0; i--){
        arr[i+1]=arr[i];
    }
    cnt++;
    arr[0]=num;
}

void insert_at_i_unsorted_array(int num, int arr[], int &cnt, int position){
    arr[cnt]=arr[position-1];
    arr[position-1]=num;
    cnt++; // best time complexity
}

void delete_at_i(int arr[], int position, int &cnt){
    for (int i=position; i<=cnt; i++){
        arr[i-1]=arr[i];}
    cnt--;
}

int main(){
    int n=6;
    int arr[n]={0};
    int cnt=0;
    int position;
    for (int i=0; i<3; i++){
        arr[i]=i+1;
        cnt++;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insert(8,arr,cnt,n);
    for (int i=0; i<cnt; i++){
        cout<<arr[i]<<" ";
    }
    insert_at_i(5,arr,cnt,n, 2);
    cout<<endl;
    for (int i=0; i<cnt; i++){
        cout<<arr[i]<<" ";
    }
    insert_at_beginning(6,arr,cnt,n);
    cout<<endl;
    for (int i=0; i<cnt; i++){
        cout<<arr[i]<<" ";
    }
    delete_at_i(arr,2,cnt);
    cout<<endl;
    for (int i=0; i<cnt; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}