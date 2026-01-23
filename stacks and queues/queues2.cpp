#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=nullptr;
    }
};

void enqueue(Node*& front, Node*& rear, int value){
    Node* newNode=new Node(value);
    if (front==nullptr & rear==nullptr){
        front=rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
}

void dequeue(Node*& front, Node*& rear){
    Node* temp=front;
    if (front==nullptr){
        cout<<"queue underflow.";
    }
    else{
        front=front->next;
        delete(temp);
    }
}

void display(Node*& front, Node*& rear){
    Node* temp=front;
    if (front==nullptr & rear==nullptr){
        cout<<"queue is empty.";
    }
    else{
        while (temp!=0){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}

void display_top(Node*& front, Node*& rear){
    if (front==nullptr){
        cout<<"queue is empty.";
    }
    else{
        cout<<front->data;
    }
}

int main(){
    Node* front=nullptr;
    Node* rear=nullptr;
    enqueue(front,rear,2);
    enqueue(front,rear,3);
    enqueue(front,rear,4);
    enqueue(front,rear,5);
    enqueue(front,rear,6);
    display(front,rear);
    cout<<"\n";
    display_top(front,rear);
    cout<<"\n";
    dequeue(front,rear);
    display(front,rear);
    cout<<"\n";
    display_top(front,rear);
    cout<<"\n";
}