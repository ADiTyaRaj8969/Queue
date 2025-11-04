/*
 Task: Implement a queue using two stacks
*/

#include <bits/stdc++.h>
using namespace std;

class QueueTwoStacks
{
    stack<int> s1, s2;
    void transfer()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

   public:
    void push(int x) { s1.push(x); }
    void pop()
    {
        if (s2.empty())
            transfer();
        if (!s2.empty())
            s2.pop();
    }
    int front()
    {
        if (s2.empty())
            transfer();
        return s2.top();
    }
    bool empty() { return s1.empty() && s2.empty(); }
};

int main()
{
    QueueTwoStacks q;
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

// Time Complexity: Amortized O(1)
// Space Complexity: O(n)
