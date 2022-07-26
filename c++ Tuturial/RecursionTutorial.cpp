// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// long long fib(long long n, vector<long long> &v)
// {
//     if (n == 0 || n == 1)
//         return n;

//     if (v[n] != -1)
//     {
//         return v[n];
//     }
//     v[n] = fib(n - 1, v) + fib(n - 2, v);
//     return v[n];
// }
// long long fib2(long long n)
// {
//     if (n == 0 || n == 1)
//     {
//         return n;
//     }
//     long long a = 0, b = 1;

//     while (n - 1 != 0)
//     {
//         long long temp = a + b;
//         a = b;
//         b = temp;
//         n--;
//     }
//     return b;
// }
// int main()
// {
//     long long n;
//     cin >> n;
//     vector<long long> v(n + 1, -1);
//     v[0] = 0, v[1] = 1;
//     cout << fib2(n);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

/*
int reverseNumberRecursively(int n, int result = 0)
{
    if (n == 0)
        return result;
    result = result * 10 + (n % 10);
    reverseNumberRecursively(n / 10, result);
}*/
//Recursion Tutorial
//Recursive leap of faith
void say_hellow(int i)
{
    if (i == 0)
        return;
    cout << i << " hello" << endl;
    say_hellow(i - 1);
}

string reverseString(string s)
{
    if (s == "")
        return "";
    return reverseString(s.substr(1)) + s[0];
}

int sumOfN(int n)
{
    if (n == 0)
        return 0;
    return sumOfN(n - 1) + n;
}

int factOfN(int n)
{
    if (n == 0)
        return 1;
    return factOfN(n - 1) * n;
}

int sum_digit(int n)
{
    if (n == 0)
        return 0;
    int last_digit = n % 10;
    int remaining_digit = n / 10;

    return sum_digit(remaining_digit) + (last_digit);
}

int fibboAtNPoss(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibboAtNPoss(n - 1) + fibboAtNPoss(n - 2);
}

int fibOptimize()
{
}
void printPattern1(int n)
{
    if (n == 0)
        return;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    printPattern1(n - 1);
}

void printPattern2(int n)
{
    if (n == 0)
        return;
    printPattern2(n - 1);
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

void patterPrinting3(int n)
{
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    patterPrinting3(n - 1);
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

int reverseNumber(int n)
{
    int rem, result = 0, temp = n;
    while (temp != 0)
    {
        rem = temp % 10;
        temp = temp / 10;
        result = result * 10 + rem;
    }
    return result;
}

bool isPallindrome(string input)
{
    if (input.size() == 0 || input.size() == 1)
    {
        return true;
    }
    if (input[0] == input[input.size() - 1])
    {
        //   cout << input.substr(1, input.size() - 2) << endl;
        return isPallindrome(input.substr(1, input.size() - 2));
    }

    return false;
}
//backtracking

/*     a  d  e  f  g
    00 01 02 03 04 05
  a 10 11
  e 20 min(00,01,10) 11
  f 30 min(arr[i-1][j-1],arr[i][j-1],arr[i-1][j])
  g 40

replace(\)   remove(|)

insert(->)   
*/
int EditDistance(string s1, string s2)
{
    if (s1.size() == 0)
        return s2.size();
    if (s2.size() == 0)
        return s1.size();

    int arr[s1.size() + 1][s2.size() + 1];
    for (int i = 0; i < s1.size() + 1; i++)
    {
        arr[i][0] = i;
    }
    for (int i = 0; i < s2.size() + 1; i++)
    {
        arr[0][i] = i;
    }
    for (int i = 1; i < s1.size() + 1; i++)
    {
        for (int j = 1; j < s2.size() + 1; j++)
        {
            if (s2[i - 1] == s1[j - 1])
            {
                arr[i][j] = arr[i - 1][j - 1];
            }
            else
            {
                arr[i][j] = min(arr[i - 1][j - 1], min(arr[i][j - 1], arr[i - 1][j])) + 1;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < s1.size() + 1; i++)
    {
        for (int j = 0; j < s2.size() + 1; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return arr[s1.size()][s2.size()];
}
int EditDistance2(string s1, string s2)
{
}
int main()
{
    string s1, s2;
    cout << "Enter two string :" << endl;
    cin >> s1 >> s2;
    //EditDistance(s1, s2);
    cout << "Minimum operations required is :" << EditDistance(s1, s2);

    return 0;
}