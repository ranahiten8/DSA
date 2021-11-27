#include <bits/stdc++.h>
using namespace std;

// cycle detection in undirected graph using DSU

class Graph
{
    int V;
    list<pair<int, int>> l; // edge list

public:
    Graph(int v)
    {
        V = v;
    }
    void add_edge(int u, int v)
    {
        l.push_back(make_pair(u, v));
    }

    int findset(int i, int parent[]) //worst case O(n)
    {
        // base case
        if (parent[i] == -1)
            return i;

        return findset(parent[i], parent);
    }

    void unionset(int x, int y, int parent[]) //worst case O(n)
    {
        int s1 = findset(x, parent);
        int s2 = findset(y, parent);

        if (s1 != s2)
            parent[s2] = s1;
    }

    bool contains_cycle()
    {
        int *parent = new int[V];
        for (int i = 0; i < V; ++i)
        {
            parent[i] = -1;
        }

        for (auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;

            int s1 = findset(i, parent);
            int s2 = findset(j, parent);

            if (s1 != s2)
                unionset(s1, s2, parent);
            else
                return true;
        }
        delete[] parent;
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 0);

    cout<<g.contains_cycle();
    return 0;
}