/*
 Task: Design circular queue with fixed capacity
*/

#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
    vector<int> data;
    int head, tail, cap, sz;

   public:
    CircularQueue(int k) : data(k), head(0), tail(0), cap(k), sz(0) {}

    bool enqueue(int x)
    {
        if (sz == cap)
            return false;
        data[tail] = x;
        tail = (tail + 1) % cap;
        sz++;
        return true;
    }

    bool dequeue()
    {
        if (sz == 0)
            return false;
        head = (head + 1) % cap;
        sz--;
        return true;
    }

    int front()
    {
        if (sz == 0)
            throw runtime_error("empty");
        return data[head];
    }

    int rear()
    {
        if (sz == 0)
            throw runtime_error("empty");
        return data[(tail - 1 + cap) % cap];
    }

    int size() { return sz; }
};

int main()
{
    CircularQueue q(3);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.front() << " " << q.rear() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    return 0;
}

// Time Complexity: O(1) per operation
// Space Complexity: O(k)
