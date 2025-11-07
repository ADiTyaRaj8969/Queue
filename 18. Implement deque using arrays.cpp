/*
 Task: Implement deque using a circular array
*/

#include <bits/stdc++.h>
using namespace std;

class MyDeque
{
    int* arr;
    int cap;
    int fronti;
    int size;

   public:
    MyDeque(int k)
    {
        cap = k;
        arr = new int[cap];
        fronti = 0;
        size = 0;
    }

    ~MyDeque() { delete[] arr; }

    bool push_back(int x)
    {
        if (size == cap)
            return false;
        arr[(fronti + size) % cap] = x;
        size++;
        return true;
    }

    bool push_front(int x)
    {
        if (size == cap)
            return false;
        fronti = (fronti - 1 + cap) % cap;
        arr[fronti] = x;
        size++;
        return true;
    }

    bool pop_back()
    {
        if (size == 0)
            return false;
        size--;
        return true;
    }

    bool pop_front()
    {
        if (size == 0)
            return false;
        fronti = (fronti + 1) % cap;
        size--;
        return true;
    }

    int get_front()
    {
        if (size == 0)
            throw runtime_error("empty");
        return arr[fronti];
    }

    int get_back()
    {
        if (size == 0)
            throw runtime_error("empty");
        return arr[(fronti + size - 1) % cap];
    }

    int get_size() { return size; }
};

int main()
{
    MyDeque dq(5);
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(0);
    cout << dq.get_front() << " " << dq.get_back() << "\n";
    dq.pop_front();
    cout << dq.get_front() << "\n";
    return 0;
}

// Time Complexity: operations O(1)
// Space Complexity: O(k)
