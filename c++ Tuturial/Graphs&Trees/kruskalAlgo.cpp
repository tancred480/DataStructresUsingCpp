#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int parent[N], sz[N];
void make(int v)
{
    parent[v] = v;
    sz[v] = 1;
}
int find(int v)
{
    if (parent[v] == v)
        return parent[v];

    return parent[v] = find(parent[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main()
{
    int n, m;
    cout << "Enter no. of nodes and edges:";
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    cout << "\nEnter all edges with weight and u and v edge:\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> wt >> u >> v;
        edges.push_back({wt, {u, v}});
    }
    sort(edges.begin(), edges.end());

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    int totalCost = 0;
    cout << "\nMST edges:\n";
    for (auto &edge : edges)
    {
        int wt = edge.first;
        int u = edge.second.first, v = edge.second.second;
        if (find(u) == find(v))
            continue;
        Union(u, v);
        totalCost += wt;
        cout << u << " " << v << endl;
    }

    cout << "Total Cost :" << totalCost << endl;
    return 0;
}
