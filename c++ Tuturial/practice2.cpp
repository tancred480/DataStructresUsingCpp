// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

bool checkBeutifullString(string s)
{
    map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
        auto it = m.find(s[i]);
        if (it != m.end())
        {
            (*it).second = (*it).second + 1;
        }
        else
        {
            m[s[i]] = 1;
        }
    }
    bool flag = false;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (((*it).second) >= (s.size() / 2))
        {
            flag = true;
            break;
        }
        // cout << (*it).first << " " << (*it).second << endl;
    }
    return flag;
}
//----------PERMUTATION 1----------------
void backtracking(vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans, vector<bool> &vis, int n)
{
    if (curr.size() >= n)
    {
        ans.push_back(curr);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == true)
            continue;
        curr.push_back(nums[i]);
        vis[i] = true;
        backtracking(nums, curr, ans, vis, n);
        vis[i] = false;
        curr.pop_back();
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    int n = nums.size();
    vector<bool> vis(n, false);
    vector<int> curr;
    vector<vector<int>> ans;
    backtracking(nums, curr, ans, vis, n);

    return ans;
}

//-----------------
//-----------NEXT PERMUTATION-----------

// minimum swaps to group all ones (2); loop wala
int minSwaps(int arr[], int n)
{
    int cnt_ones = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            cnt_ones++; // this count of ones will be our window size
    }
    if (cnt_ones == 0)
        return -1;
    // counting zeroes for our first window
    int cnt_zeroes = 0;
    for (int i = 0; i < cnt_ones; i++)
    {
        if (arr[i] == 0)
            cnt_zeroes++;
    }
    int ans = cnt_zeroes;
    for (int i = cnt_ones; i < (n + cnt_ones); i++)
    { // this will handle loop condition
        if (arr[i % n] == 0)
        {
            cnt_zeroes++;
        }
        if (arr[(i - cnt_ones) % n] == 0)
        {
            cnt_zeroes--;
        }
        ans = min(ans, cnt_zeroes);
    }
    return ans;
}

// int main()
// { // Download More RAM
//     // int t;
//     // cin >> t;
//     // while (t--)
//     // {
//     //     int n, k;
//     //     cin >> n >> k;
//     //     multiset<pair<int, int>> s;
//     //     vector<int> v(n);
//     //     for (auto &el : v)
//     //     {
//     //         cin >> el;
//     //     }
//     //     for (int i = 0; i < n; i++)
//     //     {
//     //         int x;
//     //         cin >> x;
//     //         s.insert({v[i], x});
//     //     }
//     //     sort(s.begin(), s.end());
//     //     for (auto &el : s)
//     //     {
//     //         if (el.first <= k)
//     //             k += el.second;
//     //     }
//     //     cout << k;
//     // }

//     // int t;
//     // cin >> t;
//     // while (t--)
//     // {
//     //     float h, c, T;
//     //     cin >> h >> c >> T;
//     //     int cup = 1;
//     //     float b_temp = h;
//     //     while (std::
//     //                ceil(b_temp / cup) != T)
//     //     {
//     //         //cout << b_temp << endl;
//     //         cup++;
//     //         b_temp = b_temp + c;
//     //         if (std::ceil(b_temp / cup) != T)
//     //         {
//     //             b_temp = b_temp + h;
//     //             cup++;
//     //         }
//     //     }
//     //     cout << cup << endl;
//     // }

//     // //Buy a Shovel
//     // int k, r;
//     // cin >> k >> r; // k is the price of 1 shovel and r-> is the denomination of coin in Polycarp's pocket that is different from "10-burle" coin.
//     // // 1<=r<=9;
//     // int i = 1;
//     // while (true)
//     // {
//     //     int price = k * i;
//     //     int rem = price % 10;
//     //     if (rem == 0 || rem == r)
//     //     {
//     //         cout << i << endl;
//     //         break;
//     //     }
//     //     i++;
//     // }
//     // Cormen - The Best friend of a man
//     // int n, k;
//     // cin >> n >> k;
//     // vector<int> a_days(n);
//     // for (auto &d : a_days)
//     //     cin >> d;
//     // int extra_walk = 0;
//     // for (int i = 1; i < n; i++)
//     // {
//     //     if ((k - (a_days[i] + a_days[i - 1])) > 0)
//     //     {
//     //         extra_walk += (k - (a_days[i] + a_days[i - 1]));
//     //         a_days[i] = a_days[i] + (k - (a_days[i] + a_days[i - 1]));
//     //     }
//     // }
//     // cout << extra_walk << endl;
//     // for (auto &d : a_days)
//     //     cout << d << " ";
//     // cout << endl;
//     //
//     // int t;
//     // cin >> t;
//     // while (t--)
//     // {
//     //     int n;
//     //     cin >> n;
//     //     vector<int> a(n), b(n);
//     //     for (auto &el : a)
//     //         cin >> el;
//     //     for (auto &el : b)
//     //         cin >> el;
//     //     int max_mul = 0;
//     //     for (int i = 0; i < n; i++)
//     //     {
//     //         max_mul = std::max(max_mul, a[i] * b[i]);
//     //     }
//     //     cout << max_mul << endl;
//     // }
//     // cout << atoi("words and 335") << endl;

