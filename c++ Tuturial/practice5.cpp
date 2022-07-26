#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
int chessboard[N][N];
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
    // vector<vector<int>> chessboard(n, vector<int>(n));
    int count = 0;
    r_q--;
    c_q--;
    chessboard[r_q][c_q] = 1;
    for (int i = 0; i < k; i++)
    {
        int x = obstacles[i][0], y = obstacles[i][1];
        chessboard[x - 1][y - 1] = -1;
    }
    // for (auto &el : chessboard)
    // {
    //     for (auto &val : el)
    //         cout << val << " ";
    //     cout << endl;
    // // }

    for (int i = r_q, j = c_q; i >= 0 && j < n; i--, j++)
    { // l-r upward diagonal
        if ((i != r_q && j != c_q) && chessboard[i][j] != -1)
            count++;
        else if (chessboard[i][j] == -1)
            break;
    }
    // cout << "\ncount l-r-u:" << count;
    for (int i = r_q, j = c_q; i < n && j >= 0; i++, j--)
    { // r-l downward diagonal
        if ((i != r_q && j != c_q) && chessboard[i][j] != -1)
            count++;
        else if (chessboard[i][j] == -1)
            break;
    }
    // cout << "\ncount : r-l-d" << count;
    for (int i = r_q, j = c_q; i >= 0 && j >= 0; i--, j--)
    { // r-l upward diagonal
        if ((i != r_q && j != c_q) && chessboard[i][j] != -1)
            count++;
        else if (chessboard[i][j] == -1)
            break;
    }
    // cout << "\ncount :r-l-u" << count;
    for (int i = r_q, j = c_q; i < n && j < n; i++, j++)
    { // l-r downward diagonal
        if ((i != r_q && j != c_q) && chessboard[i][j] != -1)
            count++;
        else if (chessboard[i][j] == -1)
            break;
    }
    // cout << "\ncount : l-r-d" << count;
    for (int i = r_q; i >= 0; i--)
    { // vertical-upward check
        if ((i != r_q) && chessboard[i][c_q] != -1)
            count++;
        else if (chessboard[i][c_q] == -1)
            break;
    }
    for (int i = r_q; i < n; i++)
    { // vertical-downward check
        if ((i != r_q) && chessboard[i][c_q] != -1)
            count++;
        else if (chessboard[i][c_q] == -1)
            break;
    }
    // cout << "\ncount :v" << count;
    for (int i = c_q; i >= 0; i--)
    { // horizontal-left check
        if ((i != c_q) && chessboard[r_q][i] != -1)
            count++;
        else if (chessboard[r_q][i] == -1)
            break;
    }
    for (int i = c_q; i < n; i++)
    { // horizontal-right check
        if ((i != c_q) && chessboard[r_q][i] != -1)
            count++;
        else if (chessboard[r_q][i] == -1)
            break;
    }
    // cout << "\ncount :h" << count;
    return count;
}
// flood fill question approach using BFS
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    vector<pair<int, int>> v = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    set<pair<int, int>> st;
    int row = image.size(), cols = image[0].size();
    list<pair<int, int>> qu;
    qu.push_back({sr, sc});
    st.insert({sr, sc}); // this will work as our visited array;
    while (!qu.empty())
    {
        pair<int, int> box = qu.front();
        qu.pop_front();
        int x = box.first, y = box.second;
        int startpixel = image[x][y];
        image[x][y] = newColor;
        for (pair<int, int> neigbour : v)
        {
            int p = x + neigbour.first, q = y + neigbour.second;
            if (p >= 0 && p < row && q >= 0 && q < cols && (image[p][q] == startpixel) && (!st.count({p, q})))
            {
                qu.push_back({p, q});
                st.insert({p, q});
            }
        }
    }
    return image;
}
// flood fill approach using dfs
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
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int rows = image.size();
    int cols = image[0].size();
    dfs(image, sr, sc, rows, cols, newColor, image[sr][sc]);
    return image;
}
////////////////////////////////////////
int main()
{
    int n, k, x, y;
    cin >> n >> k;
    cin >> x >> y;
    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++)
    {
        obstacles[i].resize(2);
        for (auto &el : obstacles[i])
            cin >> el;
    }
    int count = queensAttack(n, k, x, y, obstacles);
    cout << "\ncount :" << count;
    return 0;
}