#include <iostream>
using namespace std;

class Stack{
public:
    int* arr;
    int size;
    int top1;
    int top2;

    Stack(int size){
        arr = new int[size]();
        this -> size = size;
        this -> top1 = -1;
        this -> top2 = size;
    }

    void push1(int val){
        if (top1 == top2 -1){
            cout << "overflow" << endl;
        }
        else{
            top1++;
            arr[top1] = val;
        }
    }

    void push2(int val){
        if (top2 == top1 + 1){
            cout << "overflow" << endl;
        }
        else{
            top2--;
            arr[top2] = val;
        }
    }

    void pop1(){
        if (top1 == -1){
            cout << "underflow" << endl;
        }
        else{
            arr[top1] = 0;
            top1--;
        }
    }

    void pop2(){
        if (top2 == size){
            cout << "underflow";
        }
        else{
            arr[top2] = 0;
            top2++;
        }
    }

    void print(){
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
    }
};

int main(){
    Stack st(6);
    st.push1(10);
    st.push2(20);
    st.push1(60);
    st.pop1();
    st.push1(50);
    st.push2(80);
    st.push2(56);
    st.push1(12);
    st.push1(2);
    st.print();

    return 0;
}