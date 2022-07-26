#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool sortByVal(pair<int, int> &a, pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    vector<pair<int, int>> vec(6);
    for (auto &el : vec)
    {
        cin >> el.first >> el.second;
    }

    cout << "\nAfter sorting by value :\n";
    sort(vec.begin(), vec.end(), sortByVal);
    for (auto &el : vec)
    {
        cout << el.first << " " << el.second << endl;
    }
    return 0;
}