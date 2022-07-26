#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Subtree Operation uper aate hue hote hai
Given Q quries, Q<=10^5
In each  query given V,
Print subtree sum of V, Number of even numbers
in subtree of V
*/
// calculated the sum of each subtree of a tree
int subtreeSum[10010];
void dfs(int vertex, int parent, vector<vector<int>> &g)
{
    subtreeSum[vertex] = vertex;
    for (auto &child : g[vertex])
    {
        if (child != parent)
        {
            dfs(child, vertex, g);
            subtreeSum[vertex] += subtreeSum[child];
        }
    }
}
int EvenCount[10010];
void EvenCountInSubtree(int vertex, int parent, vector<vector<int>> &g)
{
    if (vertex % 2 == 0)
        EvenCount[vertex]++;
    for (auto &child : g[vertex])
    {
        if (child != parent)
        {
            EvenCountInSubtree(child, vertex, g);
            EvenCount[vertex] += EvenCount[child];
        }
    }
}
int main()
{
    int n, e; // number of nodes and edges
    cin >> n >> e;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1, -1, g);
    EvenCountInSubtree(1, -1, g);
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ":" << subtreeSum[i] << endl;
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << ":" << EvenCount[i] << endl;
    }
    return 0;
}