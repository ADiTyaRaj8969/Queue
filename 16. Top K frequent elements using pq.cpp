/*
 Task: Find top K frequent elements from an array using a priority queue
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topK(vector<int>& a, int k)
{
    unordered_map<int, int> cnt;
    for (int x : a) ++cnt[x];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    for (auto& p : cnt)
    {
        pq.push({p.second, p.first});
        if (pq.size() > static_cast<size_t>(k))
            pq.pop();
    }

    vector<int> res;
    while (!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> a = {1, 1, 1, 2, 2, 3};
    auto r = topK(a, 2);
    for (int x : r) cout << x << " ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(n log k)
// Space Complexity: O(n)
