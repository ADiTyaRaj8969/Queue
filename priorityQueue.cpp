#include <iostream>
using namespace std;

// Node structure for Priority Queue
class Node {
public:
    int data;
    int priority;
    Node* next;

    // Constructor to create a new node
    Node(int value, int prio) {
        data = value;
        priority = prio;
        next = nullptr;
    }
};

// Priority Queue class
class PriorityQueue {
    Node* front;

public:
    // Constructor
    PriorityQueue() {
        front = nullptr;
    }

    // Enqueue operation to insert an element into the priority queue
    void enqueue(int value, int priority) {
        Node* temp = new Node(value, priority);

        // If the queue is empty or the new node has higher priority than the front
        if (front == nullptr || priority < front->priority) {
            temp->next = front;
            front = temp;
        } else {
            // Traverse the list and find the correct position for the new node
            Node* start = front;
            while (start->next != nullptr && start->next->priority <= priority) {
                start = start->next;
            }
            temp->next = start->next;
            start->next = temp;
        }
        cout << "Enqueued: " << value << " with priority " << priority << endl;
    }

    // Dequeue operation to remove the highest priority element from the queue
    void dequeue() {
        if (front == nullptr) {
            cout << "Priority Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << "Dequeued: " << front->data << " with priority " << front->priority << endl;
        front = front->next;
        delete temp;
    }

    // Peek operation to view the front element
    void peek() {
        if (front == nullptr) {
            cout << "Priority Queue is empty\n";
        } else {
            cout << "Front element: " << front->data << " with priority " << front->priority << endl;
        }
    }

    // Check if the priority queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

// Main function to demonstrate Priority Queue operations
int main() {
    PriorityQueue pq;

    pq.enqueue(10, 2);   // Enqueue 10 with priority 2
    pq.enqueue(20, 1);   // Enqueue 20 with priority 1
    pq.enqueue(30, 3);   // Enqueue 30 with priority 3
    pq.enqueue(40, 0);   // Enqueue 40 with priority 0
    pq.enqueue(50, 1);   // Enqueue 50 with priority 1

    pq.peek();           // View the front element

    pq.dequeue();        // Dequeue the highest priority element
    pq.dequeue();        // Dequeue the next highest priority element

    pq.peek();           // View the front element

    pq.enqueue(60, 0);   // Enqueue 60 with priority 0

    return 0;
}