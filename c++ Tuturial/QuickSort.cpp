#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void QuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);

        QuickSort(arr, low, i - 1);
        QuickSort(arr, i + 1, high);
    }
}

int main()
{
    vector<int> v = {9, 112, 200, 25, 3, 35, 89, -1, 25, 302, 45, 33, 22, 1};
    for (auto &el : v)
        cout
            << el << " ";
    cout << endl;
    QuickSort(v, 0, v.size() - 1);
    cout << endl;
    for (auto &el : v)
        cout << el << " ";
    return 0;
}
