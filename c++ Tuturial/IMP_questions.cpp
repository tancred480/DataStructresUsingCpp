#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
int findGCD(vector<int> arr, int idx)
{
    int result = arr[0];
    for (int i = 1; i <= idx; i++)
    {
        result = gcd(arr[i], result);
        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}
// for vectors having distinct elements

int main()
{
    //--------------------------------------------------
    // short cut method using STL
    vector<int> v = {1, 2, 3};
    sort(v.begin(), v.end());
    do
    {
        for (auto &el : v)
            cout << el << " ";
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
    //--------------------------------------------------

    return 0;
}