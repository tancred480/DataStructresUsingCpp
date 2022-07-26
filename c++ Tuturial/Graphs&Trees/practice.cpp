#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

// vector<pair<int, int>> E;
// for (int x = 0; x < 17; x++)
// {
//     int temp = sqrt(pow(x, 3) + 2 * x + 2);
//     if (floor(temp) == temp)
//     {
//         E.push_back({x, temp});
//     }
// }
// for (auto &el : E)
// {
//     cout << el.first << " " << el.second << endl;
// // }
// int n, d, m;
// cin >> n >> d >> m;
// vector<int> s(n);
// for (auto &el : s)
//     cin >> el;
// int sum = 0, count = 0;
// for (int i = 0; i < m; i++)
//     sum += s[i]; // first segement sum
// for (int i = 0, j = m - 1; i < s.size() && j < s.size();)
// {
//     cout << sum << " ";
//     if (sum == d)
//         count++;
//     sum -= s[i++];
//     sum += s[++j];
// }
// cout << count << " ";