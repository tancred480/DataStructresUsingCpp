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
    return 0;
}