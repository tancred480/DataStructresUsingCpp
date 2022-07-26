#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// string removeDuplicate(string s){
//     int n =
// }
int main()
{
    string s1 = "hello world";
    cout << s1 << "\n";
    // if string only contains alphabets and small letters
    int frequency[26] = {0}; // initializing zero initially
    for (int i = 0; i < s1.length(); i++)
    {
        int c = (int)s1[i] - 'a'; //
        frequency[c]++;
    }
    string res = "";
    for (int i = 0; i < s1.length(); i++)
    {
        int c = (int)s1[i] - 'a';
        if (frequency[c] >= 1)
        {
            res += s1[i];
            frequency[c] = 0;
        }
    }
    cout << res << " ";

    return 0;
}