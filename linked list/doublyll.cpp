#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
    Node(int value){
        data=value;
        next=nullptr;
        prev=nullptr;
    }
};

void insert_at_end(Node*& head, Node*& temp, int value){
    Node* newNode= new Node(value);
    if (head==nullptr){
        head=temp=newNode;
    }
    else{
        newNode->prev=temp;
        temp->next=newNode;
        temp=newNode;
    }
}

void insert_at_i(Node*& head, Node*& prevnode, Node*& nextnode, int value, int position){
    Node* newNode=new Node(value);
    prevnode=nextnode=head;
    int i=1;
    while (i<position){
        prevnode=nextnode;
        nextnode=nextnode->next;
        i++;
    }
    newNode->next=nextnode;
    newNode->prev=prevnode;
    prevnode->next=newNode;
    nextnode->prev=newNode;
    //prevnode=nextnode;
}

void delete_at_end(Node*& head) {
    if (head == nullptr) return;
    Node* prevNode;
    Node* temp = head;
    while (temp->next != nullptr) {
        prevNode = temp;
        temp = temp->next;
    }
    prevNode->next = nullptr;
    delete temp;
}

void delete_from_i(Node*& head, int position){
    Node* curr=head;
    Node* prevnode;
    Node* nextnode;
    int i=1;
    while (i<position){
        prevnode=curr;
        curr=curr->next;
        nextnode=curr->next;
        i++;
    }
    prevnode->next=nextnode;
    nextnode->prev=prevnode;
    delete(curr);
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
    insert_at_i(head,prevnode,nextnode,21,4);
    delete_at_end(head);
    delete_from_i(head,3);
    Node* traverse=head;
    while (traverse!=nullptr){
        cout<<traverse->data<<"-->>";
        traverse=traverse->next;
    }
    return 0;
}