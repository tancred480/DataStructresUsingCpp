#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/**/
int binExpoRecur(int a, int b)
{
    if (b == 0)
        return 1;
    int res = binExpoRecur(a, b / 2);
    if (b & 1)
        return a * res * res;
    return res * res;
}
int main()
{
    double d = 1e20;
    cout << fixed << setprecision(2) << d;

    return 0;
}