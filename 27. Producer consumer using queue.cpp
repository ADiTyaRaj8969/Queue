/*
 Task: Producer-consumer simulation using queue and condition_variable
*/

#include <bits/stdc++.h>
using namespace std;

queue<int> q;
mutex m;
condition_variable cv;
bool done = false;

void producer()
{
    for (int i = 1; i <= 5; ++i)
    {
        {
            unique_lock<mutex> lk(m);
            q.push(i);
            cout << "produced " << i << "\n";
        }
        cv.notify_one();
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    {
        unique_lock<mutex> lk(m);
        done = true;
    }
    cv.notify_all();
}

void consumer(int id)
{
    while (true)
    {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [] { return !q.empty() || done; });

        if (!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << "consumer " << id << " consumed " << v << "\n";
        }
        else if (done)
        {
            break;
        }
    }
}

int main()
{
    thread p(producer);
    thread c1(consumer, 1);
    thread c2(consumer, 2);

    p.join();
    c1.join();
    c2.join();

    return 0;
}

// Time Complexity: Depends on workload
// Space Complexity: O(n)
