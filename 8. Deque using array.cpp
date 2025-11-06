/*
 Task: Implement a deque using array
*/

#include <bits/stdc++.h>
using namespace std;

class ArrayDeque
{
    vector<int> a;
    int head = 0;
    int tail = 0;
    int sz = 0;

   public:
    ArrayDeque(int cap = 10) : a(cap) {}

    bool push_back(int x)
    {
        if (sz == static_cast<int>(a.size()))
            return false;
        a[tail] = x;
        tail = (tail + 1) % a.size();
        ++sz;
        return true;
    }

    bool push_front(int x)
    {
        if (sz == static_cast<int>(a.size()))
            return false;
        head = (head - 1 + a.size()) % a.size();
        a[head] = x;
        ++sz;
        return true;
    }

    bool pop_back()
    {
        if (sz == 0)
            return false;
        tail = (tail - 1 + a.size()) % a.size();
        --sz;
        return true;
    }

    bool pop_front()
    {
        if (sz == 0)
            return false;
        head = (head + 1) % a.size();
        --sz;
        return true;
    }

    int front() { return a[head]; }

    int back() { return a[(tail - 1 + a.size()) % a.size()]; }

    bool empty() { return sz == 0; }
};

int main()
{
    ArrayDeque d(3);
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

// Time Complexity: O(1)
// Space Complexity: O(n)
