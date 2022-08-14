#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int parent[N];
void make(int v)
{
    parent[v] = v;
}
int find(int v)
{
    if (v == parent[v])
        return v;
    return find(parent[v]);
}
void Union(int a, int b)
{
    int ar = find(a), br = find(b); // find the root of a and b so as to join there root for union
    if (ar != br)
    { // if both are from differnt component
        parent[br] = ar;
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
            temp.push_back(parent[i]);
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