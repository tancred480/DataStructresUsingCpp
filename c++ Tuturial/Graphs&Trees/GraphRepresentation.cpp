#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>

using namespace std;
/*Ways of Representing a graph
    1)Adjacency Matrix
    2)Adjacency List
*/
const int N = 1e3 * 10;
int graph1[N][N]; //Adjacency Matrix Representation.

vector<int> graph2[N];            //Adacency List Representation.
vector<pair<int, int>> graph3[N]; //for Weighted graph

int main()
{
    int n, m;
    cin >> n >> m;
    //forming using Adjacency matrix
    //Adjacency matrix
    //O(N^2) - space Complexity
    //N != 10^5 / N<= 10^3
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1][v2] = wt;
        graph[v2][v1] = wt;
    }

    //Forming using adjacency list
    for (int i = 0; i < m; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }

    //for Weighted Graph
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph3[v1].push_back({v2, wt});
        graph3[v2].push_back({v1, wt});
    }

    if (graph1[i][j] == 1)
    {
        //connected
    }

    graph1[i][j];
    for (int child : graph2[i])
    {
        if (child == j)
        {
            //connected
        }
    }

    return 0;
}