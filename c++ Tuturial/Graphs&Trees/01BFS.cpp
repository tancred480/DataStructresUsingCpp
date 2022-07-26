#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*shortest path using 0-1 BFS

Q) Given a directed graph we have to find how many minimum no. of
   edges needs to be reversed to reach to the destination node.

   To solve this problem we will simply add an extra reversed-edge by customely
   and then simply call the 0-1 BFS and then check how many 1's exists
   in the shortest path from source to destination and that will tell us how many nodes
   needs to be reversed in order to reach to the destination.

   At a certain time in our queue only two level node exist
*/
const int N = 1e5;
const int INF = 1e9 + 10;
vector<int> lev(N, INF);
void bfs(vector<vector<int>> &g, int src, int dest)
{
    vector<vector<pair<int, int>>> Rgraph(g.size()); // here we will give 0 weight for the existing edge and 1 weight to the every reversed edge
    // making the graph again with all reversed edge also.
    for (int x = 0; x < g.size(); x++)
    {
        for (int j = 0; j < g[x].size(); j++)
        {
            int y = g[x][j];
            if (x == y)
                continue;                // avoiding self loop
            Rgraph[x].push_back({y, 0}); // existing edge
            Rgraph[y].push_back({x, 1}); // reversed edge explicitly adding by us
        }
    }
    // if weight is 0 then push it from front and if weight is 1 then push it from back in queue
    deque<int> q; // it allows put from front and end
    q.push_back(src);
    lev[src] = 0;
    while (!q.empty())
    {
        auto node = q.front();
        q.pop_front();
        for (auto &child : Rgraph[node])
        {
            int child_v = child.first, wt = child.second;
            // checking the current node
            if (lev[node] + wt < lev[child_v])
            { // observation is a node can be put maximum two times
                lev[child_v] = lev[node] + 1;
                if (wt == 1)
                    q.push_back(child_v);
                else
                    q.push_front(child_v);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e; // since in a tree there are n-1 edges
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(g, 1, n);
    cout << lev[n - 1];
    return 0;
}