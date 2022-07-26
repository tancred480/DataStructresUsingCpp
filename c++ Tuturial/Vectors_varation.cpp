// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<string> &v)
{
    cout << "size:" << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void printVec2(vector<pair<int, int>> &v)
{
    cout << "size:" << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;
}
void fillVec(vector<pair<int, int>> &v)
{
    int n;
    cout << "Enter number of pair to be inserted :" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        //v.push_back(make_pair(x,y));
        v.push_back({x, y});
    }
}
void fillVec2()
{
    //array of vectors
    int N;
    cout << "Enter the no of vectors :" << endl;
    cin >> N;
    vector<int> v[N]; //here we have N vectors array;
    for (int i = 0; i < N; i++)
    {
        int n;
        cout << "Enter the no of values to be inserted into this vector :" << endl;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cout << "Enter j=" << j << endl;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < N; i++)
    {
        //printVec(v[i])
        //  OR
        int n = v[i].size();
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
void fillVec3(vector<vector<int>> &v)
{
    //here no of vector is dynamic mtlb abhi vector fix numbers ka nhi hai jaise upr waale m tha v[N]
    int N;
    cout << "Enter no of vectors to be inserted :";
    cin >> N;
    // for (int i = 0; i < N; i++)
    // {
    //     int n;
    //     cout << "Enter no of vetors at i = " << i << " :";
    //     cin >> n;
    //     vector<int> temp;
    //     for (int j = 0; j < n; j++)
    //     {
    //         int x;
    //         cout << "Enter j=" << j << endl;
    //         cin >> x;
    //         temp.push_back(x);
    //     }
    //     v.push_back(temp);
    // }
    for (int i = 0; i < N; i++)
    {
        int n;
        cout << "Enter no of vetors at i = " << i << " :";
        cin >> n;
        v.push_back(vector<int>()); //initializing or creating ith vector for further access just to avoid nullpointer exception
        for (int j = 0; j < n; j++)
        {
            int x;
            cout << "Enter j=" << j << endl;
            cin >> x;
            v[i].push_back(x);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        //printVec(v[i])
        //  OR
        int n = v[i].size();
        for (int j = 0; j < n; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    //yaha pe kabhi m vectors ko badah ksta hun aur kam kr skta hun.
}
void itrExample(vector<pair<int, int>> &v)
{
    vector<pair<int, int>>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).first << "=>" << (*it).second << endl;
    }
    //different syntax (*it).first == it->first
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << it->first << "=>" << it->second << endl;
    }
}
void itrExample2(vector<pair<int, int>> &v)
{
    for (pair<int, int> &value : v)
    {
        cout << value.first << endl;
    }
    //or
    for (auto &value : v)
    {
        cout << value.first << " " << value.second << endl;
    }
}
int main()
{
    vector<pair<int, int>> v = {{1, 2}, {4, 3}, {5, 7}};
    //fillVec2();
    //vector<vector<int>> v;
    itrExample2(v);
    return 0;
}