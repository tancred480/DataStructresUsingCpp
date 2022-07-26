#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
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

    return 0;
}