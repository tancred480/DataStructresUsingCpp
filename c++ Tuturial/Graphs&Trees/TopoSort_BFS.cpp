#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* Topological sort/ordering using BFS Approach
 using Kahn's Algorithm
 This can only be applicable to non-cyclic graph means DAG[directed Acyclic Graph]
 */
void BFS_kahns(vector<vector<int>> &graph, vector<int> &topoSort)
{
    int n = graph.size();
    vector<int> indegree(n);
    // calculating the indegree of each node
    for (int i = 0; i < n; i++)
    {
        for (auto &child : graph[i])
        {
            indegree[child]++;
        }
    }
    queue<int> q;
    for (int node = 0; node < n; node++)
    {
        if (indegree[node] == 0) // pushing those whose indegrees is zero
            q.push(node);
    }
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        // cout << node << " "; // printing
        topoSort.push_back(node);
        for (auto &child : graph[node])
        {
            indegree[child]--;
            if (indegree[child] == 0) // if indegree of node becomes zero push it into the queue
            {
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n);

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    // calling for each component;
    cout << "\nTopologically ordered graph nodes :";
    vector<int> topoSort;
    BFS_kahns(graph, topoSort);
    for (int i = 0; i < n; i++)
    {
        cout << topoSort[i] << " ";
    }
    return 0;
}