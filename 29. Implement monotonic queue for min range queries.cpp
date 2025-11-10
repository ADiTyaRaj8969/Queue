/*
 Task: Monotonic queue for range minimum/maximum queries
*/

#include <bits/stdc++.h>
using namespace std;

struct MonotonicQueue
{
    deque<int> dq;

    void push(int x)
    {
        while (!dq.empty() && dq.back() > x) dq.pop_back();
        dq.push_back(x);
    }

    void pop(int x)
    {
        if (!dq.empty() && dq.front() == x)
            dq.pop_front();
    }

    int getMin()
    {
        if (dq.empty())
            throw runtime_error("empty");
        return dq.front();
    }
};

int main()
{
    vector<int> a = {2, 1, 3, 4, 6, 3, 8, 9, 10, 12, 56};
    int k = 4;
    MonotonicQueue mq;

    for (size_t i = 0; i < a.size(); ++i)
    {
        if (i < static_cast<size_t>(k) - 1)
        {
            mq.push(a[i]);
        }
        else
        {
            mq.push(a[i]);
            cout << mq.getMin() << " ";
            mq.pop(a[i - k + 1]);
        }
    }

    cout << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(k)
