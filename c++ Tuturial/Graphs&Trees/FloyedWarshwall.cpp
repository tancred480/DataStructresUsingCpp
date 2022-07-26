#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// all pair shortest path using Floyed Warshwall Algorithm
// It handle's negative weighted graphs
// But it does not handles negative weighted cycles
const int INF = 1e9 + 7;
int main()
{
    // floyed warshwall algorithm
    int v, e;
    cin >> v >> e;
    int graph[v][e];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i != j)
                graph[i][j] = INF;
            else
                graph[i][j] = 0;
        }
    }
    // all adjacent edges values ;its directed graph

    for (int j = 0; j < e; j++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x - 1][y - 1] = wt;
    }
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                graph[i][j] = min(graph[i][j], (graph[i][k] + graph[k][j]));
            }
        }
    }
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (graph[i][j] == (1e9 + 7))
                cout << 'I' << " ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
