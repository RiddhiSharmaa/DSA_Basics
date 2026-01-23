#include<bits/stdc++.h>
using namespace std;

#define n 5
int arr[n];
int front=-1, rear=-1;

void enqueue(int value){
    if (rear==n-1){
        cout<<"queue overflow.";
    }
    else if (rear==-1){
        front++;
        rear++;
        arr[rear]=value;
    }
    else{
        rear++;
        arr[rear]=value;
    }
}

void dequeue(){
    if (front==-1 ){
        cout<<"queue underflow.";
    }
    else{
        front++;
    }
}

void display(){
    for(int i=front; i<=rear; i++){
        cout<<arr[i]<<" ";
    }
}

void display_top(){
    cout<<"top "<<arr[front];
}

int main(){
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    display();
    cout<<"\n";
    dequeue();
    display();
    cout<<"\n";
    display_top();
}