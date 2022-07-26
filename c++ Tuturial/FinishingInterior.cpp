#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void topoSort(int vertex, vector<vector<int>> &graph, vector<bool> &vis, stack<int> &st)
{
    if (vis[vertex])
        return;
    vis[vertex] = true;
    for (auto child : graph[vertex])
    {
        if (!vis[child])
        {
            topoSort(child, graph, vis, st);
        }
    }
    st.push(vertex);
}

void FindMinReqDays(vector<vector<int>> &graph, vector<bool> &vis, int startVertex)
{
    vector<vector<int>> levels;
    queue<int> q;
    q.push(startVertex);
    vis[startVertex] = true;
    while (!q.empty())
    {
        vector<int> temp;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int node = q.front();
            temp.push_back(node);
            q.pop();
            for (auto &child : graph[node])
            {
                if (!vis[child])
                {
                    vis[child] = true;
                    q.push(child);
                }
            }
        }
        levels.push_back(temp);
    }
    cout << endl;
    for (int i = 0; i < levels.size(); i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < levels[i].size(); j++)
        {
            cout << levels[i][j] << " ";
        }
        cout << endl;
    }
    int minReqDays = levels.size();
    cout << "\nMinimum Required Days :" << minReqDays << " ";
}

int main()
{
    int n, e;
    cout << "\nEnter no of nodes and edges : ";
    cin >> n >> e;
    vector<vector<int>> g(n);
    cout << "\nEnter All edges : ";
    for (int i = 0; i < e; i++)
    { // unidirectional
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        // g[y].push_back(x);
    }
    stack<int> st;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topoSort(i, g, vis, st);
        }
    }
    cout << "Topo-Sort:";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    int sv;
    cout << "\nEnter Start Vertex :";
    cin >> sv;
    fill(vis.begin(), vis.end(), false);
    FindMinReqDays(g, vis, sv);
    return 0;
}