#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// shortest Path in Undirected and unweighted graph; Acyclic graph
vector<int> BFS(vector<vector<int>> &g, int N, int src)
{
    vector<int> dist(N, INT_MAX);
    // vector<int> vis(N, 0);
    queue<int> q;
    dist[src] = 0;
    // vis[src] = 1;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : g[node])
        {
            // if (!vis[child])
            // {
            if (dist[node] + 1 < dist[child])
            {
                dist[child] = dist[node] + 1;
                q.push(child);
            }
            //     vis[child] = 1;
            // }
        }
    }
    return dist;
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    return 0;
}

// Robot Game
//  void solve(int N, vector<int> &A)
//  {
//      vector<int> result(N + 1, 0);
//      vector<pair<int, pair<int, int>>> edges; // weight u->v
//      for (int i = 0; i < N; i++)
//      { // preparing edges
//          int j = i;
//          while (j + 1 + A[i] <= N)
//          {
//              int newInd = j + A[i];
//              edges.push_back({newInd - i + 1, {i, newInd}});
//              j = newInd;
//          }
//          j = i;
//          while ((j + 1 - A[i]) >= 1)
//          {
//              int newInd = j - A[i];
//              edges.push_back({i - newInd + 1, {i, newInd}});
//              j = newInd;
//          }
//      }
//      for (auto &edge : edges)
//      {
//          int x = edge.second.first, y = edge.second.second, wt = edge.first;
//          cout << x + 1 << "->" << y + 1 << " :" << wt << endl;
//      }
//      sort(edges.begin(), edges.end());
//      for (auto &edge : edges)
//      {
//          int x = edge.second.first, y = edge.second.second, wt = edge.first;
//          if (A[y] > wt)
//          {
//              result[y] = 1;
//          }
//      }
//      for (int i = 0; i < N; i++)
//      {
//          cout << result[i] << " ";
//      }
//  }

// int main()
// {
//     vector<int> v = {2, 5, 1, 5, 2};
//     solve(v.size(), v);
//     return 0;
// }