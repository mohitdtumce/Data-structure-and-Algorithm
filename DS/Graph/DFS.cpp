#include <bits/stdc++.h>
using namespace std;

// Implementing Directed Graph
class Graph
{
  private:
    int V;

    list<int> *adj;

    void DFSHelper(int source, vector<bool> &visited);

  public:
    Graph(int V);

    void AddEdge(int u, int v);

    void RemoveEdge(int u, int v);

    void DFS();
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

void Graph::DFSHelper(int source, vector<bool> &visited)
{
    visited[source] = true;
    cout << source << " ";
    
    for (auto itr = adj[source].begin(); itr != adj[source].end(); itr++)
    {
        if (!visited[*itr])
        {
            DFSHelper(*itr, visited);
        }
    }
}
void Graph::DFS()
{
    vector<bool> visited(this->V, false);

    for (int v = 0; v < this->V; v++)
    {
        if (!visited[v])
        {
            DFSHelper(v, visited);
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
    g.DFS();
}