#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// distinctive integer-given
void CombinationSum1(int ind, vector<int> arr, vector<int> ds, int target, int n)
{
    if (ind == n)
    {
        if (target == 0)
        {
            for (auto &el : ds)
                cout << el << " ";
            cout << endl;
        }
    }
    if (arr[ind] <= target) // cheking if we ca n take the same index again or not for combination
    {
        ds.push_back(arr[ind]);
        CombinationSum1(ind, arr, ds, target - arr[ind], n);
        ds.pop_back(); // while backtraking remove the element added to the data-structure
    }
    CombinationSum1(ind + 1, arr, ds, target, n); // not taking the same index
}
// Combination Sum II with duplicates ----------------------------
vector<vector<int>> res;
void getComb(int ind, vector<int> arr, vector<int> ds, int target, int n)
{
    if (target == 0)
    {
        res.push_back(ds);
        return;
    }
    for (int i = ind; i < n; i++)
    {
        if (i > ind && arr[i] == arr[i - 1]) // cheking also if its not the first index
            continue;                        // if current element is same as the previous then dont call further for it will give same result redundent task
        if (target < arr[i])
            break; // if ever elements becomed greater than target element then break because further element would also be greater as the array is sorted.
        ds.push_back(arr[i]);
        getComb(i + 1, arr, ds, target - arr[i], n);
        ds.pop_back(); // remove element after calling the recursion neccessary step to get unique answers
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    int n = candidates.size();
    vector<int> ds;
    getComb(0, candidates, ds, target, n);
    return res;
}

//--------------------------
int main()
{

    return 0;
}