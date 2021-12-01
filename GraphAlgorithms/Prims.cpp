#include <bits/stdc++.h>
using namespace std;
class graph
{
    vector<pair<int, int>> *l;
    int V;

public:
    graph(int n)
    {
        V = n;
        l = new vector<pair<int, int>>[n];
    }
    void addedge(int x, int y, int w)
    {
        l[x].push_back(make_pair(y, w));
        l[y].push_back(make_pair(x, w));
    }
    int prim()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        bool *vis = new bool[V]{0};
        int ans = 0;
        q.push({0, 0});
        while (!q.empty())
        {
            auto best = q.top();
            q.pop();
            int to = best.second;
            int weight = best.first;
            if (vis[to])
                continue;
            else
            {
                ans = ans + weight;
                vis[to] = 1;
                for (auto x : l[to])
                {
                    if (vis[x.first] == 0)
                        q.push(make_pair(x.second, x.first));
                }
            }
        }
        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addedge(x - 1, y - 1, w);
    }
    cout << g.prim();
    return 0;
}
