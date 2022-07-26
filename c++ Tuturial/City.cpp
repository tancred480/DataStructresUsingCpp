#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// // n-queen problem
// bool isSafe(int **arr, int x, int y, int n)
// {
//     // cheking vertically
//     for (int row = 0; row < x; row++)
//     {
//         if (arr[row][y] == 1)
//             return false;
//     }
//     // checking horizontally
//     for (int col = x; col < n; col++)
//     {
//         if (arr[x][col] == 1)
//             return false;
//     }
//     // checking diagonal of r-l
//     int row = x, col = y;
//     while (row >= 0 && col < n)
//     {
//         if (arr[row][col] == 1)
//             return false;
//         row--;
//         col++;
//     }
//     // cheking diagonal of l-r
//     row = x, col = y;
//     while (row >= 0 && col >= 0)
//     {
//         if (arr[row][col] == 1)
//             return false;
//         row--;
//         col--;
//     }
//     return true;
// }
// void display(int **arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
// bool nQueen(int **arr, int x, int n)
// {
//     if (x >= n)
//     {
//         return true;
//     }
//     for (int col = 0; col < n; col++)
//     {
//         if (isSafe(arr, x, col, n))
//         {
//             arr[x][col] = 1;
//             if (nQueen(arr, x + 1, n))
//             {
//                 return true;
//             }
//             cout << endl;
//             arr[x][col] = 0; // backtracking
//         }
//     }
//     return false;
// };
// int main()
// {
//     int n;
//     cin >> n;
//     int **arr = new int *[n];
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = new int[n];
//         for (int j = 0; j < n; j++)
//         {
//             arr[i][j] = 0;
//         }
//     }
//     cout << endl;
//     if (nQueen(arr, 0, n))
//     {
//         display(arr, n);
//     }

//     return 0;
// }
bool isSafe(vector<string> &arr, int x, int y)
{
    int n = arr.size();
    for (int row = 0; row < n; row++)
    { // cheking vertically
        if (arr[row][y] == 'Q')
        {
            return false;
        }
    }
    for (int col = x; col < n; col++)
    { // checking horizontally
        if (arr[x][col] == 'Q')
        {
            return false;
        }
    }
    int row = x, col = y;
    while (row >= 0 && col < n)
    { // checking r-l diagonal -upper
        if (arr[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col++;
    }
    row = x, col = y;
    while (row < n && col >= 0)
    { // checking r-l diagonal -lower
        if (arr[row][col] == 'Q')
        {
            return false;
        }
        row++;
        col--;
    }
    row = x, col = y;
    while (row >= 0 && col >= 0)
    { // checking l-r diagonal
        if (arr[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }

    row = x, col = y;
    while (row < n && col < n)
    { // checking l-r diagonal
        if (arr[row][col] == 'Q')
        {
            return false;
        }
        row--;
        col--;
    }
    return true;
}

bool nQueen(vector<string> &arr, int x)
{
    if (x >= arr.size())
        return true;
    for (int col = 0; col < arr.size(); col++)
    {
        if (isSafe(arr, x, col))
        {
            arr[x][col] = 'Q';
            if (nQueen(arr, x + 1))
            {
                return true;
            }
            arr[x][col] = '.';
        }
    }
    return false;
}

void display(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void saveBoard(vector<string> &arr, vector<vector<string>> &ans)
{
    string row = "";
    vector<string> newBoard;
    for (int i = 0; i < arr.size(); i++)
    {
        row = "";
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i][j] == 'Q')
            {
                row += 'Q';
            }
            else
            {
                row += '.';
            }
        }
        newBoard.push_back(row);
    }
    ans.push_back(newBoard);
}

void nQueen2(vector<vector<string>> &ans, vector<string> &arr, int col)
{
    if (col == arr.size())
    {
        saveBoard(arr, ans);
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (isSafe(arr, i, col))
        {
            arr[i][col] = 'Q';
            nQueen2(ans, arr, col + 1);
            arr[i][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{ // main implementing function
    vector<vector<string>> ans;
    vector<string> arr1(n), arr2(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr1[i] += ".";
        }
    }
    nQueen2(ans, arr1, 0);
    for (auto &el1 : ans)
    {
        for (auto &el2 : el1)
        {
            cout << el2 << "\n";
        }
        cout << endl;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, i, cnt = 0;
        cin >> n >> x;
        vector<int> ans;
        i = 1;
        if ((n % 2) != 0)
            ans.push_back(x);
        while (ans.size() < n)
        {
            ans.push_back(x - i);
            ans.push_back(x + i);
            i++;
        }
        for (auto &el : ans)
            cout << el << " ";
        cout << endl;
    }

    return 0;
}