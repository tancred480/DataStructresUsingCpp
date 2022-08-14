#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

// This DFS will check for the cycle
void dfs(int vertex, int parent, vector<vector<int>> g, vector<bool> vis, bool &check)
{
    if (vis[vertex])
    {
        check = true;
        return;
    }
    vis[vertex] = true;
    for (auto &child : g[vertex])
    {
        if (child != parent)
        {
            dfs(child, vertex, g, vis, check);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<bool> vis(n + 1);
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> wt >> u >> v;
        edges.push_back({wt, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int TotalCost = 0;
    for (auto &edge : edges)
    {
        int u = edge.second.first, v = edge.second.second, wt = edge.first;
        g[u].push_back(v);
        g[v].push_back(u);
        fill(vis.begin(), vis.end(), false);
        bool check = false;
        dfs(u, -1, g, vis, check);
        if (check)
        {
            g[u].pop_back();
            g[v].pop_back();
        }
        else
        {
            TotalCost += wt;
        }
    }
    // printing the final MST;
    cout << "\nFinal MST :\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Total Cost :" << TotalCost;
    return 0;
}
