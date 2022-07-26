#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
    1      2
    |\    /|
    | \  / |
    |   3  |
    |  /|\ |
    | / | \|
    |/  4  |
    |    \ |
    5------6
*/
const int N = 1e5 + 10;

vector<int> g[N];
bool vis[N]; // visited array

void dfs(int vertex)
{
    /*Take action on vertex after entering
        the vertex.
    */
    if (vis[vertex])
        return; // checking the child vertex at entry point ki whether its been visited or not.
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        // if(vis[child]) continue;
        cout << "parent " << vertex << ",child " << child << endl;
        /*Take action on child before
        entering the child node
       */
        dfs(child);
        /*Take action on child
       after exiting child node
       */
    }
    /*Take action on vertex before
   exiting the vertex.
   */
}

void dfs(int vertex)
{
    if (vis[vertex])
        return;
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        dfs(child);
    }
}

int main()
{
    int n, e; // number of nodes and edges
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << ":";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "size :" << g[i].size() << "\n";
    //     for (int j = 0; j < g[i].size(); j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // dfs(1);
    // calculating number of connected components.
    int ct = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        dfs(i);
        ct++;
    }
    cout << ct << endl;
    return 0;
}