#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

void print(set<string> &s)
{
    for (string value : s)
    {
        cout << value << endl;
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << it->data() << " " << (*it) << endl; //both can be used to print data either *it OR it->data()
    }
}
int main()
{
    //log(n) time complexity
    //unordered_set<string> s; //same as unordered_map only for simple data staructures like int,string
    set<string> s; //its sorted accroding to numberwise for int set and lexicographical order for strings
    s.insert("abc");
    s.insert("dfg");
    s.insert("dfg");
    s.insert("a43"); //log(n)
    s.insert("d6g");
    auto it = s.find("dfg");
    if (s.find("dfg") != s.end())
        cout << "value not found";
    else
    {
        cout << it->data() << " found";
        s.erase(*it);
    }
    print(s);
    //--------------Multi-Set---------
}