//     // string bin_string;
//     // cin >> bin_string;
//     // int i=0,j=bin_string.size()-1;
//     // while(i<j)
//     // {
//     //     //cout << bin_string[i] << " ";
//     //     if(bin_string[i]==bin_string[j]){

//     //     }

//     // }
//     // int arr[] = {1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1};
//     // minSwaps(arr, 15);

//     return 0;
// }

// int main()
// {
//     //Knock Out spree
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         vector<int> spot;
//         for (int i = 0; i < n; i++)
//         {
//             spot.push_back(i + 1);
//         }
//         int x = 0, wand_pos = 0;
//         while (spot.size() > 1)
//         {
//             spot.erase(spot.begin() + ((wand_pos + 1) % spot.size()));
//             x++;
//             wand_pos = (x + 1) % spot.size();
//         }
//         cout << spot[0]<<endl;
//     }
//     return 0;
// }
/*const int N = 1e5 + 10;
vector<int> city[N];
bool visCity[N];
vector<vector<int>> ans;
void find_path(int vertex, int dest, vector<int> &curr)
{
    if (vertex == dest)
    {
        curr.push_back(dest);
        ans.push_back(curr);
        curr.pop_back();
        visCity[vertex] = false;
        return;
    }

    visCity[vertex] = true;
    curr.push_back(vertex);
    for (auto child : city[vertex])
    {
        if (!visCity[child])
        {
            find_path(child, dest, curr);
        }
    }
    curr.pop_back();
    visCity[vertex] = false;
}

int main()
{
    int n, m; // n-> number of cities m->directly connecting edges no of edges
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        city[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << ":";
        for (int j = 0; j < city[i].size(); j++)
        {
            cout << city[i][j] << " ";
        }
        cout << endl;
    }
    int x, y;
    cin >> x >> y;
    vector<int> curr;
    find_path(x, y, curr);
    for (auto &el : ans)
    {
        for (auto &val : el)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
*/
/*
find wieghted graph all possible paths from source 0 to n-1 node[destination].

    vector<pair<int,int>> g[N];
    //vector<bool> vis;
     bool vis[N];
    void dfs(int vertex,int &time,int dest,vector<int> &anstimes){
        if(vertex == dest){
            vis[vertex] = false;
            anstimes.push_back(time);
            return;
        }
        for(auto child : g[vertex]){
            if(!vis[child.first]){
                time = time + child.second;
                vis[child.first] = true;
                dfs(child.first,time,dest,anstimes);
                time = time - child.second;
             }
        }
        vis[vertex] = false;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> anstimes;
        for(int i=0;i<roads.size();i++){
            g[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            g[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        // for(int i=0;i<n;i++){
        //     vis.push_back(false);
        // }
        int time = 0,dest = n-1;
        dfs(0,time,dest,anstimes);
        // for(int i=0;i<n;i++){
        //     cout<<i<<" :";
        //     for(int j=0;j<g[i].size();j++){
        //         cout<<g[i][j].first<<" ";
        //     }
        //     cout<<endl;
        // }
        // int i=0;
        // for(auto &el:g){
        //     cout<<i++<<" :";
        //     for(auto &val:el){
        //         cout<<val.first<<" ";
        //     }cout<<endl;
        // }
        sort(anstimes.begin(),anstimes.end());
        int count = 1;
        for(int i=0;i<anstimes.size()-1;i++){
            if(anstimes[i]==anstimes[i+1]){
                count++;
            }else {
                break;
            }
        }
        return count;
    }
*/

