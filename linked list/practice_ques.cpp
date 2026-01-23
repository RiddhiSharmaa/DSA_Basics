#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to traverse the list in reverse order using recursion
void reverseTraversal(Node* head) {
    if (head == nullptr) {
        return;
    }

    // Recursively call for the next node
    reverseTraversal(head->next);

    // Print the current node's data after the recursive call (reverse order)
    cout << head->data << " ";
}

// Helper function to insert a new node at the end
void insert(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() {
    Node* head = nullptr;

    // Insert nodes into the list
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Reverse order traversal: ";
    reverseTraversal(head);

    return 0;
}
