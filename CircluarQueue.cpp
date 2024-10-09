#include<bits/stdc++.h>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int *arr;

public:
    CircularQueue(int s) {
        arr = new int[s];
        front = -1;
        rear = -1;
        size = s;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return ((rear + 1) % size == front);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
        cout << "Enqueued element: " << val << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued element: " << arr[front] << endl;
        if (front == rear) { 
            front = rear = -1; 
        } else {
            front = (front + 1) % size;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "The queue is empty" << endl;
            return;
        }
        cout << "The front element is: " << arr[front] << endl;
    }
};

int main() {
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.peek();
    cq.dequeue();
    cq.peek();
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60); 
    return 0;
}