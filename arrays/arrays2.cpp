#include<bits/stdc++.h>
using namespace std;

//brute
int missing(int arr[], int n){
    for (int i=1; i<n; i++){
        int flag=0;
        for (int j=0; j<n; j++){
            if (arr[j]==i){
                flag=1;
                break;
            }
        }
        if (flag==0){
            return i;
        }
    }
    return -1;
}
//tc=n^2
//sc=1

//better
int missing1(int arr[], int n){
    int hash[n+1]={0};
    for (int i=0; i<n-1; i++){
        hash[arr[i]]=1;
    }
    for (int i=1; i<=n; i++){
        if (hash[i]==0){
            return i;
        }
    }
    return -1;
}

//optimal 1
int missing2(int arr[], int n){
    int sum=0;
    for (int i=0; i<n; i++){
        sum=sum+arr[i];
    }
    int actual_sum=((n+1)*(n+2))/2;
    int missing_number=actual_sum-sum;
    return missing_number;
}

//optimal 2
int missing3(int arr[], int n){
    int XOR1=0;
    int XOR2=0;
    for (int i=0; i<n-1; i++){
        XOR2=XOR2^arr[i];
        XOR1=XOR1^(i+1);
    }
    XOR1=XOR1^n;
    int missing_number=XOR1^XOR2;
    return missing_number;
}

int consecutive(int arr[], int n){
    int maximum=0;
    int cnt=0;
    for (int i=0; i<n; i++){
        if (arr[i]==1){
            cnt=cnt+1;
            maximum=max(maximum,cnt);
        }
        else{
            cnt=0;
        }
    }
    return maximum;
}

//brute: number that appears once, all other numbers appear twice
int occurence(int arr[], int n){
    for (int i=1; i<n; i++){
        int cnt=0;
        for (int j=0; j<n; j++){
            if (arr[j]==i){
                cnt++;
            }
        }
        if (cnt==1){
            return i;
        }
    }
    return -1;
}

//better: hashing
int occurence1(int arr[], int n){
    int maximum=arr[0];
    for(int i=0; i<n; i++){
        if (arr[i]>maximum){
            maximum=arr[i];
        }
    }
    int hash[maximum+1]={0};
    for (int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    for (int i=0; i<maximum+1; i++){
        if (hash[i]==1){
            return i;
        }
    }
    return -1;
}

//better: mapping
int occurence2(int arr[], int n){
    map<int,int>mpp;
    for (int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    for (auto it:mpp){
        if (it.second==1){
            return it.first;
        }
    }
    return -1;
}

//optimal:XOR
int occurence3(int arr[], int n){
    int XOR=0;
    for (int i=0; i<n; i++){
        XOR=XOR^arr[i];
    }
    return XOR;
}

int main(){
    int n=7;
    int arr[n]={1,1,2,3,3,4,4};
    cout<<occurence2(arr,n);
    return 0;
}