#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// coin Change 1---------dp
int dp[10010];
int coinSum(int amount, vector<int> &coins)
{
    if (amount == 0)
        return 0;
    if (dp[amount] != -1)
        return dp[amount];
    int ways = INT_MAX;
    for (int coin : coins)
    {
        if (amount - coin >= 0)
        {
            ways = min(ways + 0LL, coinSum(amount - coin, coins) + 1LL);
        }
    }
    return dp[amount] = ways;
}
int coinChange(vector<int> &coins, int amount)
{
    memset(dp, -1, sizeof(dp));
    int ans = coinSum(amount, coins);
    return ans == INT_MAX ? -1 : ans;
}
//-------------------------
