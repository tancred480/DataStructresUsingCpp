#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N]; // Teacking using visited array of size of no of nodes;
bool dfs(int vertex, int parent)
{
    vis[vertex] = true;
    bool isLoopExists = false;
    for (auto child : g[vertex])
    {
        if (vis[child] == true && child == parent)
            continue;
        if (vis[child] == true)
            return true;
        isLoopExists |= dfs(child, vertex);
    }

    return isLoopExists;
}
// finding a cycle in a graph if exists.
/*  |-----------------|
    |    2--1---3     | 
    |    |   |        |
    |    5---4        |
    |                 |----->together called as "FOREST"
    | 6--7---9        |  
    |        |        |  
    |        8        |
    -------------------  
*/
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
    bool isLoopExists = false;
    // we have to check for every connected component.
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == true)
            continue;
        if (dfs(i, 0) == true)
        {
            isLoopExists = true;
        }
    }
    cout << isLoopExists << endl;
    return 0;
}