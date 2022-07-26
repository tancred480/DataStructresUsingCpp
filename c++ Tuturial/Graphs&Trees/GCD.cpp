#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// gcd using euclidean algorithm
// formula : axb/(GCD) = LCM
/*
minimum fraction of a,b
a/b = (a)/gcd(a,b) / (b)/gcd(a,b)

12/18 = 12/6  / 18/6 => 2/3 -> so this is the minimum fraction of a/b

*/
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int main()
{
    int a, b, lcm, gcd;
    cout << "Enter a & b :";
    cin >> a >> b;
    gcd = GCD(a, b);
    lcm = (a * b) / gcd; // using formula
    cout << "Greatest Common Divisor :" << gcd << endl;
    cout << "Least Common Divisor :" << lcm << endl;
    return 0;
}