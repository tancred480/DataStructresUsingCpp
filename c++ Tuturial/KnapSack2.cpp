#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// 01 knapsack problem
/*There are N items,numbers 1,2,..,N. For each i(1<=i<=N), item i
has a weight of wi and a value of vi.
Taro has decided to choose some of the N items and carry them to
home in a knapsack. The capacity of the knapsack is W, which means that the
weight of the items taken must be atmost W.
Find the maximum possible sum of the value Taro takes home.
*/
int wt[105], val[105];
long long dp[105][100005];

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    // cout << func(n - 1, w) << endl;
}