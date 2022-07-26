#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

void BFS_Traversal(int vertex)
{
    queue<int> q;
    q.push(vertex);
    vis[vertex] = true;
    while (!q.empty())
    {
        int child_v = q.front();
        cout << child_v << " ";
        q.pop();
        for (auto node : g[child_v])
        {
            if (!vis[node])
            {
                vis[node] = true;
                q.push(node);
            }
        }
    }
}
void DFS_Traversal(int vertex)
{
    if (vis[vertex])
        return;
    vis[vertex] = true;
    cout << vertex << " ";
    for (auto v : g[vertex])
    {
        DFS_Traversal(v);
    }
}
// DFS implementation using stack
void dfs(int vertex)
{
    stack<int> st;
    st.push(vertex);
    vis[vertex] = true;
    while (!st.empty())
    {
        int x = st.top();
        cout << x << " ";
        st.pop();
        if (!vis[x])
        {
            vis[x] = true;
        }
        for (auto child_v : g[x])
        {
            if (!vis[child_v])
                st.push(child_v);
        }
    }
}
// for one directional tree no need for visited array
void dfs2(int vertex)
{
    stack<int> st;
    st.push(vertex);
    while (!st.empty())
    {
        int x = st.top();
        cout << x << " ";
        st.pop();
        for (auto child_v : g[x])
        {
            st.push(child_v);
        }
    }
}

int main()
{
    // taking input of graph
    int n, e;
    cout << "\nEnter no of nodes and edges : ";
    cin >> n >> e;
    cout << "\nEnter All edges : ";
    for (int i = 0; i < e; i++)
    { // bidirectional /undirectional graph
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int x;
    cout << "enter start node :";
    cin >> x;
    BFS_Traversal(x);
    cout << endl;
    // as visited array is global
    // for (int i = 0; i < 15; i++)
    // {
    //     vis[i] = false;
    // }
    // DFS_Traversal(x);
    // dfs2(5); //for unidirectional graph
    return 0;
}

vector<pair<int, int>> directions = {{-1, 1}, {1, -1}, {-1, -1}, {1, 1}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int r = grid.size(), c = grid[0].size(), short_dist = INT_MAX;
    if (grid[0][0] == 1 || grid[r - 1][c - 1] == 1)
        return -1;
    queue<pair<pair<int, int>, int>> q;
    set<pair<int, int>> st;

    q.push({{0, 0}, 1});
    st.insert({0, 0});
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        int dist = node.second;
        if (node.first.first == r - 1 && node.first.second == c - 1)
        {
            short_dist = min(short_dist, dist);
        }
        for (auto &el : directions)
        {
            int x = node.first.first + el.first, y = node.first.second + el.second;
            if (x >= 0 && x < r && y >= 0 && y < c && st.count({x, y}) == 0 && grid[x][y] == 0)
            {
                q.push({{x, y}, dist + 1});
                st.insert({x, y});
            }
        }
    }
    return short_dist == INT_MAX ? -1 : short_dist;
}