#include<bits/stdc++.h>
using namespace std;

int diameter=0; 

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

bool is_identical(Node* root1, Node* root2){
    if (root1==nullptr && root2==nullptr) return true;
    if (root1==nullptr || root2==nullptr) return false;
    return (root1->data==root2->data) 
        && is_identical(root1->left,root2->left) 
        && is_identical(root1->right,root2->right);
}

int main() {
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);
    
    cout<<"Is it identical?: "<<is_identical(root1,root2)<<endl;
    return 0;
}