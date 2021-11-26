#include <bits/stdc++.h>
using namespace std;

class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool help(int node, bool *visited, int parent)
    {
        // visit a node
        visited[node] = true;

        for (auto nbr : l[node])
        {
            // 2 cases
            // go and recursively visit the nbr
            if (!visited[nbr])
            {
                bool cycle_mila = help(nbr, visited, node);
                if (cycle_mila)
                    return true;
            }
            // nbr is visited but nbr should not be equal to parent
            else if (nbr != parent)
                return true;
        }

        return false;
    }

    bool containscycle()
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; ++i)
        {
            visited[i] = false;
        }
        return help(0, visited, -1);
    }
};

int main()
{

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    // g.addEdge(4, 0); //this makes it have a cycle

    if (g.containscycle())
        cout << "yes it has cycle";
    else
        cout << "no cycle";

    return 0;
}