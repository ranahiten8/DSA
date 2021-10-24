//build heap using array inplace and O(n) complexity

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

bool minheap = false;
bool cmp(int a, int b)
{
    if (minheap)
    {
        return a < b;
    }
    return a > b;
}

void heapify(vector<int> &v, int idx)
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
        heapify(v, min_idx);
    }
}

void buildheap(vector<int> &v)
{
    for (int i = (v.size() - 1); i >= 1; i--)
    {
        heapify(v, i);
    }
}

int main()
{
    vector<int> v{-1, 10, 20, 5, 7, 8, 30, 3, 4};

    print(v);
    buildheap(v);
    print(v);
    return 0;
}