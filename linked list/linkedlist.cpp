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

void insert_at_start(Node*& head,int value){
    Node* newNode=new Node(value);
    newNode->next=head;
    head=newNode;
}

void insert_at_end(Node*& head, int value){
    Node* newNode=new Node(value);
    Node* temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newNode;
}
int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    int choice=1;
    int value;
    int start;
    while (choice==1){
        cout<<"Do you want to add more elements?(1 for Yes, 0 for No)";
        cin>>choice;
        if (choice==0){
            break;
        }
        cout<<"enter value to be added: ";
        cin>>value;
        cout<<"start? ";
        cin>>start;
        if (start==1){
            insert_at_start(head,value);
            continue;
        }
        Node* newNode=new Node(value);
        if (head== nullptr){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* temp=head;
    cout<<"Linked List: ";
    while (temp!=nullptr){
        cout<< temp->data<<"-->";
        temp=temp->next;
    }
    return 0;
}

