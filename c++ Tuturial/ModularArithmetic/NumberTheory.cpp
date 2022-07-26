#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
10^9 + 7=> is very close to integer and its prime no there fore we can get the multiplicative inverse of every integer in this range
1.(a+b) % M = ((a%M) + (b%M))% M
2.(a*b) % M = ((a%M) * (b%M))% M
3.(a-b) % M = ((a%M) - (b%M)+M)% M
4.(a/b) % M = ((a%M)*(b^-1)% M) % M
    where b^-1 ->multiplicative inverse
*/
// print modulo of 47 as answer
int factorial(int n) // modulas ki multiplication waali property
{
    int fact = 1;
    for (int i = 2; i < n; i++)
    {
        fact = (fact * i) % 47;
    }
    return fact;
}
/*
precision datatype
1.double
2.float
3.long long int
4.long int
5.int
6.character
when ever calculation is done in any expresion the answer comes in the higher precision

-------Rough Ranges keep in mind while CP-----
int -> -10^9 to 10^9
long int -> -10^12 to 10^12
long long int -> -10^18 to 10^18
---------------------------------------------
*/
int main()
{
    cout << (1e7) << " " << INT_MAX;
    return 0;
}