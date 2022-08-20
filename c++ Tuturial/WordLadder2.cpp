#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Getting all shortest path
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

/*
class Solution {
public:
    vector<vector<string>> ans;
    void AddEdge(string s,map<string,vector<string>> &hm,unordered_map<string, unordered_set<string>> &g){
        for(int i=0;i<s.size();i++){
            string t = s;
            t[i] = '*';
            for(auto &sw:hm[t]){
                if(sw!=s){
                    g[s].insert(sw);
                    g[sw].insert(s);
                }
            }
        }
    }
    void dfs(string src,string dest,unordered_map<string, unordered_set<string>> &g,unordered_set<string> vis,vector<string> ds){
        if(vis.find(src)!=vis.end()) return;
        vis.insert(src);
        ds.push_back(src);
        if(src==dest){
            ans.push_back(ds);
            return;
        }
        for(auto &child:g[src]){
            if(vis.find(child)==vis.end()){
                dfs(child,dest,g,vis,ds);
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, unordered_set<string>> g;
        map<string,vector<string>> hm;
        for(auto w:wordList){
            for(int i=0;i<w.size();i++){
                string s = w;
                s[i] = '*';
                hm[s].push_back(w);
            }
        }
        AddEdge(beginWord,hm,g);
        for(auto w:wordList) AddEdge(w,hm,g);
        unordered_set<string> vis;
        vector<string> ds;
        dfs(beginWord,endWord,g,vis,ds);

        vector<vector<string>> res;
        int mnLen = INT_MAX;
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()<mnLen) mnLen = ans[i].size();
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()==mnLen) res.push_back(ans[i]);
        }

        return res;
    }
};
*/