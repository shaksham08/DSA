#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int n)
    {
        this->V = n;
        this->l = new list<int>[V];
    }

    void addEdges(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
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

    void bfs(int source)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};

        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int f = q.front();
            cout << f << endl;
            q.pop();

            for (auto nbrs : l[f])
            {
                if (!visited[nbrs])
                {
                    q.push(nbrs);
                    visited[nbrs] = true;
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph g(6);
    g.addEdges(0, 1);
    g.addEdges(0, 2);
    g.addEdges(2, 3);
    g.addEdges(1, 4);
    g.addEdges(4, 5);
    g.addEdges(3, 5);
    g.printAdjList();
    g.bfs(0);
    return 0;
}
