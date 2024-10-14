#include <iostream>
using namespace std;

// Node structure for the singly linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to create a new node
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Double-Ended Queue class using singly linked list
class Deque {
    Node* front;  // Points to the front node
    Node* rear;   // Points to the rear node

public:
    // Constructor to initialize the Deque
    Deque() {
        front = rear = nullptr;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Insert element at the front
    void insertFront(int value) {
        Node* temp = new Node(value);

        if (isEmpty()) {
            front = rear = temp;
        } else {
            temp->next = front;
            front = temp;
        }

        cout << "Inserted " << value << " at front\n";
    }

    // Insert element at the rear
    void insertRear(int value) {
        Node* temp = new Node(value);

        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }

        cout << "Inserted " << value << " at rear\n";
    }

    // Delete element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = front;
        cout << "Deleted " << front->data << " from front\n";

        front = front->next;  // Move front to the next node

        // If deque becomes empty after deletion
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;  // Free the memory
    }

    // Delete element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        if (front == rear) {
            // If there is only one node
            cout << "Deleted " << rear->data << " from rear\n";
            delete rear;
            front = rear = nullptr;  // Deque becomes empty
        } else {
            // Traverse to the second last node
            Node* temp = front;
            while (temp->next != rear) {
                temp = temp->next;
            }

            cout << "Deleted " << rear->data << " from rear\n";
            delete rear;
            rear = temp;
            rear->next = nullptr;
        }
    }

    // Get the front element
    void getFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }

    // Get the rear element
    void getRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
        } else {
            cout << "Rear element: " << rear->data << endl;
        }
    }
};

// Main function to demonstrate Deque functionality
int main() {
    Deque dq;

    dq.insertFront(10);  // Insert 10 at front
    dq.insertRear(20);   // Insert 20 at rear
    dq.insertFront(5);   // Insert 5 at front
    dq.insertRear(30);   // Insert 30 at rear 5 10 20 30

    dq.getFront();  // Should print 5
    dq.getRear();   // Should print 30

    dq.deleteFront();  // Removes 5
    dq.deleteRear();   // Removes 30

    dq.getFront();  // Should print 10
    dq.getRear();   // Should print 20

    dq.deleteFront();  // Removes 10
    dq.deleteRear();   // Removes 20

    dq.getFront();  // Deque is empty
    dq.getRear();   // Deque is empty

    return 0;
}