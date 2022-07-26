#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sortByVal(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < e; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
        graph[y].push_back({x, wt});
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "{" << graph[i][j].first << " " << graph[i][j].second << "} ";
        }
        cout << endl;
    }
    vector<vector<pair<int, int>>> Agraph(n); // answer graph
    vector<pair<int, pair<int, int>>> edges;

    vector<bool> vis(n, false);
    vector<int> dist(n, 1e9);
    int source = 0;
    dist[source] = 0;
    for (auto &child : graph[0])
    {
        int x = 0, y = child.first, wt = child.second;
        edges.push_back({wt, {x, y}});
    }
    sort(edges.begin(), edges.end());
    while (edges.size() > 0)
    {
        auto node = *edges.begin();
        edges.erase(edges.begin()); // pop from front
        int x = node.second.first, y = node.second.second, wt = node.first;
        if (vis[x] && vis[y]) // if both are visited that means it will create a cycle which is against prims alo we do not allow cycle in graph
            continue;         // if both nodes are visited then continue
        vis[x] = true;

        if ((dist[x] + wt) < dist[y])
        {
            Agraph[x].push_back({y, wt});
            Agraph[y].push_back({x, wt});
            dist[y] = (dist[x] + wt);
        }
        for (auto &child : graph[y])
        {
            int u = y, v = child.first, w = child.second;
            edges.push_back({w, {u, v}});
        }
        sort(edges.begin(), edges.end());
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < Agraph[i].size(); j++)
        {
            cout << "{" << Agraph[i][j].first << " " << Agraph[i][j].second << "} ";
        }
        cout << endl;
    }
    return 0;
}