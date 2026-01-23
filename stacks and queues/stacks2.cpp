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


Node* top=nullptr;


void push(int value){
    Node* newNode= new Node(value);
    newNode->next=top;
    top=newNode;
}

void pop(){
    Node* temp=top;
    top=top->next;
    delete (temp);
}

void display_top(){
    cout<<top->data;
}

void display(){
    Node* temp=top;
    while (temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;  
    }
}


int main(){
    push(2);
    push(4);
    push(6);
    push(8);
    push(10);
    display_top();
    pop();
    cout<<"\n";
    display();
    cout<<"\n";
    display_top();
}

