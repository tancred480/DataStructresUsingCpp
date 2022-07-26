#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

// write a program to check if a given number is a power of two.
bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    } // else
    /*
    in any number which is power of two there is only one bit set
    example 2 =>0010    and n-1 1=>0001
            4 =>0100            3=>0011
            8 =>1000            7=>0111
            therefore n & n-1 ==0000 every time "n" is power of two
    */
    return (n & (n - 1)) == 0 ? true : false;
}

// check if Kth bit is set or not  -its like the getBit function
bool checkKthBit(int n, int k)
{
    return (n & (1 << k)) == 0 ? false : true;
}
// count number of ones in a number as binary number
// 2^n is represented as (1<<n)
int numberOfOne_s(int n)
{
    /*
    this is the fastest approach
    n=19 => 01011   n=18  => 01010  ....
  n-1=18 => 01010   n-1=17=> 01001

  n&(n-1)-> 01010   n&(n-1)->01001
    */
    int cnt = 0;
    while (n)
    {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}
int numberOf1Bits(int N)
{
    // count no. of one's 2nd method
    int count = 0;
    while (N)
    {
        if (N & 1)
            count++;
        N = N >> 1;
    }
    return count;
}
void subsets(int arr[], int n)
{
    // here we have to go till [2^(n) - 1] there fore (1<<n)
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

uint32_t reverseBit(uint32_t n)
{
    uint32_t result = 0;
    for (int i = 0; i < 31; i++)
    {
        if (n & 1)
        {
            result = result | (1 << (31 - i)); // its like setBitoperation
        }
        n = n >> 1;
    }
    return result;
}
/*
Write a program to find a uniue number in an array
where all numbers except one, are present twice.
*/
int getUniqueElement(vector<int> a)
{
    int res = 0;
    for (auto &el : a)
    {
        res = res ^ el; // using xor operator n^n = 0,n^0=n
    }
    return res;
}
/*
Write a program to find the 2 unique numbers in an array where all
numbers except two are present twice.
{2,4,6,7,4,5,6,2}
7=>0111
5=>0101 ^
--------
   0010
--------

*/
int setBit(int n, int pos)
{
    return (n & (1 << pos)) != 0; // if equals 0 then we do not have one over there
}
void getTwoUniuqeEl(vector<int> a)
{
    int xorsum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        xorsum = xorsum ^ a[i];
    }
    int tempxor = xorsum;
    int setbit = 0, pos = 0;
    // here we run this loop untill we get the 1 in our setbit which will directly also get the position of 1st one
    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int newxor = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (setBit(a[i], pos - 1))
        {
            newxor = newxor ^ a[i];
        }
    }
    cout << newxor << endl;
    cout << (tempxor ^ newxor) << "\n";
}

// here we have to find out the &-operation between left - right range of numbers inclusive of right
int rangeBitwiseAnd(int left, int right)
{
    int count = 0;
    while (left != right)
    {
        left >>= 1;
        right >>= 1;
        count++;
    }
    return right <<= count;
}
void singleNumber(vector<int> nums)
{
    // Code here.
    sort(nums.begin(), nums.end());
    vector<int> ans;
    int i = 0;
    while (i < nums.size() - 1)
    {
        if (nums[i] ^ nums[i + 1] != 0)
        {
            cout << i << ":" << nums[i] << " ,i+1 : " << nums[i + 1] << "\n";
            i++;
        }
        else if (nums[i] ^ nums[i + 1] == 0)
        {
            cout << i << ":" << nums[i] << " ,i+1 : " << nums[i + 1] << "\n";
            i = i + 2;
        }
    }
    if (i == nums.size() - 1)
    {
        cout << nums[i] << " ";
        i++;
    }
}
int main()
{
    // cout << numberOfOne_s(7) << endl;
    // int a[] = {45, 3, 19};
    // subsets(a, 3);
    // vector<int> arr = {2, 4, 6, 3, 4, 6, 2};
    // cout << getUniqueElement(arr);
    vector<int> arr = {1, 2, 3, 1, 2, 3, 5, 7};
    // getTwoUniuqeEl(arr);

    return 0;
}