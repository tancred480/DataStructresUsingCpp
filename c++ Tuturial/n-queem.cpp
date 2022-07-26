#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> ans;
    bool checkValid(int x, int y, int r, int c, vector<vector<char>> &chessboard)
    {
        for (int i = y; i < c; i++)
        { // staright right check
            if (chessboard[x][i] == 'Q')
                return false;
        }
        for (int i = y; i >= 0; i--)
        { // staright left check
            if (chessboard[x][i] == 'Q')
                return false;
        }
        for (int i = x; i < r; i++)
        { // staright downward check
            if (chessboard[i][y] == 'Q')
                return false;
        }
        for (int i = x; i >= 0; i--)
        { // staright upward check
            if (chessboard[i][y] == 'Q')
                return false;
        }
        for (int i = x, j = y; i < r and j < c; i++, j++)
        { // l-r downward digonal check
            if (chessboard[i][j] == 'Q')
                return false;
        }
        for (int i = x, j = y; i >= 0 and j < c; i--, j++)
        { // l-r upward digonal check
            if (chessboard[i][j] == 'Q')
                return false;
        }
        for (int i = x, j = y; i >= 0 and j >= 0; i--, j--)
        { // r-l upward digonal check
            if (chessboard[i][j] == 'Q')
                return false;
        }
        for (int i = x, j = y; i < r and j >= 0; i++, j--)
        { // r-l downward digonal check
            if (chessboard[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void dfs(int x, int y, vector<vector<char>> &chessboard)
    {
        int r = chessboard.size(), c = chessboard[0].size();
        if (x >= r)
        {
            vector<string> answer_string;
            for (auto &el : chessboard)
            {
                string s = "";
                for (auto &val : el)
                {
                    cout << val << " ";
                    s += val;
                }
                cout << endl;
                answer_string.push_back(s);
            }
            ans.push_back(answer_string);
            cout << endl;
            return;
        }
        for (int i = 0; i < r; i++)
        {
            if (checkValid(x, i, r, c, chessboard))
            {
                chessboard[x][i] = 'Q';
                dfs(x + 1, 0, chessboard);
                chessboard[x][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<char>> chessboard(n, vector<char>(n));
        for (auto &el : chessboard)
            for (auto &val : el)
                val = '.';
        dfs(0, 0, chessboard);

        return ans;
    }
};