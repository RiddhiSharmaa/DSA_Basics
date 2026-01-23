#include<bits/stdc++.h>
using namespace std;

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

bool find(Node* root, int value){
    if (root==nullptr) return false;
    if (root->data==value) return true;
    if (root->data<value){
        return find(root->right,value);
    }
    else{
        return find(root->left,value);
    }
}

int minValue(Node* root) {
    if (root==nullptr) return -1;
    while (root->left!=nullptr){
        root=root->left;
    }
    return root->data;
}

int no_just_greater_ciel(Node* root, int value){
    int ciel=-1;
    while (root!=nullptr){
        if (root->data==value){
            ciel=root->data;
            return ciel;
        }
        if (root->data>value){
            ciel=root->data;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ciel;
}

int no_just_smaller_floor(Node* root, int value){
    int floor=-1;
    while (root!=nullptr){
        if (root->data==value){
            floor=root->data;
            return floor;
        }
        if (root->data>value){
            root=root->left;
        }
        else{
            floor=root->data;
            root=root->right;
        }
    }
    return floor;
}

Node* insert(Node*root, int value){
    if (root==nullptr) return new Node(value);
    Node* current=root;
    while (current!=nullptr){
        if (current->data<=value){
            if (current->right==nullptr){
                current->right=new Node(value);
                break;
            }
            else{
                current=current->right;
            }
        }
        else{
            if (current->left==nullptr){
                current->left=new Node(value);
                break;
            }
            else{
                current=current->left;
            }
        }
    }
    return root;
}

int main() {
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(12);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    //     8
    //    / \
    //   5   12
    //  / \   / \
    // 4   7 10  14
    //    /      /
    //   6      13
    cout<<find(root,10)<<endl;
    cout<<minValue(root)<<endl;
    cout<<no_just_greater_ciel(root,9)<<endl;
    cout<<no_just_smaller_floor(root,11)<<endl;
    cout<<insert(root,11);
    return 0;
}