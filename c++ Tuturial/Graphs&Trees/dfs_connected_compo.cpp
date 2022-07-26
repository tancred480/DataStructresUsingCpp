#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];            // Teacking using visited array of size of no of nodes;
vector<vector<int>> cc; // connected component
vector<int> current_cc; // currently stored connected component

void dfs(int vertex)
{ /* Take action on vertex after entering the vertex*/
    cout << vertex << endl;
    vis[vertex] = true;
    current_cc.push_back(vertex);
    for (auto child : g[vertex])
    { /* Take action on child before entering the child node*/
        cout << "parent " << vertex << " child " << child << endl;
        if (vis[child] == true)
            continue;
        dfs(child);
        /* Take action on child after exiting child node*/
    }
    /* Take action on vertex before exiting the vertex */
}

// finding connected components in a graph or forest.
int main()
{
    int n, e;
    cin >> n >> e; // n->no of nodes ,e->no of edges.
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    // finding connected components
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == true)
            continue;
        current_cc.clear();
        count++;
        dfs(i);
        cc.push_back(current_cc);
    }

    cout << "Total connected components = " << count << endl;
    for (auto c_cc : cc)
    {
        for (int v : c_cc)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}