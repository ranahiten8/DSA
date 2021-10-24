#include <bits/stdc++.h>
using namespace std;

class heap
{
    vector<int> v;
    bool minheap;
    bool cmp(int a, int b)
    {
        if (minheap)
        {
            return a < b;
        }
        return a > b;
    }
    void heapify(int idx)
    {
        int left = 2 * idx;
        int right = left + 1;

        int min_idx = idx;
        int last = v.size() - 1;

        if (left <= last and cmp(v[left], v[idx]))
        {
            min_idx = left;
        }
        if (right <= last and cmp(v[right], v[min_idx]))
        {
            min_idx = right;
        }

        if (min_idx != idx)
        {
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }

public:
    heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size);
        v.push_back(-1); // 0th index ko block kro -1 se
        minheap = type;
    }
    void push(int d)
    {
        v.push_back(d);
        int index = v.size() - 1;
        int parent = index / 2;

        //keep pushing to top until u reach root or stop midway because condition become false
        while (index > 1 and cmp(v[index], v[parent]))
        {
            swap(v[index], v[parent]);
            index = parent;
            parent = parent / 2;
        }
    }
    int top()
    {
        return v[1];
    }
    void pop()
    {
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }
    bool empty()
    {
        return v.size() == 1; //because 0th index is blocked by -1
    }
    
};

int main()
{
    heap h; //default min heap
    heap h2(10, true); // for max heap

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        h.push(no);
    }

    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }
    return 0;
}