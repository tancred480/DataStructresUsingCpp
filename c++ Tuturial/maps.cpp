// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

void print1(map<int, string> &m)
{
    cout << "Size :" << m.size() << endl;
    map<int, string>::iterator it; // making an iterator of map
    // m.end() will point to last element k aage waale pointer ko.
    for (it = m.begin(); it != m.end(); ++it)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
}
void print2(map<int, string> &m)
{

    // here pr is nothing but just a pair we use & just to avoid redundent copy
    for (auto &pr : m)
    {
        cout << pr.first << " " << pr.second << endl;
    }
}
void findValue(map<int, string> &m, int key)
{
    auto it = m.find(key);

    if (it == m.end())
        cout << "No Value found";
    else
        cout << "Value Found " << (*it).first << " " << (*it).second;
}
void eraseValue(map<int, string> &m, int key)
{
    auto it = m.find(key);
    if (it != m.end())
        m.erase(key);
    else
        cout << "Value is not there actually in map already" << endl;
}
int main()
{
    // Hasmaps in c++
    // map store in sorted order time complexity 0(log(n))
    map<int, string> m;
    m[1] = "abs";
    m[5] = "cdfg";
    m[3] = "4gd";
    m.insert({6, "tan"}); // passing pair;
    auto it = m.find(3);  // it will find the value for this key if there is no element with key 3 then it will return pointer to **m.end**
    if (it != m.end())
        m.erase(it);

    if (it == m.end())
        cout << "No Value found";
    else
        cout << "Value Found " << (*it).first << " " << (*it).second;
    m.clear();
    cout << "Size :" << m.size();

    /*lets solve one question
    Given N strings,print unique strings in
    lexicographical order with their frequency
    N <= 10^5
    |S| <= 100
    */
    map<string, int> mp;
    int n;
    cout << "Enter no of strings ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]++; // if does existing string comes then it increment it by 1 else it will make new one with 1;
    }
    for (auto &pr : mp)
    {
        cout << pr.first << "=>" << pr.second << endl;
    }
    //--------------------------XXXX---------------
    // unordered map here hash is created for each to get time complexity of o(1)
    // here order is not maintained use this when order is not required it will save ur time of ur code
    // unordered_map<pair<int,int> ,string > => NOT POSSIBLE
    // map<pair<int ,int>,string> => POSSIBLE Valid.
    unordered_map<string, int> um;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        um[s]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        cout << um[s] << endl;
    }
}