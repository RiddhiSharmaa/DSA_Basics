#include<bits/stdc++.h>
using namespace std;

int largest_element(int arr[], int n){
    int largest= arr[0];
    for (int i=1; i<n; i++){
        if (arr[i]>largest){
            largest=arr[i];
        }
    }
    return largest;
}

int s_largest(int arr[], int n){
    int largest= arr[0];
    int second_largest=-1; //int_min if there are negative numbers in the array
    for (int i=0; i<n; i++){
        if (arr[i]>largest){
            second_largest=largest;
            largest=arr[i];
        }
        else if (arr[i]<largest && arr[i]>second_largest){
            second_largest=arr[i];
        }
    }
    return second_largest;
}

int second_smallest(int arr[], int n){
    int smallest=arr[0];
    int second_smallest=-1;
    for (int i=0; i<n; i++){
        if (arr[i]<smallest){
            second_smallest=smallest;
            smallest=arr[i];
        }
        else if (arr[i]>smallest && arr[i]<second_smallest){
            second_smallest=arr[i];
        }
    }
    return second_smallest;
}

bool arr_sorted(int arr[], int n){
    int smallest= arr[0];
    bool sorted= true;
    for (int i=0; i<n; i++){
        if (arr[i+1]<arr[i]){
            sorted= false;
            break;
        }
    }
    return sorted;
}

//brute
int remove_duplicates(int arr[], int n){
    set<int>st;
    for (int i=0; i<n; i++){
        st.insert(arr[i]);
    }
    int index=0;
    for (auto it:st){
        arr[index]=it;
        index++;
    }
    return index;
}

//optimal
int rem_dup(int arr[], int n){
    int i=0;
    for (int j=1; j<n; j++){
        if (arr[i]!=arr[j]){
            arr[i+1]=arr[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    int n=6;
    int arr[n]={1,2,2,7,7,7};
    cout<<"no. of elements: "<<rem_dup(arr,n)<<endl;
    int f=remove_duplicates(arr,n);
    for (int i=0; i<f; i++){
        cout<<arr[i]<<" ";
    }
}
