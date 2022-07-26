#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int getParent(vector<int> &v, int x)
{
    return v[x];
}
int getRoot(vector<int> &v, int x)
{
    int i = x;
    while (v[i] != x)
    {
        i = v[i];
        x = i;
    }
    return v[i]; // passing root;
}
vector<vector<int>> getAllConnectedComponents(vector<int> &v)
{
    vector<vector<int>> ans(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        int r = getRoot(v, i);
        ans[r].push_back(i);
    }
    cout << "\nAll Connected Components : \n";
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].size() > 0)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return ans;
}
int main()
{

    int n, e;
    cout << "Enter no. of nodes and edges :";
    cin >> n >> e;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
    cout << "\nEnter all edges :";
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        v[y] = x;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    // check if the vertices are connected
    // while (1)
    // {
    //     int x, y;
    //     cout << "\nenter the vertices to check if they are connected :";
    //     cin >> x >> y;
    //     if (getRoot(v, x) == getRoot(v, y))
    //     {
    //         cout << "YES" << endl;
    //     }
    //     else
    //     {
    //         cout << "NO" << endl;
    //     }
    // }

    // get All Connected Components in graph
    vector<vector<int>> ans = getAllConnectedComponents(v);
    // for (auto &el : ans)
    // {
    //     for (auto &val : el)
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}