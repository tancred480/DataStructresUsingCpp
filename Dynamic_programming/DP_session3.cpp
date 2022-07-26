#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
const int N = 25e2 + 10;
vector<int> a(N);
// Question
// Longest increasing subsequence[order of numbers will not change]
int biggestLength = 1;
void lis(int index, vector<int> nums, vector<int> ds)
{
    if (index < 0)
        return;
    ds.push_back(nums[index]);
    for (int i = index - 1; i >= 0; i--)
    {
        if (nums[index] >= nums[i]) // for strictly increaing it will be nums[index]>nums[i]
        {
            lis(i, nums, ds);
        }
    }
    for (auto &el : ds)
        cout << el << " ";
    cout << endl;
    int l = ds.size();
    biggestLength = max(biggestLength, l);
}
void printAllLIS(vector<int> v)
{
    int n = v.size();
    vector<int> ds;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        lis(i, v, ds);
    }
    cout << "Maximum Length Increasing SubSequence :" << biggestLength << "\n";
}
//---------------------
// just to get Length
int lis2(int index, vector<int> nums)
{
    if (index == 0)
        return 1;
    int biggest = 1;
    for (int j = index; j >= 0; j--)
    {
        if (nums[index] > nums[j])
        {
            biggest = max(biggest, lis2(j, nums) + 1);
        }
    }
    return biggest;
}
int main()
{
    vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
    // printAllLIS(v);
    cout << lis2(v.size() - 1, v);
    return 0;
}