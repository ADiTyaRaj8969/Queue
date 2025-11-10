/*
 Task: Simple task scheduling with priorities using priority_queue
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<pair<int, string>> pq;

    pq.push({10, "A"});
    pq.push({5, "B"});
    pq.push({20, "C"});

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        cout << p.second << " with priority " << p.first << "\n";
    }

    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)
