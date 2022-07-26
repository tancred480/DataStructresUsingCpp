#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Bellman Ford
Dijktras fails sometimes when there is negative weights but bellman ensure to get the right answer and the condition here is there should not be any negative weght cycle.
this algorithm fails there is negative weight cycle in a graph.
but it can detect the negative weight cycle which dijkstras cannot.
this algorithm works only for directed graphs with no negative weight cycle and (no self loop having negativew weight)

-------Here we do n-1 times relaxation ------------
where n => no. of nodes
*/

void bellmanFord(vector<vector<pair<int, int>>> &graph, vector<int> &dist, int source)
{
    int n = graph.size();
    dist[source] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (auto it = graph[j].begin(); it != graph[j].end(); ++it)
            {
                auto child_v = (*it).first, child_d = (*it).second;
                if ((dist[j] + child_d) < dist[child_v])
                {
                    dist[child_v] = (dist[j] + child_d);
                }
            }
        }
    }
}
// As we want just the edges we can also do it just by visisiting all edges n-1 times
void bellmanFordV2(vector<vector<pair<int, int>>> &graph, vector<int> &dist, int source)
{
    int n = graph.size();
    vector<vector<int>> edges;
    for (int j = 0; j < n; j++) // pushing all the edges first
    {
        for (auto it = graph[j].begin(); it != graph[j].end(); ++it)
        {
            auto child_v = (*it).first, child_d = (*it).second;
            edges.push_back({j, child_v, child_d});
        }
    }
    // performing realxation n-1 times
    dist[source] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], wt = e[2];
            dist[v] = min((dist[u] + wt), dist[v]);
        }
    }
}
int main()
{
    int n, e;
    cout << "Enter no. of nodes and edges:\n";
    cin >> n >> e;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> dist(n, 1e9);
    cout << "Enter all edges connection with associative weight :\n";
    for (int i = 0; i < e; i++)
    { // its directional graph with no negative self loop and no negative weight cycle
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
    }
    bellmanFord(graph, dist, 0);
    // bellmanFordV2(graph, dist, 0);
    cout << "\nFinall shortest path Distance of each vertex from source vertex :\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << ":" << dist[i] << "\n";
    }
    return 0;
}