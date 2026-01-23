#include <iostream>
using namespace std;

class Queue{
public:
    int* arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        arr = new int[size]();
        this -> size = size;
        front = -1;
        rear = -1;
    }

    void push_back (int val){
        if ((rear+1) % size == front){
            cout << "QUEUE overflow!" << endl;
        }
        else if (front == -1 && rear == -1){
            rear++;
            front++;
            arr[rear] = val;
        }
        else{
            rear = (rear + 1) % size;
            arr[rear] = val;
        }
    }

    void push_front(int val){
        if ((rear+1) % size == front){
            cout << "QUEUE overflow!" << endl;
        }
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[front] = val;
        }
        else{
            front = (front - 1 + size) % size;
            arr[front] = val;
        }
    }


    void pop_back(){
        if (front == -1 && rear == -1){
            cout << "QUEUE underflow" << endl;
        }
        else if (front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else{
            arr[rear] = -1;
            rear = (rear - 1 + size) % size;
        }
    }

    void pop_front(){
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
            front = (front + 1) % size;
        }
    }

    void print() {
        for (int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue q(5);
    q.push_back(11);
    q.push_back(22);
    q.push_back(33);
    q.push_back(44);
    q.push_back(55);
    q.print();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.print();
    return 0;
}