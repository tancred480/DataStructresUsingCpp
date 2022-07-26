#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
int parent[N];
int size[N];
void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}
int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]); // path compression
}
void Union(int a, int b)
{
    int ar = find(a), br = find(b); // find the root of a and b so as to join there root for union
    if (ar != br)
    {                            // if both are from differnt component
        if (size[ar] < size[br]) // union by size O(alpha(n))-> amotorized time complexity
            swap(ar, br);
        parent[br] = ar;
        size[ar] += size[br];
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    // find distinct connected component
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    int connected_ct = 0;
    // here we just have to calculate number of roots
    for (int v = 1; v <= n; v++)
    {
        if (find(v) == v)
            connected_ct++;
    }
    return 0;
}