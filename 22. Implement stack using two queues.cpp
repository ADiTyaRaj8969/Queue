/*
 Task: Implement stack using two queues
*/

#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    queue<int> q1, q2;

   public:
    void push(int x) { q1.push(x); }

    int pop()
    {
        if (q1.empty())
            throw runtime_error("empty");
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int v = q1.front();
        q1.pop();
        swap(q1, q2);
        return v;
    }

    int top()
    {
        if (q1.empty())
            throw runtime_error("empty");
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int v = q1.front();
        q2.push(v);
        q1.pop();
        swap(q1, q2);
        return v;
    }

    bool empty() { return q1.empty(); }
};

int main()
{
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.top() << "\n";
    cout << s.pop() << "\n";
    cout << s.empty() << "\n";
    return 0;
}

// Time Complexity: O(n) for pop/top, O(1) for push
// Space Complexity: O(n)
