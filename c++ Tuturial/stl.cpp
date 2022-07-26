#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*vector<int> v = {1, 23, 45, 6, 1, 3, 0}; //vector of 15 elements with initial value 2
    //vector<int> arr[50];//this vector is an array of 50 elements
    for (auto i : v)
        cout << i << "\t";
    cout << endl
         << v.size() << endl;
    v.clear();
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    v.push_back(7);

    for (auto i : v)
        cout << i << "\t";
    cout << endl
         << v.size() << endl;
    
    sort(v.begin() + 1, v.end() - 2);
    for (auto i : v)
        cout << i << "\t";
    
    pair<int, string> p = {4, "Tanveer"};
    cout << p.first << " " << p.second;

    //pair<int,int> p1[1000]; //array of pair
    vector<pair<int, string>> vec;

    for (int i = 0; i < 10; i++)
    {
        int f;
        string s;
        cout << "\nEnter value for first and second : ";
        cin >> f >> s;
        pair<int, string> temp = {f, s};
        vec.push_back(temp);
        cout << endl;
    }

    for (auto i : vec)
    {
        cout << i.first << " " << i.second << endl;
    }
    sort(vec.begin(), vec.end());
    cout << "After Sorting ";
    for (auto i : vec)
    {
        cout << i.first << " " << i.second << endl;
    }
    
    vector<int> v1 = {10, 1, 13, 4, 5};
    //vector<int>::iterator it = v1.begin() //one way of creating a iterator
    //shortcut
    auto it = v1.begin();
    cout << *it << " " << *(it + 1);
    */
    //SET here elements are in sorted order
    /* set<int> s, set<string> s2; 
   s.insert(x) ,s.erase(x) , s.count(x) , s.clear() , s.size() */
    /*
    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(4);
    s.insert(3);
    s.insert(5);
    s.insert(13);

    s.erase(1);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << "\nSize of Set :" << s.size();
    auto it_s = s.begin();

    cout << "\n"
         << *(++it_s) << " " << *it_s; //its runs in O(logN)

    /*
    s.find(x) it returns iterator to element with value x .Returns s.end() if not found .O(log N)
    s.lower_bound(x) :returns iterator to the first element which is >= x .Return s.end() if not found .O(logN)
    s.upper_bound(x):returns iterator to the first element which is > x .Returns s.end() if not found .O(logN)
    s.find(it) :erase the element with iterator it.O(logN) 
    */
    /*
    cout << endl;
    auto t = s.lower_bound(1); //remember it return ITERATOR to the first element which is greater than or equals to the element x
    auto t2 = s.upper_bound(5);

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << "\n"
         << *t << " " << *t2;
    */
    vector<int> v(5);
    // for (auto &ref : v)
    // {
    //     cin >> ref;
    // }
    for (int i = 0; i < 5; i++)
    {
        cin >> v[i];
    }
    cout << endl;
    for (auto &value : v)
    {
        cout << value << " ";
    }
    return 0;
}