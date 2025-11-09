/*
 Task: Simple multi-level queue scheduler simulation
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<queue<int>> levels(3);  // 0 - high, 1 - medium, 2 - low

    // simulate inserting tasks with priority levels
    levels[0].push(1);
    levels[1].push(2);
    levels[2].push(3);
    levels[0].push(4);

    for (size_t lvl = 0; lvl < levels.size(); ++lvl)
    {
        while (!levels[lvl].empty())
        {
            cout << "processing task " << levels[lvl].front() << " at level " << lvl << "\n";
            levels[lvl].pop();
        }
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
