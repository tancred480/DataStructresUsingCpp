#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
------Multi-source BFS--------
here we run simple BFS but we all source in the begining of the queue
like as we do in normal bfs but there we just push only one source here we push mulitple source

And its been proved that we will get the shortest path possible with respect to all sources.
such that minimum possible path possible with all sources taken into consideration.
*/
int dist[10010]; // this would actually store the level/shortest distance of each node possible
void MultiSrcBFS(vector<vector<int>> &g, vector<int> sources)
{
    int n = g.size();
    vector<bool> visited(n, false);
    queue<int> q;
    for (auto src : sources)
    {
        q.push(src);
        visited[src] = true;
        dist[src] = 0;
    }
    int level = 0;
    while (!q.empty())
    {
        int qsize = q.size();
        level++;
        for (int i = 0; i < qsize; i++)
        {
            int node = q.front();
            q.pop();
            for (auto &child : g[node])
            {
                if (!visited[child])
                {
                    q.push(child);
                    dist[child] = level;
                    visited[child] = true;
                }
            }
        }
    }
}
int main()
{
    int n, e;
    cout << "Enter no. of nodes and edges:";
    cin >> n >> e; // since in a tree there are n-1 edges
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int m;
    cout << "Enter no. of sources :";
    cin >> m;
    vector<int> sources(m);
    for (auto &src : sources)
        cin >> src;
    MultiSrcBFS(g, sources);

    for (int i = 1; i <= n; i++)
    {
        cout << i << ": " << dist[i] << endl;
    }

    return 0;
}