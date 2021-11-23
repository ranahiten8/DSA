#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void helper(T src, map<T, bool> &visited)
    {
        visited[src] = true;
        cout << src << " ";
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                helper(nbr, visited);
            }
        }
    }
    void dfs()
    {
        map<T, bool> visited;
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        int cnt = 0;
        for (auto x : l)
        {
            if (!visited[x.first])
            {
                cout << "Component " << cnt << " -->";
                cnt++;
                helper(x.first, visited);
                cout << endl;
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(3, 0);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(8, 8);
    g.dfs();
    return 0;
}