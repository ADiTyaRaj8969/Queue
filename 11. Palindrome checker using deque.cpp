/*
 Task: Implement a palindrome checker using deque
*/

#include <bits/stdc++.h>
using namespace std;

bool isPal(const string& s)
{
    deque<char> dq;
    for (char c : s) dq.push_back(c);

    while (dq.size() > 1)
    {
        if (dq.front() != dq.back())
            return false;
        dq.pop_front();
        dq.pop_back();
    }

    return true;
}

int main()
{
    cout << isPal("racecar") << "\n";
    cout << isPal("hello") << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
