#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// SubSet I ---------------------------No duplicates
vector<vector<int>> res;
void getSubSet(int ind, vector<int> arr, vector<int> ds, int n)
{
    if (ind >= n)
    {
        res.push_back(ds);
        return;
    }
    getSubSet(ind + 1, arr, ds, n);
    ds.push_back(arr[ind]);
    getSubSet(ind + 1, arr, ds, n);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ds;
    getSubSet(0, nums, ds, n);
    return res;
}
//--------------------------------------------
// Subset II ----------Contains duplicates-------
vector<vector<int>> res;
void getSubset(int ind, vector<int> nums, vector<int> ds, int n)
{
    res.push_back(ds);

    for (int i = ind; i < n; i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        getSubset(i + 1, nums, ds, n);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> ds;
    getSubset(0, nums, ds, n);
    return res;
}
//-------------------------
int main()
{
    return 0;
}