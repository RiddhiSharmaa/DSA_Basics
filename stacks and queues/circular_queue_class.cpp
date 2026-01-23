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
        if ((rear + 1) % size == front){
            cout << "QUEUE overflow!" << endl;
        }
        else if (front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        else{
            rear = (rear+1)%size;
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
            front = (front+1)%size;
        }
    }

    int get_size(){
        if (front == -1 && rear == -1){
            return 0;
        }
        else if (rear >= front){
            return (rear - front + 1);
        }
        else{
            return (size + rear - front + 1);
        }
    }

    void print() {
        int i = front;
        while (i != rear){
            cout << arr[i] << " ";
            i = (i+1)%size;
        }
        cout << arr[i];
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
    q.push(79);
    q.pop();
    q.push(46);
    q.print();
    return 0;
}