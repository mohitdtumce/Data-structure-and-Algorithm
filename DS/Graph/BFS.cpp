#include <bits/stdc++.h>
using namespace std;

// Implementing Directed Graph
class Graph
{
  private:
    int V;

    list<int> *adj;

  public:
    Graph(int V);

    void AddEdge(int u, int v);

    void RemoveEdge(int u, int v);

    void BFS();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[this->V];
}

void Graph::AddEdge(int u, int v)
{
    this->adj[u].push_back(v);
}

void Graph::RemoveEdge(int u, int v)
{
    if (u < this->V && v < this->V)
    {
        adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
        adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
    }
}

void Graph::BFS()
{
    vector<bool> visited(this->V, false);
    queue<int> Q;
    int temp;
    for (int i = 0; i < this->V; i++)
    {
        if (!visited[i])
        {
            Q.push(i);
            visited[i] = true;
            while (!Q.empty())
            {
                temp = Q.front();
                Q.pop();

                cout << temp << " ";
                for (auto itr = this->adj[temp].begin(); itr != this->adj[temp].end(); itr++)
                {
                    if (!visited[*itr])
                    {
                        Q.push(*itr);
                        visited[*itr] = true;
                    }
                }
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);
    g.BFS();
}