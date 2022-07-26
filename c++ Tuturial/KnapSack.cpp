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
long long dp[105][100005]; // since two states are changing therefore 2D DP apply karra hun.
// the two changing states here is 1.index and 2.capacity at each recursion thats why 2D DP.
long long robbe(int index, int capacity, vector<pair<int, int>> sack)
{
    if (capacity == 0 || index < 0) // base case says if bag capacity becomes 0 that means now we can robbe 0 value things from house.
        return 0;

    // or if index doesnt left means we have space but no items to to robbe there max robbe that can be made is 0.
    if (dp[index][capacity] != -1) // if max amount of robbery from that index[item] and that left capacity is already calculated dont calculated it again just return from our 2D DP.
        return dp[index][capacity];
    long long taken_sum = robbe(index - 1, capacity, sack); // if we dont take that item in the bag.
    if (capacity - sack[index].first >= 0)                  // if we take that item in the bag
    {
        taken_sum = max(taken_sum, robbe(index - 1, capacity - sack[index].first, sack) + sack[index].second);
    }
    return dp[index][capacity] = taken_sum;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> sack(n);
    for (auto &el : sack)
        cin >> el.first >> el.second;
    long long ans = robbe(n - 1, c, sack);
    cout << "Answer: " << ans << endl;
    return 0;
}

// long long dp[105][100005];

// long long robbe(int index, int capacity, vector<pair<int, int>> sack)
// {
//     if (capacity == 0 || index < 0)
//         return 0;
//     if (dp[index][capacity] != -1)
//         return dp[index][capacity];
//     long long ans = robbe(index - 1, capacity, sack);
//     if (capacity - sack[index].first >= 0)
//     {
//         ans = max(ans, robbe(index - 1, capacity - sack[index].first, sack) + sack[index].second);
//     }
//     return dp[index][capacity] = ans;
// }
// int main()
// {
//     memset(dp, -1, sizeof(dp));
//     int n, c;
//     cin >> n >> c;
//     vector<pair<int, int>> sack(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> sack[i].first >> sack[i].second;
//     }
//     cout << robbe(n - 1, c, sack) << endl;
// }