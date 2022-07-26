#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
This Topological ordering of nodes can only be done in Directed Acyclic Graph (DAG)
Topological sorting is nothing but ordering of nodes in a linear fashion such
that its order follows from graph means 'node1 node2 node3'
 in a graph also node1 is before node2 and node3
*/

// Topological sorting using DFS
void DFS(int vertex, vector<vector<int>> &graph, vector<bool> &vis, stack<int> &st)
{
    if (vis[vertex])
        return;
    vis[vertex] = true;
    for (auto &child : graph[vertex])
    {
        DFS(child, graph, vis, st);
    }
    st.push(vertex);
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);
    vector<bool> vis(n, false);
    stack<int> st; // here we will store our topologically ordered nodes of graph
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    // calling for each component;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            DFS(i, graph, vis, st);
    }
    cout << "\nTopologically ordered graph nodes :";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}