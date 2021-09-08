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

    void bfs(int source, int dest = -1)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *distance = new int[V]{0};
        int *parent = new int[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }

        q.push(source);
        visited[source] = true;

        parent[source] = source;
        distance[source] = 0;

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
                    parent[nbrs] = f;
                    distance[nbrs] = distance[f] + 1;
                    visited[nbrs] = true;
                }
            }
        }

        //print the shortest distance to all the nodes

        for (int i = 0; i < V; i++)
        {
            cout << "Shortest distance to node " << i << " is " << distance[i] << endl;
        }

        //print the path from souce to any destination is destination is given
        if (dest != -1)
        {
            // we can also store dest in temp and then perform the action
            //int temp = dest;
            //while(temp!=source)
            while (dest != source)
            {
                //cout << temp << " -- ";
                cout << dest << " -- ";
                dest = parent[dest];
                //temp = parent[temp];
            }
            cout << source << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    Graph g(7);
    g.addEdges(0, 1);
    g.addEdges(1, 2);
    g.addEdges(2, 3);
    g.addEdges(3, 5);
    g.addEdges(5, 6);
    g.addEdges(4, 5);
    g.addEdges(0, 4);
    g.addEdges(3, 4);
    g.printAdjList();
    g.bfs(1, 6);
    return 0;
}
