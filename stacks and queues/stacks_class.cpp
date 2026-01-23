#include <iostream>
using namespace std;

class Stack {
    public:
    int* arr;
    int size;
    int top;
    
    Stack(int size) {
        arr = new int[size];
        this -> size = size;
        this -> top = -1;
    }

    void push(int data){
        if (top == size-1){
            cout << "stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop(){
        if (top == -1){
            cout << "stack underflow" << endl;
            return; 
        }
        top--;
    }

    bool isEmpty(){
        if (top == -1){
            return true;
        }
        return false;
    }

    int getTop(){
        if (top == -1){
            cout << "stack is empty " << endl;
            return 0;
        }
        return arr[top];
    }

    int getSize(){
        return top+1;
    }
};



int main(){
    Stack st(3);
    // st.pop();
    st.push(5);
    st.push(3);
    st.push(2);
    st.push(8);
}
