#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        //number of layers;
        int no_of_layer = n / 2, ans = 0, v = 8;
        for (int i = 1; i <= no_of_layer; i++)
        {
            ans = ans + i * v;
            v += 8;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v1(n), v2(n);
        for (int i = 0; i < n; i++)
            cin >> v1[i];
        for (int i = 0; i < n; i++)
            cin >> v2[i];
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<>());
        int ans = 0;
        for (int i = 0, j = 0; i < v1.size(); i++)
        {
            if (k > 0 and (v1[i] < v2[j]))
            {
                ans = ans + v2[j];
                j++;
                k--;
            }
            else
            {
                ans = ans + v1[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}*/
/*
int main()
{
    int q;
    cin >> q;
    vector<int> v;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int new_elmnt;
            cin >> new_elmnt;
            v.push_back(new_elmnt);
        }
        else if (t == 2)
        {
            int n1, n2;
            cin >> n1 >> n2;
            for (auto it = v.begin(); it != v.end(); it++)
            {
                if (*it == n1)
                {
                    *it = n2;
                }
            }
        }
    }

    for (auto i : v)
        cout << i << " ";
    return 0;
}
*/