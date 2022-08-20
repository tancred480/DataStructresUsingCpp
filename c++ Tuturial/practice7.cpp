#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dsu[10000];
void make(int v)
{
    dsu[v] = v;
}
int find(int v)
{
    while (dsu[v] != v)
    { // finding the root of vertex v
        v = dsu[v];
    }
    return v;
}
void Union(int v1, int v2)
{
    if (find(v1) != find(v2))
    {
        dsu[v1] = v2;
    }
}

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     vector<vector<int>> res;
//     for (int i = 0; i <= n; i++)
//         make(i);
//     for (int i = 0; i < e; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         vector<int> temp;
//         for (int i = 0; i <= n; i++)
//             temp.push_back(dsu[i]);
//         res.push_back(temp);
//         Union(u, v);
//     }
//     for (auto &arr : res)
//     {
//         for (auto &el : arr)
//         {
//             cout << el << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
//     for (int i = 0; i <= n; i++)
//         cout << i << " ";
//     return 0;
// }
const int M = 1e9 + 7;
int ds[1000000], dp[1000000];
int fibbo(int n)
{
    if (n == 0 || n == 1)
    {
        ds[n] = n;
        return dp[n] = n;
    }
    if (dp[n] != -1)
        return dp[n];
    dp[n] = (fibbo(n - 1) + fibbo(n - 2)) % M;
    ds[n] = (ds[n - 1] + dp[n]) % M;
    cout << ds[n] << " ";
    return dp[n];
}
int fibSum(int N)
{
    // code here
    fibbo(N);
    return ds[N];
}
// nums = {16,17,4,3,5,2}
vector<int> solve(vector<int> nums)
{
    vector<int> ans;
    int n = nums.size();
    ans.push_back(nums[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > nums[i + 1])
        {
            ans.push_back(nums[i]);
        }
        else
        {
            nums[i] = nums[i + 1];
        }
    }
    return ans;
}
int main()
{
    // memset(dp, -1, sizeof(dp));
    // cout << fibSum(7) << " ";
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &el : arr)
        cin >> el;
    vector<int> ans = solve(arr);
    for (auto &el : ans)
        cout << el << " ";

    return 0;
}