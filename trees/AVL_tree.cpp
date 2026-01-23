#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int height(Node* node){
    if (node==nullptr){
        return 0;
    }
    else{
        return node->height;
    }
}


Node* right_rotate(Node* y){
    Node* x=y->left;
    Node* t2= x->right;
    x->right=y;
    y->left=t2;
    y->height= 1+max(height(y->left), height(y->right));
    x->height= 1+max(height(x->left), height(x->right));
    return x;
}

Node* left_rotate(Node* x){
    Node* y= x->right;
    Node* t2=y->left;
    y->left=x;
    x->right=t2;
    y->height= max(height(y->left), height(y->right))+1;
    x->height= max(height(x->left), height(x->right))+1;
    return y;
}

int get_balance(Node* node){
    if (node==nullptr){
        return 0;
    }
    else{
        return height(node->left)-height(node->right);
    }
}

Node* insert(Node* root, int data){
    if (root==nullptr){
        return new Node(data);
    }
    if (data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right, data);
    }
    else{
        return root;
    }

    root->height=1+max(height(root->left), height(root->right));
    int balance=get_balance(root);
    
    if (balance > 1 && get_balance(root->left) >= 0){
        return right_rotate(root);} // Left Left

    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root); // Left Right
    }

    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root); // Right Right

    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root); // Right Left
    }

    return root;
}

Node* minValueNode(Node* node){
    Node* current=node;
    while(current->left != nullptr){
        current=current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int data){
    if (root==nullptr){
        return root;
    }
    if (data<root->data){
        root->left=deleteNode(root->left, data);
    }
    else if(data>root->data){
        root->right=deleteNode(root->right, data);
    }
    else{
        if (root->left==nullptr || root->right==nullptr){
            Node* temp=root->left? root->left : root->right;
            if (temp==nullptr){
                temp=root;
                root=nullptr;
            }
            else{
                *root=*temp;
            }
            delete temp;
        }
        else{
            Node* temp=minValueNode(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right, temp->data);
        }
    }

    if (root==nullptr){
        return root;
    }

    root->height=1+max(height(root->left),height(root->right));
    int balance = get_balance(root);

    // Left Left Case
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    // Left Right Case
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // Right Right Case
    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    // Right Left Case
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

bool search(Node* root, int data) {
    if (root == nullptr)
        return false;

    if (root->data == data)
        return true;

    if (data < root->data)
        return search(root->left, data);

    return search(root->right, data);
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Insert elements
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 50);
    root = insert(root, 5);

    cout << "In-order traversal: ";
    inOrder(root);
    cout<<endl;
    
    cout << "Searching for 25: " << (search(root, 25) ? "Found" : "Not Found") << endl;

    cout << "Deleting 20...";
    root = deleteNode(root, 20);

    cout<<endl;
    cout << "In-order traversal after deletion: ";
    inOrder(root);

    return 0;
}