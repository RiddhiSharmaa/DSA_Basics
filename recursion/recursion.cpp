#include<bits/stdc++.h>
using namespace std;

void print(int i, int n){
    if (i>n){
        return;
    }
    else{
        cout<<"raj"<<endl;
        print(i+1,n);
    }
}

void print_linear(int i, int n){
    if (i>n){
        return;
    }
    cout<<i<<",";
    print_linear(i+1,n);
}

void reverse(int n){
    if (n==0){
        return;
    }
    cout<<n;
    reverse(n-1);
}

void p1(int i, int n){ 
    if (i==0){
        return;
    }
    p1(i-1,n);
    cout<<i;
}

void p2(int i, int n){
    if (i>n){
        return;
    }
    p2(i+1,n);
    cout<<i;
}

//paramterised
void summation(int i,int sum){
    if (i==0){
        cout<<"sum: "<<sum;
        return;
    }
    summation(i-1,sum+i);
}

//functional
int summ(int n){
    if (n==0){
        return 0;
    return n+summ(n-1);
}
}

int factorial(int n){
    if (n==1){
        return 1;
    }
    return n*factorial(n-1);
}

void rev_array(int arr[], int i, int n){
    if (i>n/2){
        return;
    }
    swap(arr[i], arr[n-i-1]);
    rev_array(arr,i+1,n);
}

// int main(){
//     int n=5;
//     int arr[n]={1,6,4,3,7};
//     rev_array(arr,0,5);
//     for (int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
// }

bool palindrome(string s, int i, int n){
    if (i>=n/2){
        return true;
    }
    if (s[i]!=s[n-i-1]){
        return false;
    }
    return palindrome(s,i+1,n);
}

// int main(){
//     string s="madam";
//     int n=s.size();
//     cout<<palindrome(s, 0, n);
// }

int fibonacci(int n){
    if (n<=1){
        return n;
    }
    int last=fibonacci(n-1);
    int slast=fibonacci(n-2);
    return last+slast;
}

int main(){
    cout<<fibonacci(4);
}

