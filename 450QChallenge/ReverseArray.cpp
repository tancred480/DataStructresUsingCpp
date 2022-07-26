#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        i++;
        j--;
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 5, 6};
    reverseArray(arr);
    for (auto &el : arr)
    {
        cout << el << " ";
    }
    return 0;
}