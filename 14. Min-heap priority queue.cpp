/*
 Task: Implement a min-heap priority queue
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(1);
    pq.push(5);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << "\n";
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(n)
