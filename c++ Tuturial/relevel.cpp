#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// bool checkPrime(int n)
// {
//     if (n == 1 || n == 2)
//         return true;
//     for (int i = 2; i < (sqrt(n) + 1); i++)
//     {
//         if ((n % i) == 0)
//             return false;
//     }
//     return true;
// }
// void SubSeqSum(vector<int> &arr, int index, int curr_sum, int &res_sum)
// {
//     if (index >= arr.size())
//     {
//         if ((curr_sum > res_sum) && checkPrime(curr_sum))
//         {
//             res_sum = curr_sum;
//         }
//         return;
//     }
//     curr_sum += arr[index];
//     SubSeqSum(arr, index + 1, curr_sum, res_sum);
//     curr_sum -= arr[index];
//     SubSeqSum(arr, index + 1, curr_sum, res_sum);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (auto &el : arr)
//         cin >> el;
//     int res_sum = -1;
//     SubSeqSum(arr, 0, 0, res_sum);
//     cout << res_sum << endl;
//     return 0;
// }

// #include <iostream>
// #include <bits/stdc++.h>
// const int M = 1e9 + 7;
// using namespace std;
// void getSubSeq(vector<int> &arr, int index, vector<int> ds, int x, int y, int &res)
// {
//     if (index >= arr.size())
//     {
//         if (ds.size() != 0 && ds.size() != x && ds.size() != y)
//         {
//             res = ((res % M) + 1) % M;
//         }
//         return;
//     }
//     ds.push_back(arr[index]);
//     getSubSeq(arr, index + 1, ds, x, y, res);
//     ds.pop_back();
//     getSubSeq(arr, index + 1, ds, x, y, res);
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, x, y;
//         cin >> n >> x >> y;
//         vector<int> arr(n), ds;
//         for (int i = 1; i <= n; i++)
//             arr[i - 1] = i;
//         int res = 0;
//         getSubSeq(arr, 0, ds, x, y, res);
//         cout << res << endl;
//     }
//     return 0;
// }
void findMinCount(int x, int y, int cnt, int &res_cnt, set<int> &s)
{
    if (x == y)
    {
        res_cnt = min(cnt, res_cnt);
        return;
    }
    if (x < 0 || x > y)
    {
        return;
    }
    if (s.find(x) != s.end())
    {
        return;
    }
    cout << x << " ";
    s.insert(x);
    findMinCount(2 * x, y, cnt + 1, res_cnt, s);
    s.erase(s.find(x));
    if (x & 1)
    {
        s.insert(((3 * x) + 1));
        findMinCount(((3 * x) + 1), y, cnt + 1, res_cnt, s);
        s.erase(s.find(((3 * x) + 1)));
    }
    else
    {
        s.insert(x / 2);
        findMinCount(x / 2, y, cnt + 1, res_cnt, s);
        s.erase(s.find(x / 2));
    }
}
int main()
{
    int res_cnt = INT_MAX;
    set<int> s;
    findMinCount(5, 32, 0, res_cnt, s);
    cout << res_cnt << " ";
    return 0;
}