/*
 Task: Implement a deque using doubly linked list
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* prev;
    Node* next;
    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class DLLDeque
{
    Node* head = nullptr;
    Node* tail = nullptr;

   public:
    void push_front(int x)
    {
        Node* n = new Node(x);
        if (!head)
        {
            head = tail = n;
        }
        else
        {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }

    void push_back(int x)
    {
        Node* n = new Node(x);
        if (!tail)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void pop_front()
    {
        if (head)
        {
            Node* t = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            else
                tail = nullptr;
            delete t;
        }
    }

    void pop_back()
    {
        if (tail)
        {
            Node* t = tail;
            tail = tail->prev;
            if (tail)
                tail->next = nullptr;
            else
                head = nullptr;
            delete t;
        }
    }

    int front() { return head->val; }

    int back() { return tail->val; }

    bool empty() { return head == nullptr; }
};

int main()
{
    DLLDeque d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(0);
    while (!d.empty())
    {
        cout << d.front() << " ";
        d.pop_front();
    }
    cout << "\n";
    return 0;
}

// Time Complexity: O(1) per op
// Space Complexity: O(n)
