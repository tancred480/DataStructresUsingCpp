#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// method  1
vector<vector<int>> permute(vector<int> &nums)
{
    if (nums.size() <= 1)
        return {nums};
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); ++i)
    {
        vector<int> v(nums.begin(), nums.end());
        v.erase(v.begin() + i);
        auto res = permute(v);

        for (int j = 0; j < res.size(); ++j)
        {
            vector<int> _v = res[j];
            _v.insert(_v.begin(), nums[i]);
            result.push_back(_v);
        }
    }
    return result;
}

// method 2--using boolean array
void permutation(vector<int> nums, vector<int> ds, int n, vector<bool> taken)
{
    if (ds.size() == n)
    {
        for (auto &el : ds)
            cout << el << " ";
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!taken[i])
        {
            ds.push_back(nums[i]);
            taken[i] = true;
            permutation(nums, ds, n, taken);
            taken[i] = false;
            ds.pop_back();
        }
    }
}
// method - 3 --no extra space
void permutation2(int ind, vector<int> nums)
{
    if (ind == nums.size())
    {
        for (auto &el : nums)
            cout << el << " ";
        cout << endl;
        return;
    }
    for (int i = ind; i < nums.size(); i++)
    {
        swap(nums[ind], nums[i]);
        permutation2(ind + 1, nums);
        swap(nums[ind], nums[i]); // while backtracking again swap to get to original position for further permuation evaluation
    }
}
//-----Next Permutation-----
/*
step 1. a[i]<a[i+1] find the index where a[i]<a[i+1]; indx1
step 2. find the first index from backside where a[i]>a[indx1] ; indx2
step 3. swap(a[indx1] with a[indx2]);
step 4. reverse the array from index (indx1 + 1 to n-1);
*/
void nextPermutation(vector<int> nums)
{
    int n = nums.size(), indx1 = n - 2, indx2 = n - 1;
    while (indx1 >= 0 && nums[indx1] >= nums[indx1 + 1]) // step1
        indx1--;
    if (indx1 >= 0)
    {
        while (nums[indx2] <= nums[indx1]) // step2
            indx2--;
        swap(nums[indx1], nums[indx2]); // step3
    }
    reverse(nums.begin() + indx1 + 1, nums.end()); // step4
}
//-----------------Subsequence-------
/*
subsequence can be a contigious or non-contigious
*/
void subSeq(vector<int> nums, int i, vector<int> temp)
{
    if (i >= nums.size())
    {
        for (auto &el : temp)
            cout << el << " ";
        cout << endl;
        if (temp.size() == 0)
            cout << "{}" << endl;
        return;
    }

    // temp.push_back(nums[i]);
    // subSeq(nums, i + 1, temp);
    // temp.erase(temp.end() - 1);
    // subSeq(nums, i + 1, temp);
    subSeq(nums, i + 1, temp); // not selecting
    temp.push_back(nums[i]);
    subSeq(nums, i + 1, temp); // when selecting
    temp.pop_back();
}

// print the subsequence whose sum == target [all subSeq]
void targetSumSeq(int ind, vector<int> arr, vector<int> ds, int target, int sum)
{
    if (ind >= arr.size())
    {
        if (sum == target)
        {
            for (auto &el : ds)
                cout << el << " ";
            cout << endl;
        }
        return;
    }
    // pick condition
    ds.push_back(arr[ind]);
    sum += arr[ind];
    targetSumSeq(ind + 1, arr, ds, target, sum);
    // not pick condition
    ds.pop_back();
    sum -= arr[ind];
    targetSumSeq(ind + 1, arr, ds, target, sum);
}

// print the subsequence whose sum == target [just one subSeq]
/*
Technique to print only one answer
f(){
    base_case==true://condition satisfied
        return true;
    else return false;
}
*/
bool targetSumSeq2(int ind, vector<int> arr, vector<int> ds, int target, int sum)
{
    if (ind >= arr.size())
    {
        if (sum == target)
        {
            for (auto &el : ds)
                cout << el << " ";
            return true;
        }
        else
            return false;
    }
    sum += arr[ind];
    ds.push_back(arr[ind]);
    if (targetSumSeq2(ind + 1, arr, ds, target, sum) == true)
        return true;
    sum -= arr[ind];
    ds.pop_back();
    if (targetSumSeq2(ind + 1, arr, ds, target, sum))
        return true;
    return false;
}

// print the count subsequence whose sum == target [just count possible subSeq]
/*
Technique to print count of subseq
int f(){
    base_case://if satisfied
        return 1;
    else return 0;

    left = f();
    right = f();

    return left + right;
}
*/
int targetSumCount(int ind, vector<int> arr, int target, int sum)
{
    if (ind >= arr.size())
    {
        if (sum == target)
            return 1;
        else
            return 0;
    }
    int left = targetSumCount(ind + 1, arr, target, sum);
    sum += arr[ind];
    int right = targetSumCount(ind + 1, arr, target, sum);

    return left + right;
}
int main()
{
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

    // vector<vector<int>> result = permute(v);
    // for (int i = 0; i < result.size(); i++)
    // {
    //     for (int j = 0; j < result[0].size(); j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<int> v = {1, 2, 3}, temp;
    vector<vector<int>> result;
    vector<bool> taken(v.size(), false);
    // permutation(v, temp, v.size(), taken);
    permutation2(0, v);
    // subSeq(v, 0, temp);
    // targetSumSeq(0, v, temp, 3, 0);

    // cout << "\ncount :" << targetSumCount(0, v, 3, 0);

    return 0;
}

//--------------------------permutation containing duplicates--------------unwanted space approach--;
/*set<vector<int>> res;
void permute(int ind,vector<int> nums,int n){
    if(ind==n){
        res.insert(nums);
        return;
    }
    for(int i=ind;i<n;i++){
        swap(nums[ind],nums[i]);
        permute(ind+1,nums,n);
        swap(nums[ind],nums[i]);
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    permute(0,nums,n);
    vector<vector<int>> ans;
    for(auto &it:res) ans.push_back(it);
    return ans;
}*/

/*
Another approach --using Hashmap permutation unique
class Solution {
public:
    vector<vector<int>> res;
    void permute(map<int,int> mp,vector<int> ds,int n){
        if(ds.size()==n){
            res.push_back(ds);
            return;
        }
        for(auto &el:mp){
            if(el.second>0){
                el.second--;
                ds.push_back(el.first);
                permute(mp,ds,n);
                ds.pop_back();
                el.second++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums){
        int n = nums.size();
        map<int,int> mp;
        for(auto &el:nums){
            if(mp.find(el)!=mp.end()){
                mp[el]++;
            }else{
                mp.insert({el,1});
            }
        }
        vector<int> ds;
        permute(mp,ds,n);
        return res;
    }
};
*/