#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
    }
    void helper(T src, map<T, bool> &visited, list<T> &ordering)
    {
        visited[src] = true;
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                helper(nbr, visited,ordering);
            }
        }
        ordering.push_front(src);
    }
    void dfs()
    {
        map<T, bool> visited;
        list<T> ordering;
        // code work without this for loop also
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }
        for (auto p : l)
        {
            T node = p.first;
            if (!visited[node])
            {
                helper(node, visited, ordering);
            }
        }

        for (auto x : ordering)
        {
            cout << x << endl;
        }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("Python", "DataPreProcessing");
    g.addEdge("Python", "Pytorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataPreProcessing", "ML");
    g.addEdge("Pytorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecogn");
    g.addEdge("Dataset", "FaceRecogn");
    g.dfs();
    return 0;
}