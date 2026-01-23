#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int value){
        data=value;
        next=nullptr;
    }
};

void insert_at_end(Node*& head, Node*& temp, int value){
    Node* newNode=new Node(value);
    if (head==nullptr){
        head=temp=newNode;
        newNode->next=head;
    }
    else{
        newNode->next=head;
        temp->next=newNode;
        temp=newNode;
    }
}

void insert_at_i(Node*& head, Node*& prevnode, Node*& temp, int value, int position){
    Node* newNode=new Node(value);
    temp=head;
    int i=1;
    while (i<position-1){
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

int main(){
    Node* head=nullptr;
    Node* temp=nullptr;
    Node* prevnode=nullptr;
    Node* nextnode=nullptr;
    insert_at_end(head, temp, 5);
    insert_at_end(head, temp, 15);
    insert_at_end(head,temp, 25);
    insert_at_end(head,temp, 35);
    insert_at_end(head,temp, 45);
    insert_at_i(head,prevnode,temp,21,4);
    Node* traverse=head;
    while (traverse->next!=head){
        cout<<traverse->data<<"-->>";
        traverse=traverse->next;
    }
    cout<<traverse->data;
    return 0;
}