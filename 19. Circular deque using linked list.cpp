/*
 Task: Implement circular deque using doubly linked list
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

class CircularDeque
{
    Node* head;
    Node* tail;
    int cap;
    int sz;

   public:
    CircularDeque(int k)
    {
        head = tail = nullptr;
        cap = k;
        sz = 0;
    }

    bool push_front(int x)
    {
        if (sz == cap)
            return false;
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
        sz++;
        return true;
    }

    bool push_back(int x)
    {
        if (sz == cap)
            return false;
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
        sz++;
        return true;
    }

    bool pop_front()
    {
        if (sz == 0)
            return false;
        Node* t = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete t;
        sz--;
        return true;
    }

    bool pop_back()
    {
        if (sz == 0)
            return false;
        Node* t = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete t;
        sz--;
        return true;
    }

    int front()
    {
        if (sz == 0)
            throw runtime_error("empty");
        return head->val;
    }

    int back()
    {
        if (sz == 0)
            throw runtime_error("empty");
        return tail->val;
    }

    int size() { return sz; }
};

int main()
{
    CircularDeque dq(3);
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(0);
    cout << dq.front() << " " << dq.back() << "\n";
    dq.pop_back();
    cout << dq.back() << "\n";
    return 0;
}

// Time Complexity: O(1) per operation
// Space Complexity: O(k)
