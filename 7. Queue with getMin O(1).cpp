/*
 Task: Implement a queue that supports getMin() in O(1) time
*/

#include <bits/stdc++.h>
using namespace std;

class MinQueue
{
    queue<int> q;
    deque<int> mins;

   public:
    void push(int x)
    {
        q.push(x);
        while (!mins.empty() && mins.back() > x) mins.pop_back();
        mins.push_back(x);
    }
    void pop()
    {
        if (q.empty())
            return;
        if (q.front() == mins.front())
            mins.pop_front();
        q.pop();
    }
    int front() { return q.front(); }
    int getMin() { return mins.front(); }
    bool empty() { return q.empty(); }
};

int main()
{
    MinQueue q;
    q.push(3);
    q.push(1);
    q.push(2);
    cout << q.getMin() << "\n";
    q.pop();
    cout << q.getMin() << "\n";
    return 0;
}

// Time Complexity: O(1) amortized per op
// Space Complexity: O(n)
