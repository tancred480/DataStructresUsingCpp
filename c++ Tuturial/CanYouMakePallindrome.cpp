#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool canbeMadePall(string s, int m)
{
    int n = s.length(), i = 0, j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            m--;
        i++;
        j--;
    }
    if (m < 0)
        return false;
    return true;
}
string pallindromeChecker(string s, vector<int> startIndex, vector<int> endIndex, vector<int> subs)
{
    string result = "";
    int n = startIndex.size();
    for (int i = 0; i < n; i++)
    {
        int st = startIndex[i], en = endIndex[i], possibleSubs = subs[i];
        string temp_s = s.substr(st, en - st + 1);
        if (canbeMadePall(temp_s, possibleSubs))
            result += '1';
        else
            result += '0';
    }
    return result;
}
int main()
{
    string s;
    int q;
    cout << "Enter String s and no. of queries: ";
    cin >> s >> q;
    vector<int> startIndex(q), endIndex(q), subs(q);
    cout << "Enter start index & endindex and possible no of substitutions for all queries";
    for (int i = 0; i < q; i++)
    {
        cin >> startIndex[i] >> endIndex[i] >> subs[i];
    }

    string result = pallindromeChecker(s, startIndex, endIndex, subs);
    cout << "result :" << result;
    return 0;
}
