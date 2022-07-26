#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int cntN = 0;
        for (auto i : s)
        {
            if (i == 'N')
                cntN++;
        }
        if (cntN == 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}