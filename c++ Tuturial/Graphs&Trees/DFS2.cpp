#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
// int graph[N][N];
//  int main()
//  {
//      int n, m;
//      cin >> n >> m;
//      for (int i = 0; i < m; i++)
//      {
//          int v1, v2;
//          cin >> v1 >> v2;
//          graph[v1][v2] = 1;
//          graph[v2][v1] = 1;
//      }
//      cout << endl;
//      for (int i = 0; i < n; i++)
//      {
//          for (int j = 0; j < m; j++)
//          {
//              cout << graph[i][j] << " ";
//          }
//          cout << endl;
//      }
//  }
// vector<int> graph2[N]; // graph representation using adjacency list.
// vector<pair<int,int>> graph[N] // for weighted undirected graph.
// Traversing graph
// Using DFS(depth first search) Algo

int main()
{
    int n, m; // n->no.of nodes m->no. of edges
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2; // enter edges one by one.
        // since its an undirected graph.
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }
    // printing all connections
    for (int i = 0; i < n; i++)
    {
        cout << i << "=>";
        for (int j = 0; j < graph2[i].size(); j++)
        {
            cout << graph2[i][j] << " ";
        }

        cout << endl;
    }
    return 0;
}