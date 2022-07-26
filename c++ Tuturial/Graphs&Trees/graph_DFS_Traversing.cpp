#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N]; // Teacking using visited array of size of no of nodes;

// // Traversing graph using DFS algo.
// void dfs(int vertex)
// { /* Take action on vertex after entering the vertex*/
//     for (auto child : g[vertex])
//     { /* Take action on child before entering the child node*/
//         dfs(child);
//         /* Take action on child after exiting child node*/
//     }
//     /* Take action on vertex before exiting the vertex */
// }
void dfs(int vertex)
{ /* Take action on vertex after entering the vertex*/
    vis[vertex] = true;
    cout << vertex << endl;
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

void dfs2(int v)
{
    vis[v] = true;
    for (auto c : g[v])
    {
        if (vis[c] == true)
            continue;
        dfs2(c);
    }
}
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
    dfs(0);
    return 0;
}