/*
 Task: Implement a queue using linked list
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class LinkedQueue
{
    Node* head = nullptr;
    Node* tail = nullptr;

   public:
    void push(int x)
    {
        Node* n = new Node(x);
        if (!tail)
            head = tail = n;
        else
        {
            tail->next = n;
            tail = n;
        }
    }

    void pop()
    {
        if (head)
        {
            Node* t = head;
            head = head->next;
            if (!head)
                tail = nullptr;
            delete t;
        }
    }

    int front() { return head->val; }

    bool empty() { return head == nullptr; }
};

int main()
{
    LinkedQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
    return 0;
}

// Time Complexity: O(1) per operation
// Space Complexity: O(n)
