#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[205][10010]; // two states of DP index and sum
    bool targetSum(int ind, int sum, vector<int> &nums)
    {
        if (sum == 0)
            return true; // if at any point of recurssion sum becomes=0 then return true
        if (ind < 0)
            return false;
        if (dp[ind][sum] != -1)
            return dp[ind][sum];
        bool isPossible = targetSum(ind - 1, sum, nums); // if not including ith element
        if (sum - nums[ind] >= 0)
        {
            isPossible = isPossible | targetSum(ind - 1, sum - nums[ind], nums); // if any one of them gives true as answer return true
        }
        return dp[ind][sum] = isPossible;
    }
    bool canPartition(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false; // if sum comes to Odd then you will never do partition in two halves
        sum = sum / 2;    // else we have to find if we can get total_sum/2 ->which turns to a problem of targetsum in array now

        return targetSum(nums.size() - 1, sum, nums);
    }
};