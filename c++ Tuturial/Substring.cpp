#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printSubstring(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            cout << s.substr(i, j - i + 1) << endl;
        }
    }
}
int main()
{
    printSubstring("tanveer");
    return 0;
}