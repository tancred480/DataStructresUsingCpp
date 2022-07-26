#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];
vector<int> dist(N, INF);
vector<bool> vis(N, false);
vector<int> ways(N, 0);

void dijkstra(int source)
{
    int mod = 1e9 + 7;
    set<pair<int, int>> pq; //{shortest_distance,to_node}
    pq.insert({0, source});
    dist[source] = 0;
    ways[source] = 1;
    while (!pq.empty())
    {
        pair<int, int> node = *pq.begin(); // poping out node with least distance
        pq.erase(pq.begin());
        int vertex = node.second, short_dist = node.first; // till yet short distance of a particular node
        if (vis[vertex] == true)
            continue;
        vis[vertex] = true;
        for (pair<int, int> child : g[vertex])
        {
            int child_v = child.first, child_short_dist = child.second;

            if ((dist[vertex] + child_short_dist) < dist[child_v])
            {
                dist[child_v] = dist[vertex] + child_short_dist;
                ways[child_v] = ways[vertex];
                pq.insert({dist[child_v], child_v});
            }
            else if ((dist[vertex] + child_short_dist) == dist[child_v])
            {
                ways[child_v] = (ways[child_v] + ways[vertex]) % mod;
            }
        }
    }
}
// Leetcode Question
// number of ways to reach the destination with shortest time
int countPaths(int n, vector<vector<int>> &roads)
{
    int e = roads.size(); // total edges in the graph
    for (int i = 0; i < e; i++)
    {
        int x, y, wt;
        x = roads[i][0], y = roads[i][1], wt = roads[i][2];
        g[x].push_back({y, wt});
        g[y].push_back({x, wt});
    }
    dijkstra(0);
    return ways[n - 1];
}
int maxOperations(vector<int> &nums, int k)
{
    int cnt = 0, flag = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << "size :" << nums.size() << endl;
        for (auto &el : nums)
            cout << el << " ";
        cout << endl;
        if (flag == 1)
        {
            i = 0;
            flag = 0;
        }
        for (int j = i + 1; j < nums.size(); j++)
        {
            if ((nums[i] + nums[j]) == k)
            {
                // cout << nums[i] << " " << nums[j] << "\n";
                nums.erase(nums.begin() + i);
                nums.erase(nums.begin() + (j - 1));
                cnt++;
                i = 0;
                flag = 1;
                break;
            }
        }
    }
    return cnt;
}
int main()
{
    // vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    // int ans = countPaths(7, roads);
    // for (int i = 0; i < 7; i++)
    // {
    //     cout << i << ":" << ways[i] << " " << dist[i] << " \n";
    // }
    vector<int> v = {1, 2, 3, 4};
    cout << maxOperations(v, 5) << endl;
}