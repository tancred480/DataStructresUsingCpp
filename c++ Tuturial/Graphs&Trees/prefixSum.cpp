#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
int a[N];
int pf[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        long long sum = 0;
        // for (int i = l; i <= r; ++i)
        // {
        //     sum += a[i];
        // }
        sum = pf[r] - pf[l - 1];
        cout << sum << endl;
    }
    return 0;
}