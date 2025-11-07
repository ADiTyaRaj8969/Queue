/*
 Task: Merge k sorted arrays using a priority queue
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> lists = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    for (int i = 0; i < static_cast<int>(lists.size()); ++i)
    {
        if (!lists[i].empty())
            pq.push({lists[i][0], {i, 0}});
    }

    vector<int> out;
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        out.push_back(t.first);
        int i = t.second.first;
        int idx = t.second.second;
        if (idx + 1 < static_cast<int>(lists[i].size()))
            pq.push({lists[i][idx + 1], {i, idx + 1}});
    }

    for (int x : out) cout << x << " ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(N log k)
// Space Complexity: O(k)
