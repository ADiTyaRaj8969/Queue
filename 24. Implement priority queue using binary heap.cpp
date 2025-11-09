/*
 Task: Implement binary max-heap as a priority queue
*/

#include <bits/stdc++.h>
using namespace std;

class BinaryHeap
{
    vector<int> heap;

    void siftUp(int i)
    {
        while (i > 0)
        {
            int p = (i - 1) / 2;
            if (heap[p] >= heap[i])
                break;
            swap(heap[p], heap[i]);
            i = p;
        }
    }

    void siftDown(int i)
    {
        int n = heap.size();
        while (true)
        {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int largest = i;
            if (l < n && heap[l] > heap[largest])
                largest = l;
            if (r < n && heap[r] > heap[largest])
                largest = r;
            if (largest == i)
                break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

   public:
    void push(int x)
    {
        heap.push_back(x);
        siftUp(heap.size() - 1);
    }

    int top()
    {
        if (heap.empty())
            throw runtime_error("empty");
        return heap[0];
    }

    void pop()
    {
        if (heap.empty())
            throw runtime_error("empty");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            siftDown(0);
    }

    int size() { return heap.size(); }
};

int main()
{
    BinaryHeap h;
    h.push(3);
    h.push(1);
    h.push(5);
    cout << h.top() << "\n";
    h.pop();
    cout << h.top() << "\n";
    return 0;
}

// Time Complexity: O(log n) per push/pop
// Space Complexity: O(n)
