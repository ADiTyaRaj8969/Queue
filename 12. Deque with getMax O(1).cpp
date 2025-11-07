/*
 Task: Design a deque that supports getMax() in O(1) time
*/

#include <bits/stdc++.h>
using namespace std;

class MaxDeque
{
    deque<int> dq;
    deque<int> maxdq;

   public:
    void push_back(int x)
    {
        dq.push_back(x);
        while (!maxdq.empty() && maxdq.back() < x) maxdq.pop_back();
        maxdq.push_back(x);
    }

    void pop_front()
    {
        if (dq.front() == maxdq.front())
            maxdq.pop_front();
        dq.pop_front();
    }

    int getMax() { return maxdq.front(); }

    int front() { return dq.front(); }

    bool empty() { return dq.empty(); }
};

int main()
{
    MaxDeque d;
    d.push_back(1);
    d.push_back(3);
    d.push_back(2);
    cout << d.getMax() << "\n";
    d.pop_front();
    cout << d.getMax() << "\n";
    return 0;
}

// Time Complexity: O(1) amortized
// Space Complexity: O(n)
