#include<bits/stdc++.h>
using namespace std;

#define n 5
int q[n];
int front=-1, rear=-1;

void enqueue(int value){
    if (front==-1 && rear==-1){
        front=rear=0;
        q[rear]=value;
    }
    else if ((rear+1)%n==front){
        cout<<"queue is full.";
    }
    else{
        rear=(rear+1)%n;
        q[rear]=value;
    }
}

void dequeue(){
    if (front==-1 && rear==-1){
        cout<<"queue is empty.";
    }
    else if (front==rear){
        front=rear=-1;
    }
    else{
        front=(front+1)%n;
    }
}

void display(){
    int i=front;
    while (i!=rear){
        cout<<q[i]<<" ";
        i=(i+1)%n;
    }
    cout<<q[i];
}

int main(){
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(6);
    enqueue(1);
    display();
    cout<<"\n";
    dequeue();
    display();
    enqueue(5);
    cout<<"\n";
    display();
    cout<<"\n";
    dequeue();
    display();
}