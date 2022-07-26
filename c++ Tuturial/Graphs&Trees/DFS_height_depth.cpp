#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N]; // Teacking using visited array of size of no of nodes;

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
int depth[N], height[N];
void cal_height_depth(int vertex, int parent)
{
    /* Take action on vertex after entering the vertex*/
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        /*Take action on child before entering the child node*/
        if (child == parent)
        {
            continue;
        }
        depth[child] = depth[vertex] + 1;
        cal_height_depth(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
        /*Take action on child after exiting child node*/
    }
    /*Take action on vertex before exition the vertex*/
}
int main()
{
    int n, e;
    cin >> n >> e; // n->no of nodes ,e->no of edges.
    // if there is n vertex the edges = n-1 property of a tree
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
    cal_height_depth(1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cout << i << " depth =>" << depth[i] << " height =>" << height[i] << endl;
    }
    return 0;
}