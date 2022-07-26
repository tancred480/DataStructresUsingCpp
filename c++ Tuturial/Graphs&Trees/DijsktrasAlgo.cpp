#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Dijkstras Algorithms which is for weighted graphs
const int N = 1e5 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N]; // gr 0 -> 1(4) it means 0 is connected to 1 by weight of 4
vector<int> dist(N, INF);    // initializing all nodes with infinity as theid
vector<bool> vis(N, false);

void dijkstra(int source)
{
    set<pair<int, int>> pq; // this will be our priority queue such that front node will be that node which has the lowest distance automaitcally as its a set
    // {dist , node} 👆 ->as we want to get the lowest distance node for further optimal solution

    pq.insert({0, source}); // setting source distance from source to 0 initially
    dist[source] = 0;
    while (pq.size() > 0)
    {
        pair<int, int> node = *pq.begin(); // poping out node with least distance
        pq.erase(pq.begin());
        int vertex = node.second, distance = node.first;

        if (vis[vertex])
            continue;
        vis[vertex] = true;
        for (auto child : g[vertex])
        {
            int child_v = child.first, child_dist = child.second;
            if ((dist[vertex] + child_dist) < dist[child_v]) // (parent_node_dist + child_node_dist < curr_child_node_dist)
            {
                dist[child_v] = (dist[vertex] + child_dist);
                pq.insert({dist[child_v], child_v});
            }
        }
    }
}
int main()
{
    int n, e; // nodes and edges
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        // 2 connected nodes with some weights
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << " : " << dist[i] << "\n";
    }
    return 0;
}

/*
//coding  ninjas question
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<pair<int,int>>> graph(vertices);
    for(int i=0;i<edges;i++){
        int x = vec[i][0],y = vec[i][1],wt = vec[i][2];
        graph[x].push_back({y,wt});
        graph[y].push_back({x,wt});
    }
    vector<bool> vis(vertices,false);
    vector<int> dist(vertices,1e18);
    set<pair<int,int>> pq;
    pq.insert({0,source});
    dist[source] = 0;
    while(!pq.empty()){
        auto node = *pq.begin();
        pq.erase(pq.begin());
        if(vis[node.second]) continue;
        vis[node.second] = true;
        for(auto child : graph[node.second]){
            int child_v = child.first,child_d = child.second;
            if((dist[node.second]+child_d) < dist[child_v]){
                dist[child_v] = dist[node.second]+child_d;
                pq.insert({dist[child_v],child_v});
            }
        }
    }
    return dist;

}
*/