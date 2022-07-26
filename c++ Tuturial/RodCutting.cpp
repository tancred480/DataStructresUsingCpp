#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dp[100010];
int cut(int price[], int RodLen, int n)
{
    if (RodLen == 0)
        return 0;
    if (dp[RodLen] != -1)
        return dp[RodLen];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (RodLen - i >= 0)
            ans = max(ans, cut(price, RodLen - i, n) + price[i - 1]);
    }
    return dp[RodLen] = ans;
}
int cutRod(int price[], int n)
{
    int ans = cut(price, n, n);
    return ans;
}

int main()
{
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = (int)sizeof(price) / sizeof(price[0]);
    // cout << cutRod(price, n);
    cout << -1 % 7;
    return 0;
}