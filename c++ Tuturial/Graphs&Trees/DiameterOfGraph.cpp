#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
// maximum path is called as diameter of a tree
/*
Diameter means distance between two vertices
1.with any root find the max depth node
2.with that node as root find max depth and that will give u the diameter of a general tree

*/

// int mDept = INT_MIN;
// void MaxdepthNode(int vertex, int parent, vector<vector<int>> g, int d)
// {
//     if (mDept <= d)
//     {
//         mDept = d;
//         cout << vertex << " " << d << endl;
//     }
//     for (auto &child : g[vertex])
//     {
//         if (child != parent)
//         {
//             MaxdepthNode(child, vertex, g, d + 1);
//         }
//     }
// }
/*calculating depth of each node from the given node and then further getting the node whose having the longest depth so that we can use it for 2nd step*/
int depth[N];
void dfs(int vertex, int parent, vector<vector<int>> g)
{
    for (auto &child : g[vertex])
    {
        if (child != parent)
        {
            depth[child] = depth[vertex] + 1;
            dfs(child, vertex, g);
        }
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
    dfs(1, -1, g);
    // step1 finding the node having biggest depth
    int mDepthNode = 0, curr_dist = INT_MIN;
    for (int i = 1; i <= e; i++)
    {
        if (curr_dist <= depth[i])
        {
            curr_dist = depth[i];
            mDepthNode = i;
        }
        cout << i << ":" << depth[i] << endl;
    }
    // making the depth array clear so as to use it in step 2
    memset(depth, 0, sizeof(depth));
    // step :call the dfs again from the node that u have found in the above step
    dfs(mDepthNode, -1, g);
    int mDepthNode2 = 0, curr_dist2 = 0;
    for (int i = 1; i <= e; i++)
    {
        if (curr_dist <= depth[i])
        {
            curr_dist2 = depth[i];
            mDepthNode2 = i;
        }
        cout << i << ":" << depth[i] << endl;
    }
    cout << "Distance between " << mDepthNode << "<->" << mDepthNode2 << ":" << (curr_dist2);

    return 0;
}