#include <bits/stdc++.h>
using namespace std;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        // parent=-1 rank=1
        for (int i = 0; i < n; ++i)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // find
    int find(int i)
    {
        // base case
        if (parent[i] == -1)
        {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    // unite
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            // union by rank
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void addedge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }

    int Kruskal()
    {
        // GREEDY ALGO

        // 1. Sort the edge list based upon weight
        sort(edgelist.begin(), edgelist.end());

        // init a DSU
        DSU s(V);

        int ans = 0;
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // take that edge in MST if it doesnt form a cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g(4);
    g.addedge(0, 1, 1);
    g.addedge(1, 3, 3);
    g.addedge(3, 2, 4);
    g.addedge(2, 0, 2);
    g.addedge(1, 2, 2);
    g.addedge(0, 3, 2);

    cout << g.Kruskal();
    return 0;
}