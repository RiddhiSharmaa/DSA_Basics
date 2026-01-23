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

void inorder(Node* root) {
    if (root == nullptr) return;         // Base case: Stop at null
    inorder(root->left);                 // Traverse the left subtree
    cout << root->data << " ";           // Print the current node's data
    inorder(root->right);                // Traverse the right subtree
}

void preorder(Node* root){
    if (root==nullptr) return;
    cout<< root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if (root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<< root->data<<" ";
}

void level_order_traversal(Node* root){
    if (root==nullptr){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while (!q.empty()){
        Node* current= q.front();
        q.pop();
        cout<<current->data<<" ";
        if (current->left!=nullptr){
            q.push(current->left);
        }
        if (current->right!=nullptr){
            q.push(current->right);
        }
    }
}

vector<vector<int>>LevelOrderTraversal(Node* root){
    vector<vector<int>>result;
    if (root==nullptr){
        return result;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>level;
        for (int i=0; i<size; ++i){
            Node* Node = q.front();
            q.pop();
            level.push_back(Node->data);

            if (Node->left) q.push(Node->left);
            if (Node->right) q.push(Node->right);

        }
        result.push_back(level);
    }
}

void printLevelOrder(const vector<vector<int>>& levels) {
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void preorder_iterative(Node* root){
    if (root==nullptr){
        return;
    }
    stack<Node*>st;
    st.push(root);
    
    while(!st.empty()){
        Node* current=st.top();
        st.pop();
        cout<< current->data<<" ";
        if (current->right!=nullptr){
            st.push(current->right);
        }
        if (current->left!=nullptr){
            st.push(current->left);
        }
    }
}

vector<int>inorder_iterative(Node* root){
    stack<Node*>st;
    vector<int>inorder;
    Node* current=root;
    while(true){
        if (current!=nullptr){
            st.push(current);
            current=current->left;
        }
        else{
            if (st.empty()) break;
            current=st.top();
            st.pop();
            inorder.push_back(current->data);
            current=current->right;
        }
    }
    return inorder;
}

int number_of_leaf_nodes(Node* root){
    if (root==nullptr){
        return 0;
    }
    if (root->left==nullptr && root->right==nullptr){
        return 1;
    }
    return number_of_leaf_nodes(root->left)+number_of_leaf_nodes(root->right);
}

int total_nodes(Node* root){
    
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    cout << "Level Order Traversal: ";
    level_order_traversal(root);
    cout << endl;

    cout << "Number of Leaf Nodes: ";
    cout<<number_of_leaf_nodes(root);
    cout << endl;

    cout << "Level Order Traversal(OPTIMAL): ";
    vector<vector<int>> levels = LevelOrderTraversal(root);
    printLevelOrder(levels);
    
    cout << "Preorder Traversal(iterative): ";
    preorder_iterative(root);
    cout << endl;

    cout << "Inorder Traversal(iterative): ";
    vector<int> result = inorder_iterative(root);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}
