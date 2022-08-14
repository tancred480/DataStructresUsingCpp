#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int kthMex(int N, int K, int A[])
{
    // code here
    int m = *max_element(A, A + N);
    unordered_set<int> hm;
    for (int i = 0; i < N; i++)
        hm.insert(A[i]);
    vector<int> res;
    for (int i = 0; i < m; i++)
    {
        if (hm.find(i) == hm.end())
            res.push_back(i);
    }
    for (auto &el : res)
        cout << el << " ";
    int n = res.size();
    if (n >= K)
        return res[K - 1];
    int ans, loop = K - n;
    ans = (n > 0) ? res[n - 1] + 1 : 1;
    while (loop != 0)
    {
        if (hm.find(ans) == hm.end())
        {
            res.push_back(ans);
            loop--;
        }
        ans++;
    }
    return res[K - 1];
}

void dfs(int vertex, vector<vector<int>> &g, vector<bool> &vis, string &col, set<char> curr_s, unordered_map<string, int> &qry, vector<string> &ans)
{
    if (vis[vertex])
        return;
    vis[vertex] = true;
    char c = col[vertex];
    cout << c << " ";
    curr_s.insert(c);
    for (auto &child : g[vertex])
    {
        if (!vis[child])
        {
            dfs(child, g, vis, col, curr_s, qry, ans);
        }
    }
    string res = "";
    for (auto &ch : curr_s)
        res += ch;
    if (qry.find(res) != qry.end())
    {
        int ind = qry[res];
        ans[ind] = "YES";
        // cout << ind << "YES"
        //      << " ";
    }
    cout << endl;
}
vector<string> solve(int N, int M, int Q, string col,
                     vector<vector<int>> &Edge, vector<string> &query)
{
    vector<vector<int>> g(N);
    for (auto &el : Edge)
    {
        g[el[0]].push_back(el[1]);
        g[el[1]].push_back(el[0]);
    }
    unordered_map<string, int> qry;
    for (int i = 0; i < Q; i++)
    {
        sort(query[i].begin(), query[i].end());
        string s = query[i];
        qry.insert({s, i});
    }
    vector<string> ans(Q, "NO");
    vector<bool> vis(N, false);
    set<char> curr_s;
    dfs(0, g, vis, col, curr_s, qry, ans);

    return ans;
}
int main()
{
    vector<vector<int>> Edge = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {1, 2}, {2, 4}, {4, 5}};
    vector<string> query = {"abc", "aec", "azc"};
    vector<string> ans = solve(9, 10, 6, "bfbdbbcac", Edge, query);
    for (auto &s : ans)
        cout << s << " ";
    return 0;
}