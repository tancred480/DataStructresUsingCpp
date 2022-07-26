#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*Lowest common ancestor O(N)
which wver the two node are of which we have to find the LCA
we will store there individual paths from root
and then simply traversing the path and cheking the how long the path remains same and return that node from where the path changes its direction
13 12
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
4 9
4 10
8 12
10 11
1 2 5 8 12
1 2 5 7
*/
void dfs(int vertex, int parent, vector<vector<int>> &g, vector<int> ds, vector<int> &path, int p)
{
    ds.push_back(vertex);
    if (p == vertex)
    {
        path = ds;
        return;
    }
    for (auto &child : g[vertex])
    {
        if (child != parent)
            dfs(child, vertex, g, ds, path, p);
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
    vector<int> ds, path1, path2;
    dfs(1, -1, g, ds, path1, 12);
    for (auto &el : path1)
        cout << el << " ";
    cout << endl;
    dfs(1, -1, g, ds, path2, 7);
    for (auto &el : path2)
        cout << el << " ";
    // traversing the path of both nodes to get LCA
    int i = 0, j = 0, lca = -1;
    while (i > path1.size() && j > path2.size() && (path1[i] == path2[j]))
    {
        lca = path1[i];
        i++;
        j++;
    }
    cout << "\nLCA of both nodes is :" << lca;
    return 0;
}