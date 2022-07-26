#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
{
    map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mp.insert({nums[i], i});
    }
    for (auto &el : operations)
    {
        int x = el[0], y = el[1];
        nums[mp[el[0]]] = el[1];
        mp.insert({el[1], mp[el[0]]});
        mp.erase(el[0]);
    }
    return nums;
}
int minMaxGame(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    vector<int> v(nums.size() / 2);
    int k = 0;
    for (int i = 0, j = i + 1; j < nums.size(); j += 2, i += 2)
    {
        if (!(k & 1))
        { // if even
            int t = min(nums[i], nums[j]);
            v[k++] = t;
            cout << t << " ";
        }
        else
        {
            int t = max(nums[i], nums[j]);
            v[k++] = t;
            cout << t << " ";
        }
    }
    cout << "\n";

    return minMaxGame(v);
}

int main()
{
    // your code goes here
    vector<int> v = {1, 3, 5, 2, 4, 8, 2, 2};
    cout << ":\n"
         << minMaxGame(v);
}
