#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    //Default Constructor
    Node(){
        data = 0;
        next = nullptr;
        cout << "Node created with default value 0" << endl;
    }

    //Parameterised Constructor
    Node(int val){
        data = val;
        next = nullptr;
        cout << "Node created with default value " << val << endl;
    }

    //Destructor
    ~Node(){
        cout << "Node with value " << data << " deleted" <<endl;
    }
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert node with default value
    Node* node1 = new Node(); // data = 0
    head = tail = node1;

    // Insert more nodes
    Node* node2 = new Node(10);
    tail->next = node2;
    tail = node2;

    Node* node3 = new Node(20);
    tail->next = node3;
    tail = node3;

    Node* node4 = new Node(); // another node with default 0
    tail->next = node4;
    tail = node4;

    // Display linked list
    Node* temp = head;
    cout << "\nLinked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n\n";

    // Free memory
    temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp; // destructor will print deletion message
        temp = nextNode;
    }

    return 0;
}