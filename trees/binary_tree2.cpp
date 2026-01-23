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

int height_of_tree(Node* root, int& diameter){
    if (root==nullptr) return 0;
    int left_height=height_of_tree(root->left,diameter);
    int right_height=height_of_tree(root->right,diameter);
    diameter=max(diameter,left_height+right_height);
    return 1+max(left_height,right_height);
}

int height_of_tree(Node* root){
    if (root==nullptr) return 0;

    int left_height=height_of_tree(root->left);
    if (left_height==-1) return -1;

    int right_height=height_of_tree(root->right);
    if (right_height==-1) return -1;

    if (abs(left_height-right_height)>1) return -1;
    
    return 1+max(left_height,right_height);
}

bool isBalanced(Node* root){
    if (height_of_tree(root)!=-1) return true;
    return false;
}

int diameter_of_tree(Node* root, int& diameter){
    height_of_tree(root,diameter);
    return diameter;
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"Height: "<<height_of_tree(root,diameter)<<endl;
    cout<< "Is it balanced?(Y=1/N=0): "<< isBalanced(root)<< endl;
    cout<< "Diameter: "<< diameter_of_tree(root,diameter)<<endl;
    return 0;
}