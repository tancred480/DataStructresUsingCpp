#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// is Graph bipartite using two coloring technique with dfs
// void dfs(int vertex, vector<int> &vis, vector<string> &color, vector<int> adj[], int &ans)
// {
//     if (vis[vertex])
//         return;
//     vis[vertex] = true;
//     if (color[vertex] == "no-color")
//         color[vertex] = "green";
//     for (auto child : adj[vertex])
//     {
//         if (color[child] != "no-color" && color[child] == color[vertex])
//         {
//             ans = 0; // means not bipartite
//             return;
//         }
//         else if (color[vertex] == "blue")
//         {
//             color[child] = "green";
//         }
//         else
//         {
//             color[child] = "blue";
//         }
//     }
//     for (auto child : adj[vertex])
//     {
//         dfs(child, vis, color, adj, ans);
//     }
// }
void dfs(vector<vector<int>> &image, int x, int y, int rows, int cols, int newColor, int oldColor)
{
    if (x < 0 || x >= rows || y < 0 || y >= cols || image[x][y] == newColor || image[x][y] != oldColor)
        return;
    image[x][y] = newColor;
    dfs(image, x - 1, y, rows, cols, newColor, oldColor);
    dfs(image, x + 1, y, rows, cols, newColor, oldColor);
    dfs(image, x, y + 1, rows, cols, newColor, oldColor);
    dfs(image, x, y - 1, rows, cols, newColor, oldColor);
}
void floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int rows = image.size();
    int cols = image[0].size();
    dfs(image, sr, sc, rows, cols, newColor, image[sr][sc]);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> image = {{0, 0, 0}, {0, 1, 1}};
    floodFill(image, 1, 1, 1);
    return 0;
}