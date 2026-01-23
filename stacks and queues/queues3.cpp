#include<bits/stdc++.h>
using namespace std;

#define n 5
int s1[n], s2[n];
int top1=-1, top2=-1;

void push1(int value){
    top1++;
    s1[top1]=value;
}

void push2(int value){
    top2++;
    s2[top2]=value;
}

int pop1(){
    return s1[top1--];
}

int pop2(){
    return s2[top2--];
}

void enqueue(int value){
    push1(value);
}

void dequeue(){
    while (top1 != -1) {
        push2(pop1());
    }
    pop2();
    while (top2 != -1) {
        push1(pop2());
    }
}

void display(){
    for (int i=0; i<=top1; i++){
        cout<<s1[i]<<" ";
    }
}

int main(){
    enqueue(2);
    enqueue(4);
    enqueue(8);
    enqueue(9);
    display();
    cout<<"\n";
    dequeue();
    display();
}
