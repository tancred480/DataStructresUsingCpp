#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// kosarajus algorithm -> [SCC - Strongly connected component]
/*
This algorithm helps to find the strongly connected components in a graph
strongly connected components -> In this component every node can be reach to every other member of this component.
It does this work of finding the SCC using 3 (steps)

step 1: sort all the nodes in order of their finishing time(here we will use topoSort)

step 2: Transpose the graph -> which means change the direction each edge

*/

void DFS_TopoSort(int node, vector<vector<int>> &graph, vector<bool> &vis, stack<int> &topoOrder)
{
    if (vis[node])
        return;
    vis[node] = true;
    for (auto &child : graph[node])
    {
        DFS_TopoSort(child, graph, vis, topoOrder);
    }
    topoOrder.push(node);
}

vector<vector<int>> TransposeGraph(vector<vector<int>> &graph)
{
    int n = graph.size();          // no. of nodes in graph
    vector<vector<int>> Tgraph(n); // transpose of graph will be stored here
    for (int node = 0; node < n; node++)
    {
        for (auto &child : graph[node])
        {
            Tgraph[child].push_back(node); // reversing the edges from child -> parent node
        }
    }
    return Tgraph;
}

// simple DFS
void DFS(int vertex, vector<vector<int>> &graph, vector<bool> &vis, vector<int> &temp)
{
    if (vis[vertex])
        return;
    temp.push_back(vertex);
    vis[vertex] = true;
    for (auto &child : graph[vertex])
    {
        DFS(child, graph, vis, temp);
    }
}
// finding the strongly connected components
vector<vector<int>> kosarajusAlgo(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> vis(n, false);
    // step 1
    stack<int> topoStack; // here the nodes are in order of their finishing time i.e topological ordering
    DFS_TopoSort(0, graph, vis, topoStack);

    // step 2
    vector<vector<int>> Tgraph = TransposeGraph(graph);

    // step 3 -> call Dfs accroding to the TopoSort stack[finishing time ordering] of the nodes
    fill(vis.begin(), vis.end(), false); // resetting the visited array for further use. using fill function
    vector<vector<int>> ans;             // all strongly components will be stored here in respective groups
    while (!topoStack.empty())
    {
        int node = topoStack.top();
        topoStack.pop();
        vector<int> temp;
        DFS(node, Tgraph, vis, temp);
        if (temp.size() > 0)
            ans.push_back(temp);
    }
    return ans;
}

int main()
{
    int n, e;
    cout << "Enter no. of nodes and edges:";
    cin >> n >> e;
    vector<vector<int>> graph(n);
    cout << "Enter all edges :\n";
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    vector<vector<int>> ans = kosarajusAlgo(graph);
    // printing all strongly connected components
    cout << "\nStrongly Connected components are :\n";
    for (auto &component : ans)
    {
        for (auto &el : component)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}