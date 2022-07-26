#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

/*FROG 1
There are N stones ,numbered 1,2,...N .For each (1<=i<=N), the height of stones is hi.
There is a frog who is initially on stone 1.He will repeat the following action
some number of times to reach stone N:
    -If the frog is currently on stone i,jump to stone i+1 or stone i+2.
    Here a cost of |hi-hj| is incurred ,where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches stone N.
*/
const int N = 1e5 + 10;
int dp[N];
int minCost(int i, vector<int> &arr)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int cost = INT_MAX;
    cost = min(cost, (minCost(i - 1, arr) + std::abs(arr[i] - arr[i - 1])));
    if (i > 1)
        cost = min(cost, minCost(i - 2, arr) + std::abs(arr[i] - arr[i - 2]));
    return dp[i] = cost;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &el : arr)
        cin >> el;
    int minimum_cost = minCost(n - 1, arr);
    cout << minimum_cost << endl;
    return 0;
}