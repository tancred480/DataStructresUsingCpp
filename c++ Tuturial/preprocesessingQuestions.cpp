#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1), mxl(n + 2, 1), mxr(n + 2, 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (i == 1)
        {
            mxl[i] = arr[i];
        }
        else
        {
            mxl[i] = max(mxl[i - 1], arr[i]);
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (i == n)
        {
            mxr[i] = arr[i];
        }
        else
        {
            mxr[i] = max(mxr[i + 1], arr[i]);
        }
    }
    while (q--)
    {
        int l, r, ans;
        cin >> l >> r;
        ans = max(mxl[l - 1], mxr[r + 1]);
        cout << ans << endl;
    }
}