const int N = 1e5 + 10;
vector<pair<int, int>> g[N];
bool vis[N];
void dfs(int vertex, int &time, int dest, int &cnt, int &ans)
{
    cout << vertex << " ";
    if (vertex == dest)
    {
        if (time == ans)
        {
            cnt++;
        }
        else if (time < ans)
        {
            ans = time;
            cnt = 1;
        }
        vis[vertex] = false;
        return;
    }
    for (auto child : g[vertex])
    {
        if (!vis[child.first])
        {
            cout << child.first << " ";
            time = time + child.second;
            vis[child.first] = true;
            dfs(child.first, time, dest, cnt, ans);
            time = time - child.second;
        }
    }
    vis[vertex] = false;
}
int countPaths(int n, vector<vector<int>> &roads)
{
    vector<int> anstimes;
    for (int i = 0; i < roads.size(); i++)
    {
        g[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        g[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }
    int time = 0, dest = n - 1, ans = INT_MAX, cnt = 1;
    dfs(0, time, dest, cnt, ans);
    return cnt;
}

// int main()
// {
//     vector<vector<int>> roads = {{0, 1, 3972}, {2, 1, 1762}, {3, 1, 4374}, {0, 3, 8346}, {3, 2, 2612}, {4, 0, 6786}, {5, 4, 1420}, {2, 6, 7459}, {1, 6, 9221}, {6, 3, 4847}, {5, 6, 4987}, {7, 0, 14609}, {7, 1, 10637}, {2, 7, 8875}, {7, 6, 1416}, {7, 5, 6403}, {7, 3, 6263}, {4, 7, 7823}, {5, 8, 10184}, {8, 1, 14418}, {8, 4, 11604}, {7, 8, 3781}, {8, 2, 12656}, {8, 0, 18390}, {5, 9, 15094}, {7, 9, 8691}, {9, 6, 10107}, {9, 1, 19328}, {9, 4, 16514}, {9, 2, 17566}, {9, 0, 23300}, {8, 9, 4910}, {9, 3, 14954}, {4, 10, 26060}, {2, 10, 27112}, {10, 1, 28874}, {8, 10, 14456}, {3, 10, 24500}, {5, 10, 24640}, {10, 6, 19653}, {10, 0, 32846}, {10, 9, 9546}, {10, 7, 18237}, {11, 7, 21726}, {11, 2, 30601}, {4, 11, 29549}, {11, 0, 36335}, {10, 11, 3489}, {6, 11, 23142}, {3, 11, 27989}, {11, 1, 32363}, {11, 8, 17945}, {9, 11, 13035}, {5, 11, 28129}, {2, 12, 33902}, {5, 12, 31430}, {6, 12, 26443}, {4, 12, 32850}, {12, 3, 31290}, {11, 12, 3301}, {12, 1, 35664}, {7, 13, 28087}, {13, 8, 24306}, {6, 13, 29503}, {11, 13, 6361}, {4, 13, 35910}, {13, 12, 3060}, {3, 13, 34350}, {13, 5, 34490}, {13, 2, 36962}, {10, 13, 9850}, {9, 13, 19396}, {12, 14, 8882}, {8, 14, 30128}, {14, 6, 35325}, {14, 5, 40312}, {1, 14, 44546}, {11, 14, 12183}, {15, 12, 13581}, {2, 15, 47483}, {4, 15, 46431}, {15, 10, 20371}, {15, 14, 4699}, {15, 6, 40024}, {15, 7, 38608}, {1, 15, 49245}, {11, 15, 16882}, {8, 15, 34827}, {0, 15, 53217}, {5, 15, 45011}, {15, 3, 44871}, {16, 2, 53419}, {16, 9, 35853}, {1, 16, 55181}, {16, 7, 44544}, {8, 16, 40763}, {0, 16, 59153}, {15, 16, 5936}, {16, 10, 26307}, {16, 6, 45960}, {12, 16, 19517}, {17, 2, 57606}, {17, 3, 54994}, {17, 14, 14822}, {17, 11, 27005}, {0, 17, 63340}, {17, 7, 48731}, {8, 17, 44950}, {17, 16, 4187}, {5, 17, 55134}, {17, 10, 30494}, {17, 9, 40040}, {17, 12, 23704}, {13, 17, 20644}, {17, 1, 59368}};
//     cout << "Getting all trinched down :";
//     int res = countPaths(18, roads);
//     cout << "result :" << res << "";
//     return 0;
// }
bool checkSorted(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> v(n);
        for (auto &el : v)
            cin >> el;
        int i = 0, j = i + 1;
        while (j < n)
        {

            if ((v[i] > 0 && v[j] < 0) || (v[i] < 0 && v[j] > 0))
            {
                v[i] = -v[i];
                v[j] = -v[j];
                i++;
                j = i + 1;
            }
            j++;
        }
        if (checkSorted(v) == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
