/*
 Task: Find the first non-repeating element in a stream
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> firstNonRepeating(const vector<int>& stream)
{
    unordered_map<int, int> cnt;
    queue<int> q;
    vector<int> res;
    for (int x : stream)
    {
        cnt[x]++;
        if (cnt[x] == 1)
            q.push(x);
        while (!q.empty() && cnt[q.front()] > 1) q.pop();
        res.push_back(q.empty() ? -1 : q.front());
    }
    return res;
}

int main()
{
    vector<int> s = {2, 2, 3, 4, 3, 5};
    auto r = firstNonRepeating(s);
    for (int x : r) cout << x << " ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
