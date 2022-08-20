#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Getting shortest path length
void AddEdge(string s, map<string, vector<string>> &hm, unordered_map<string, unordered_set<string>> &g)
{
    for (int i = 0; i < s.size(); i++)
    {
        string t = s;
        t[i] = '*';
        for (auto &sw : hm[t])
        {
            if (sw != s)
            {
                g[s].insert(sw);
                g[sw].insert(s);
            }
        }
    }
}
int bfs(string src, string dest, unordered_map<string, unordered_set<string>> &g)
{
    queue<string> q;
    unordered_set<string> vis;
    q.push(src);
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        level++;
        for (int i = 0; i < n; i++)
        {
            auto node = q.front();
            q.pop();
            vis.insert(node);
            for (auto &child : g[node])
            {
                // here inserting a node in vis array means its visited
                if (child == dest)
                    return level + 1;
                if (vis.find(child) == vis.end())
                {
                    q.push(child);
                }
            }
        }
    }
    return 0;
}
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_map<string, unordered_set<string>> g;
    map<string, vector<string>> hm;
    for (auto w : wordList)
    {
        for (int i = 0; i < w.size(); i++)
        {
            string s = w;
            s[i] = '*';
            hm[s].push_back(w);
        }
    }
    AddEdge(beginWord, hm, g);
    for (auto w : wordList)
        AddEdge(w, hm, g);

    int ans = bfs(beginWord, endWord, g);
    return ans;
}