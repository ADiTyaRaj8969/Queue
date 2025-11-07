/*
 Task: Implement a max-heap priority queue
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
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

// Time Complexity: O(log n) per push/pop
// Space Complexity: O(n)
