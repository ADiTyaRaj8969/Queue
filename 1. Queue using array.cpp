/*
 Task: Implement a queue using array
*/

#include <bits/stdc++.h>
using namespace std;

class ArrayQueue
{
    vector<int> a;
    int head = 0;

   public:
    ArrayQueue(int capacity = 1000) { a.reserve(capacity); }

    void push(int x) { a.push_back(x); }

    void pop()
    {
        if (head < static_cast<int>(a.size()))
            ++head;
    }

    int front() { return a[head]; }

    bool empty() { return head >= static_cast<int>(a.size()); }
};

int main()
{
    ArrayQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << '\n';
    return 0;
}

// Time Complexity: O(1) amortized per operation
// Space Complexity: O(n)
