/*
 Task: Merge k sorted arrays using min-heap (priority_queue)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeK(vector<vector<int>>& lists)
{
    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;

    int k = static_cast<int>(lists.size());
    for (int i = 0; i < k; ++i)
    {
        if (!lists[i].empty())
            pq.push({lists[i][0], i, 0});
    }

    vector<int> res;
    while (!pq.empty())
    {
        auto [val, idx, pos] = pq.top();
        pq.pop();
        res.push_back(val);
        if (pos + 1 < static_cast<int>(lists[idx].size()))
            pq.push({lists[idx][pos + 1], idx, pos + 1});
    }
    return res;
}

int main()
{
    vector<vector<int>> lists = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    for (auto x : mergeK(lists)) cout << x << " ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(n log k)
// Space Complexity: O(k)
