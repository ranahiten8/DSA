#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node; //our data type

vector<int> mergek(vector<vector<int>> arr)
{
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq; // min priority queue
    // insert 0th element of every array in pq

    for (int i = 0; i < arr.size(); ++i)
    {
        pq.push({arr[i][0], {i, 0}});
    }
    // remove elements from top of pq and add to result vector
    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;  // row in which element is present
        int y = current.second.second; // column in which elemennt is present

        result.push_back(element);

        // push pq next element of current element x,y+1
        if (y + 1 < arr[x].size())
        {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> arr{{2, 6, 12, 15}, {1, 3, 14, 20}, {30, 40}};
    vector<int> output = mergek(arr);
    for (auto x : output)
    {
        cout << x << " ";
    }
    return 0;
}