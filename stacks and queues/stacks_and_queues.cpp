#include<bits/stdc++.h>
using namespace std;
#define n 5

struct Stack{
    int arr[n];
    int top=-1;
}s;

void push(int value){
    if (s.top==n-1){
        cout<<"overflow";
    }
    else{
        s.top++;
        s.arr[s.top]=value;
    }
}

void pop(){
    if (s.top==-1){
        cout<<"underflow";
    }
    else{
        s.top--;
    }
}

void display_top(){
    if (s.arr[s.top]==-1){
        cout<<"stack is empty.";
    }
    else{
        cout<<s.arr[s.top];
    }
}

void display(){
    for (int k=s.top; k>=0; k--){
        cout<<s.arr[k]<<" ";
    }
}

int main(){
    push(2);
    push(4);
    push(9);
    push(7);
    push(5);
    pop();
    display_top();
    cout<<"\n";
    display();
}