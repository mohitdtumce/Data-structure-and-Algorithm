#include <bits/stdc++.h>
using namespace std;

// Implementing Directed Graph
class Graph
{
  private:
    int V;

    list<int> *adj;

    bool IsCyclicHelper(int v, vector<bool> &visited, vector<bool> &recStack);

  public:
    Graph(int V);

    void AddEdge(int u, int v);

    void RemoveEdge(int u, int v);

    bool IsCyclic();
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

bool Graph::IsCyclicHelper(int v, vector<bool> &visited, vector<bool> &recStack)
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;

        for (auto itr = adj[v].begin(); itr != adj[v].end(); itr++)
        {
            if (!visited[*itr])
            {
                if (IsCyclicHelper(*itr, visited, recStack))
                    return true;
            }
            else
            {
                if (recStack[*itr])
                    return true;
            }
        }

        recStack[v] = false;
        return false;
    }
}

bool Graph::IsCyclic()
{
    vector<bool> visited(this->V, false);
    vector<bool> recStack(this->V, false);
    for (int v = 0; v < this->V; v++)
    {
        if (IsCyclicHelper(v, visited, recStack))
            return true;
    }
    return false;
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
    cout<<g.IsCyclic();
}