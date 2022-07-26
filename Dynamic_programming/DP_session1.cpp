#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
/*
 in 1D problems
 How to understand that this is a Dp problem
 -whenever it is given
    -count the total no. of ways
-concept of try all possible ways comes up.
-figureout the bestway

--Short trick
-Try to represent the problem in the terms of indexes
-Do all possible stuffs on that index as per the given problem statement
-Sum of all stuffs -> count all ways
-min(of all stuffs) ->find min

---standard set of problems---
->Coin Change
->Edit distance
->Rod cutting
->Longest Increasing Subsequence
->Knapsack problems
->subset problems
->Longest Common Subsequence/substring
The main approach of the dynamic problems is to minimize the time.

conversation of time-complexity after applying DP
O(2^n) --> O(N)
O(2^y) --> O(N)
O(N!) --> O(2^N)
*/
const int N = 1e5 + 10;
// 0 1 1 2 3 5 8 13 21
// 0 1 2 3 4 5 6 7  8
int dp[N];
// Top Down Approach--genearlly recursion gets into used
int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    if (dp[n] != -1) // memoization
        return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
}
// Bottom up Approach
int fib2(int n)
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout << fib(8);
    return 0;
}