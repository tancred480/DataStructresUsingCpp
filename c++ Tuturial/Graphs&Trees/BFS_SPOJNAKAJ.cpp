#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*shortest path
As we know in BFS node which are lesser level are accesed and levels mean what distance

*/
const int INF = 1e9 + 10;
int level[10010][10010] = {INF};
vector<pair<int, int>> moves = {{-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}, {2, -1}, {2, 1}, {1, 2}, {1, -2}};

bool valid(vector<vector<int>> chessboard, int x, int y)
{
    int r = chessboard.size(), c = chessboard[0].size();
    if (x < 0 || y < 0 || x >= r || y >= c)
        return false;
    return true;
}
int findShortPath(vector<vector<int>> chessboard, pair<int, int> src, pair<int, int> dest)
{
    // knight moves
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(chessboard.size(), vector<bool>(chessboard[0].size(), false));
    int dist = 0;
    q.push(src);
    visited[src.first][src.second] = true;
    level[src.first][src.second] = 0;
    while (!q.empty())
    {
        int n = q.size();
        dist++; // here shortest distance is nothing but just levels
        for (int i = 0; i < n; i++)
        {
            pair<int, int> nextnode = q.front();
            q.pop();
            int x = nextnode.first, y = nextnode.second;
            if (x == dest.first && y == dest.second)
                return dist;
            for (auto &move : moves)
            {
                int a = x + move.first, b = y + move.second;
                if (valid(chessboard, a, b) && !visited[a][b])
                {
                    visited[a][b] = true;
                    level[a][b] = level[x][y] + 1; // level child will parentLevel + 1;->this 2D array stores levels of each node from given root vertex
                    q.push({a, b});
                }
            }
        }
    }
    return -1; // if no possible way then return -1;
}
int main()
{

    return 0;
}