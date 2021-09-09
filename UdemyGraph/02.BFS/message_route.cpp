#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int n)
    {
        V = n;
        l = new list<int>[V];
    }

    void addEdge(int x, int y, bool undir = true)
    {
        l[x].push_back(y);
        if (undir)
        {
            l[y].push_back(x);
        }
    }

    void printAdjList()
    {
        //Iterate over all the rows
        for (int i = 0; i < V; i++)
        {
            cout << i << "-->";
            //every element of ith linked list
            for (auto node : l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }

    int shortestPath(int src, int dest = -1)
    {
        bool visited[V] = {0};
        int distance[V] = {0};
        int parent[V];

        for (int i = 0; i < V; i++)
        {
            parent[V] = -1;
        }

        queue<int> q;

        q.push(src);
        visited[src] = true;
        distance[src] = 0;
        parent[src] = src;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            for (auto nbrs : l[f])
            {
                if (!visited[nbrs])
                {
                    q.push(nbrs);
                    visited[nbrs] = true;
                    distance[nbrs] = distance[f] + 1;
                    parent[nbrs] = f;
                }
            }
        }

        if (distance[dest] == -1)
        {
            return -1;
        }

        for (int i = 0; i < V; i++)
        {
            cout << "Shortest distance to node " << i << " is " << distance[i] << endl;
        }
        return distance[dest] + 1;
    }
};

int messageRoute(int n, vector<vector<int>> edges)
{
    cout << n << endl;
    Graph g(n + 1);
    for (auto edge : edges)
    {
        int first = edge[0];
        int second = edge[1];
        g.addEdge(first, second);
    }
    g.printAdjList();
    return g.shortestPath(1, n);
}
