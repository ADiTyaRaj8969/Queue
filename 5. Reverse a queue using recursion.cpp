/*
 Task: Reverse a queue using recursion
*/

#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int>& q)
{
    if (q.empty())
        return;
    int x = q.front();
    q.pop();
    reverseQueue(q);
    q.push(x);
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    reverseQueue(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n) recursion stack
