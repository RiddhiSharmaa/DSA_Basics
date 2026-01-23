#include <iostream>
using namespace std;

class Queue{
public:
    int* arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        arr = new int[size];
        this -> size = size;
        front = -1;
        rear = -1;
    }

    void push (int val){
        if (rear == size - 1){
            cout << "QUEUE overflow!" << endl;
        }
        else if (front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        if (front == -1 && rear == -1){
            cout << "QUEUE underflow" << endl;
        }
        else if (front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    int get_size(){
        if (front == -1 && rear == -1){
            return 0;
        }
        else{
            return (rear - front + 1);
        }
    }

    void print() {
        for (int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue q(5);
    q.push(10);
    q.push(45);
    q.push(78);
    q.push(56);
    q.print();
    q.push(34);
    q.print();
    q.push(54);
    return 0;
}