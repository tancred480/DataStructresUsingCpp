#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//introsort -> mixture of (Quick sort),(heap sort),(insertion sort).
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &el : a)
    {
        cin >> el;
    }
    sort(a, a + 3);
    for (auto &el : a)
    {
        cout << el << " ";
    }
    return 0;
}