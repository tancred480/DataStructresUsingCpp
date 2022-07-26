#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*  --problem statement--
An arithemetic array is an array that contains at least two integers and the differences 
between consecutive integers are equal . For example [9,10],[3,3,3],and [9,7,5,3] are arithemetic arrays,
while [1,3,3,7],[2,1,2],and [1,2,4] are not arithemeic arrays.

Sarasvati has an array of N non-negative integers. The i-th integer  of the array is Ai. She 
wants to choose a contiguous arithemetic subarray from her array that has the maximum
length. Please help her to determine the length of the longest contiguous arithemetic 
subarray.

INPUT format:
The first line of the input gives the number of test cases , T .T- test cases follow . Each
test case begins with a line containing the integer N. The second line contains N integers. The
i-th integer is Ai.

OUTPUT format:
For each test case , output one line containing Case #x:y ,Where x is the test case number 
(starting from 1) and y is the length of the longest continuous arithemetic subarray. 
*/
void print_all_subarray(int arr[], int n)
{
    vector<vector<int>> v;

    vector<int> first;
    first.push_back(arr[0]);
    v.push_back(first);
    int gcounter = 0;
    for (int i = 1; i < n; i++)
    {
        vector<int> f;
        f.push_back(arr[i]);
        v.push_back(f);
        for (int j = i; j < n; j++)
        {
            vector<int> temp(v[gcounter]);
            temp.push_back(arr[j]);
            cout << gcounter << " ";
            v.push_back(temp);
            gcounter++;
        }
        cout << endl;
    }
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    print_all_subarray(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}