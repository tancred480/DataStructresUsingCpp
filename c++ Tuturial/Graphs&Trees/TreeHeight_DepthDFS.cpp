#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Height of Tree
// calculating Height of Tree and Depth of tree using DFS
int depth[100010], height[100010];
// no need of visited as its a tree just check for parents
void dfs(int vertex, int parent, vector<vector<int>> g)
{
    for (auto child : g[vertex])
    {
        if (child != parent)
        {
            depth[child] = depth[vertex] + 1;
            dfs(child, vertex, g);
            height[vertex] = max(height[child] + 1, height[vertex]);
        }
    }
}
int main()
{
    int n;
    cin >> n; // since in a tree there are n-1 edges
    vector<vector<int>> g;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cout<<"Height of Each node: ->"<<endl;
    return 0;
}


/*
Minimum height of Tree
class Solution {
public:
    void dfs(int vertex,int parent,vector<vector<int>>& Tree,vector<int>& height){
        for(auto &child:Tree[vertex]){
            if(child!=parent){
                dfs(child,vertex,Tree,height);
                height[vertex] = max(height[child]+1,height[vertex]);
            }
        }
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> Tree(n);
        vector<int> minheights,height(n,0);
        int smallestHeight = INT_MAX;
        for(auto &edge:edges){
            int x = edge[0],y = edge[1];
            Tree[x].push_back(y);
            Tree[y].push_back(x);
        }
        for(int i=0;i<n;i++){
            dfs(i,-1,Tree,height);
            if(smallestHeight > height[i]){
                smallestHeight = height[i];
                minheights.clear();
                minheights.push_back(i);
            }else if(smallestHeight==height[i]){
                minheights.push_back(i);
            }
            fill(height.begin(),height.end(),0);
        }
        return minheights;
    }
};
*/