#include <bits/stdc++.h>
using namespace std;
//insertion sort
int main()
{
    int n;
    cout << "Enter size of array :" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter elements of array in seprated space in one line" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //insertion Sort
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i], j;
        for (j = i - 1; arr[j] > curr and j >= 0; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = curr;
    }
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}