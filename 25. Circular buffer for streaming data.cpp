/*
 Task: Implement circular buffer for streaming data
*/

#include <bits/stdc++.h>
using namespace std;

class CircularBuffer
{
   public:
    explicit CircularBuffer(int k) : buf(k), head(0), tail(0), cap(k), sz(0) {}

    bool write(int x)
    {
        if (sz == cap)
            return false;  // buffer full
        buf[tail] = x;
        tail = (tail + 1) % cap;
        ++sz;
        return true;
    }

    bool read(int& out)
    {
        if (sz == 0)
            return false;  // buffer empty
        out = buf[head];
        head = (head + 1) % cap;
        --sz;
        return true;
    }

    int size() const { return sz; }

   private:
    vector<int> buf;
    int head;
    int tail;
    int cap;
    int sz;
};

int main()
{
    CircularBuffer cb(3);
    cb.write(1);
    cb.write(2);

    int v = 0;
    if (cb.read(v))
    {
        cout << v << "\n";
    }

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(k)
