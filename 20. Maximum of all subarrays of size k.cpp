/*
 Task: Maximum of all subarrays of size k (same as sliding window maximum)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> maxSubarrays(vector<int>& a, int k)
{
    deque<int> dq;
    vector<int> res;

    for (int i = 0; i < static_cast<int>(a.size()); ++i)
    {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            res.push_back(a[dq.front()]);
    }

    return res;
}

int main()
{
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    for (auto x : maxSubarrays(a, 3)) cout << x << " ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(k)
