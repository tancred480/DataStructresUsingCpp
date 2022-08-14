#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//-----------Longest Common Subseq.------------
int dp[1001][1001];
int lcs(int ind1, int ind2, string &s1, string &s2)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s1[ind1] == s2[ind2])
        return dp[ind1][ind2] = 1 + lcs(ind1 - 1, ind2 - 1, s1, s2);

    return dp[ind1][ind2] = max(lcs(ind1 - 1, ind2, s1, s2), lcs(ind1, ind2 - 1, s1, s2));
}
int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length(), m = text2.length();
    memset(dp, -1, sizeof(dp));
    return lcs(n - 1, m - 1, text1, text2);
}
//-------------------------------------------------

//---------Longest common subsequence------Tabulation-----
int longestCommonSubsequence2(string text1, string text2)
{
    int n = text1.length(), m = text2.length();
    // using Tabulation Technique Bottom Up approach
    vector<vector<int>> ds(n + 1, vector<int>(m + 1, -1)); // extra column and row for shifting of index
    for (int i = 0; i < n + 1; i++)
        ds[i][0] = 0;
    for (int j = 0; j < m + 1; j++)
        ds[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                ds[i][j] = 1 + ds[i - 1][j - 1];
            else
                ds[i][j] = max(ds[i][j - 1], ds[i - 1][j]);
        }
    }
    return ds[n][m];
}
//----------------print---------------------------------
void longestCommonSubsequence3(string text1, string text2)
{
    int n = text1.length(), m = text2.length();
    // using Tabulation Technique Bottom Up approach
    vector<vector<int>> ds(n + 1, vector<int>(m + 1, -1)); // extra column and row for shifting of index
    for (int i = 0; i < n + 1; i++)
        ds[i][0] = 0;
    for (int j = 0; j < m + 1; j++)
        ds[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                ds[i][j] = 1 + ds[i - 1][j - 1];
            else
                ds[i][j] = max(ds[i][j - 1], ds[i - 1][j]);
        }
    }
    int i = n, j = m;
    string lcs_string = "";
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            lcs_string += text1[i - 1];
            i--;
            j--;
        }
        else if (ds[i - 1][j] > ds[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(lcs_string.begin(), lcs_string.end());
    cout << lcs_string << endl;
}
//----------------Longest Common Substring -Tabulation method easy to think-----
int longestCommonSubstr(string S1, string S2, int n, int m)
{
    // your code here

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // one extra zeroeth column and row
    int ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (S1[i - 1] == S2[j - 1]) // shifting of index in order to write the tabulation
            {                           // as string 0-n and 0-m not (1+(n+1)) & (1+(m+1))
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}
//--------------------------------------------------------------------------------
int main()
{
    longestCommonSubsequence3("gffjhs", "jgdjffs");
    return 0;
}