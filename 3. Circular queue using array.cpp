/*
 Task: Implement a circular queue using array
*/

#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
    vector<int> a;
    int head = 0, tail = 0, sz = 0;

   public:
    CircularQueue(int capacity = 10) : a(capacity) {}
    bool push(int x)
    {
        if (sz == a.size())
            return false;
        a[tail] = x;
        tail = (tail + 1) % a.size();
        ++sz;
        return true;
    }
    bool pop()
    {
        if (sz == 0)
            return false;
        head = (head + 1) % a.size();
        --sz;
        return true;
    }
    int front() { return a[head]; }
    bool empty() { return sz == 0; }
    int size() { return sz; }
};

int main()
{
    CircularQueue q(3);
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.push(4) << " (should be false)\n";
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
