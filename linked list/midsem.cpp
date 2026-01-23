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

void insert_at_end(Node*& head, int value, Node*& tail){
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

void insert_at_i(Node*& head, int val, int position){
    Node* newNode=new Node(val);
    int i=1;
    Node* pointer=head;
    while(i<position-1){
        pointer=pointer->next;
        i++;
    }
    newNode->next=pointer->next;
    pointer->next=newNode;
}

void insert_at_ii(Node*& head, int val, int position){
    Node* newNode=new Node(val);
    int i=1;
    Node* prev;
    Node* temp=head;
    while(i<position){
        prev=temp;
        temp=temp->next;
        i++;
    }
    newNode->next=temp;
    prev->next=newNode;
}

void delete_from_start(Node*& head){
    Node* temp=head;
    head=temp->next;
    delete(temp);
}

void delete_from_end(Node*& head){
    Node* temp=head;
    Node* prevnode;
    while (temp->next!=nullptr){
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=nullptr;
    delete(temp);
}

void delete_from_i(Node*& head, int position){
    Node* temp=head;
    Node* prevnode;
    int i=1;
    while (i<position){
        prevnode=temp;
        temp=temp->next;
        i++;
    }
    prevnode->next=temp->next;
    delete(temp);
}

void reverse_linked_list(Node*& head){
    Node* prevNode=nullptr;
    Node* nextNode=head;
    Node* currentNode=head;
    while (nextNode!=nullptr){
        nextNode=nextNode->next;
        currentNode->next=prevNode;
        prevNode=currentNode;
        currentNode=nextNode;
    }
    head=prevNode;
}

int main(){
    Node* head=nullptr;
    Node* tail=nullptr;
    int val=5;
    int position=3;
    cout<<"Linked List: ";
    insert_at_end(head, 10,tail);
    insert_at_end(head, 20,tail);
    insert_at_end(head, 30,tail);
    insert_at_end(head, 40,tail);
    insert_at_end(head, 50,tail);
    insert_at_start(head, -10);
    insert_at_ii(head, val, position);
    Node* temp=head;
    while (temp!=nullptr){
        cout<< temp->data<<"-->";
        temp=temp->next;
    }
    cout<<"\n";
    delete_from_i(head,3);
    Node* t=head;
    while (t!=nullptr){
        cout<< t->data<<"-->";
        t=t->next;
    }
    reverse_linked_list(head);
    cout<<"\n";
    Node* tm=head;
    while (tm!=nullptr){
        cout<< tm->data<<"-->";
        tm=tm->next;
    }
    return 0;
}

