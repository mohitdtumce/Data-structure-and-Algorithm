#include <bits/stdc++.h>
using namespace std;

class Graph
{
  private:
    int V;
    list<int> *adj;

  public:
    Graph(int V)
    {
        this->V = V;
        this->adj = new list<int>[this->V];
    }

    void AddEdge(int u, int v)
    {
        this->adj[u].push_back(v);
        this->adj[v].push_back(u);
    }

    bool IsSafe(int v, vector<int> &color, int c)
    {
        for (auto itr = this->adj[v].begin(); itr != this->adj[v].end(); itr++)
        {
            if (color[*itr] == c)
                return false;
        }
        return true;
    }

    bool MColoringProblemHelper(int v, vector<int> &color, const int &M)
    {
        if (v == this->V)
            return true;
        else
        {
            for (int c = 1; c <= M; c++)
            {
                if (IsSafe(v, color, c))
                {
                    color[v] = c;
                    if (MColoringProblemHelper(v + 1, color, M))
                        return true;
                    color[v] = 0;
                }
            }
        }
    }

    bool MColoringProblem(const int &M)
    {
        vector<int> color(this->V, 0);

        if (MColoringProblemHelper(0, color, M))
        {
            for (int v = 0; v < this->V; v++)
            {
                cout << color[v] << " ";
            }
            cout<<"\n";
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(0, 3);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    cout<<g.MColoringProblem(3);

}