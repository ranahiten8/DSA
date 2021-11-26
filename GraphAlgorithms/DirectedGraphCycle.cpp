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
    }

    bool help(int node, bool *visited, bool *stack)
    {
        // visit a node
        visited[node] = true;
        stack[node] = true;

        for (int nbr : l[node])
        {
            // 2 cases
            if (stack[nbr] == true)
                return true;
            else if (visited[nbr] == false)
            {
                bool cycle_mila = help(nbr, visited, stack);
                if (cycle_mila == true)
                    return true;
            }
        }

        // leave a node
        stack[node] = false;
        return false;
    }

    bool containscycle()
    {
        bool *visited = new bool[V];
        bool *stack = new bool[V];
        for (int i = 0; i < V; ++i)
        {
            visited[i] = stack[i] = false;
        }
        return help(0, visited, stack);
    }
};

int main()
{

    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(4, 2); // this is the back edge which makes cycle

    if (g.containscycle())
        cout << "yes it has cycle";
    else
        cout << "no cycle";

    return 0;
}