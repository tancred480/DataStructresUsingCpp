#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void primeSieve(int n)
{ // n is our end limit from 2 - n
    vector<int> prime(100, 0);
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = (i * i); j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    // printing all prime number upto n
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    primeSieve(n);
}