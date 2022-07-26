#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        }
    return 0;
}
/*int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > k)
                break;
            if (a[i] >= l && a[i] <= r)
            {
                count++;
                k = k - a[i];
            }
        }
        cout << count << endl;
    }
    return 0;
}*/