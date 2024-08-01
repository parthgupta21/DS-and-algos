#include <bits/stdc++.h>

using namespace std;

class dsu
{
    vector<int> parent;
    vector<int> sz;

public:
    dsu(int n)
    {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        u = findPar(u);
        v = findPar(v);

        if (u != v)
        {
            if (sz[u] < sz[v])
            {
                parent[u] = v;
                sz[v] += sz[u];
            }
            else
            {
                parent[v] = u;
                sz[u] += sz[v];
            }
        }
    }
};

int main()
{

    vector<vector<int>> edges = {{1, 2},
                                 {2, 3},
                                 {3, 4},
                                 {1, 4},
                                 {1, 5}};

    int maxNode = 0;
    for (const auto &edge : edges)
    {
        maxNode = max(maxNode, max(edge[0], edge[1]));
    }

    dsu ds(maxNode);

    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1];
        if (ds.findPar(u) == ds.findPar(v))
        {
            cout << "Redundant edge: [" << u << ", " << v << "]" << endl;
            // This edge forms a cycle
        }
        else
        {
            ds.unionBySize(u, v);
        }
    }

    return 0;
}
