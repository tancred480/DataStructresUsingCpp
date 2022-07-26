#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(vector<vector<char>> &board, int x, int y, char c)
{
    // checking horizontally
    for (int i = 0; i < 9; i++)
    {
        if (board[x][i] == c)
            return false;
    }
    // cheking vertically
    for (int i = 0; i < 9; i++)
    {
        if (board[i][y] == c)
            return false;
    }
    // checking sub-grid
    int p = 3 * (x / 3), q = 3 * (y / 3);
    for (int i = p; i < p + 3; i++)
    {
        for (int j = q; j < q + 3; j++)
        {
            if (board[i][j] == c)
                return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (int p = 0; p < 9; p++)
    {
        for (int q = 0; q < 9; q++)
        {
            if (board[p][q] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (check(board, p, q, c))
                    {
                        board[p][q] = c;
                        if (solve(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[p][q] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main()
{
    return 0;
}