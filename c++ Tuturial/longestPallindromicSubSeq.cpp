#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//--longest common pallindromic subseq--------
// this problem is just an extension of lcs such that we just have to perform lcs with its reversed string to
// get the lc pallindromic subseq
int dp[1001][1001];

int lcs(int ind1, int ind2, string &s1, string &s2)
{
    if (ind1 == -1 || ind2 == -1)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcs(ind1 - 1, ind2 - 1, s1, s2);

    return dp[ind1][ind2] = max(lcs(ind1 - 1, ind2, s1, s2), lcs(ind1, ind2 - 1, s1, s2));
}
int longestPalindromeSubseq(string s)
{
    memset(dp, -1, sizeof(dp));
    int n = s.size();
    string s1 = s;
    reverse(s.begin(), s.end());
    return lcs(n - 1, n - 1, s1, s);
}
//------------------Longest Pallindromic Substring----------
string longestPalindrome(string s)
{
    int n = s.size(), resLen = 0;
    string ress = "";
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i; // for odd pallindrome
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > resLen)
            {
                resLen = r - l + 1;
                ress = s.substr(l, r - l + 1);
            }
            l--;
            r++;
        }
        l = i, r = i + 1; // for even pallindrome
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l + 1 > resLen)
            {
                resLen = r - l + 1;
                ress = s.substr(l, r - l + 1);
            }
            l--;
            r++;
        }
    }
    return ress;
}

int main()
{

    return 0;
}