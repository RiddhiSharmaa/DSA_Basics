#include <iostream>
using namespace std;

#define n 5
int q1[n], q2[n];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

void enqueue1(int value) {
    if (rear1 == n - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front1 == -1) front1 = 0;
    q1[++rear1] = value;
}

void enqueue2(int value) {
    if (rear2 == n - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front2 == -1) front2 = 0;
    q2[++rear2] = value;
}

int dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        cout << "Queue Underflow\n";
        return -1;
    }
    return q1[front1++];
}

int dequeue2() {
    if (front2 == -1 || front2 > rear2) {
        cout << "Queue Underflow\n";
        return -1;
    }
    return q2[front2++];
}

bool isEmpty1() {
    return front1 == -1 || front1 > rear1;
}

bool isEmpty2() {
    return front2 == -1 || front2 > rear2;
}

void resetQueue2() {
    front2 = rear2 = -1;
}

void swapQueues() {
    // Copy q2 to q1
    for (int i = front2, j = 0; i <= rear2; ++i, ++j) {
        q1[j] = q2[i];
    }
    rear1 = rear2 - front2;
    front1 = 0;
    resetQueue2();
}

void push(int value) {
    enqueue2(value);
    while (!isEmpty1()) {
        enqueue2(dequeue1());
    }
    swapQueues();
}

void pop() {
    if (isEmpty1()) {
        cout << "Stack Underflow\n";
    } else {
        dequeue1();
    }
}

int top() {
    if (isEmpty1()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return q1[front1];
}

void display() {
    if (isEmpty1()) {
        cout << "Stack is empty\n";
        return;
    }
    for (int i = front1; i <= rear1; i++) {
        cout << q1[i]<<" ";
    }
    cout << "\n";
}

int main() {
    push(5);
    push(10);
    push(15);
    display();     // Output: 15 10 5
    pop();
    display();     // Output: 10 5
    cout << "Top element: " << top() << "\n"; // Output: 10
    return 0;
}
