#include <bits/stdc++.h>
using namespace std;

/*There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from
first city to second city .You are given information in the form of M pairs (X,Y) i.e there is an
undirected road between city X and city Y. Find out the number of ways in which cities can be chosen.*/

class Graph
{
    int V;
    list<pair<int, int>> l;

public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(int u, int v)
    {
        l.push_back(make_pair(u, v));
    }
    // find
    int findSet(int i, int parent[])
    {
        // base case
        if (parent[i] == -1)
            return i;
        // path compression optimisation
        return parent[i] = findSet(parent[i], parent);
    }
    // union
    void union_set(int x, int y, int parent[], int rank[])
    {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if (s1 != s2)
        {
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
    int pairing()
    {
        // init DSU logic
        int *parent = new int[V];
        int *rank = new int[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
        // code logic
        int ans = 0;
        for (auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;

            int s1 = findSet(i, parent);
            int s2 = findSet(j, parent);

            union_set(s1, s2, parent, rank);
        }
        // go to all the nodes
        for (int i = 0; i < V; i++)
        {
            ans += V - rank[findSet(i, parent)];
        }
        delete[] parent;
        delete[] rank;

        return ans / 2;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;

    Graph g(n);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    cout << g.pairing() << endl;
}
