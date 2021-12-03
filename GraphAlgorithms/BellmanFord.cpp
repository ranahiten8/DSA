#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int n, int src, vector<vector<int>> edges)
{
    vector<int> dist;
    for (int i = 1; i <= n; i++)
        dist.push_back(INT_MAX);

    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto x : edges)
        {
            int from, to, weight;
            from = x[0];
            to = x[1];
            weight = x[2];
            if (dist[from] != INT_MAX and dist[to] > dist[from] + weight)
            {
                dist[to] = dist[from] + weight;
                cout << dist[to] << x[0] << x[1] << endl;
            }
        }
    }
    for (auto x : edges)
    {
        int from, to, weight;
        from = x[0];
        to = x[1];
        weight = x[2];
        if (dist[from] != INT_MAX and dist[to] > dist[from] + weight)
        {
            cout << "NEgative Weight Cycle \n";
            exit(0);
        }
    }
    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    vector<int> dist = bellman_ford(n, 1, edges);
    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of " << i << "From 1 is " << dist[i] << endl;
    }
}
