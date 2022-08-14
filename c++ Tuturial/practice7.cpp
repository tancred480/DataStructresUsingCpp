#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dsu[10000];
void make(int v)
{
    dsu[v] = v;
}
int find(int v)
{
    while (dsu[v] != v)
    { // finding the root of vertex v
        v = dsu[v];
    }
    return v;
}
void Union(int v1, int v2)
{
    if (find(v1) != find(v2))
    {
        dsu[v1] = v2;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> res;
    for (int i = 0; i <= n; i++)
        make(i);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        vector<int> temp;
        for (int i = 0; i <= n; i++)
            temp.push_back(dsu[i]);
        res.push_back(temp);
        Union(u, v);
    }
    for (auto &arr : res)
    {
        for (auto &el : arr)
        {
            cout << el << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
        cout << i << " ";
    return 0;
}