#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums, int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;
    vector<int> a(n1), b(n2);
    for (int i = 0; i < n1; i++)
    {
        a[i] = nums[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = nums[mid + 1 + i];
        ;
    }
    // merging two sorted arrays now
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            nums[k++] = a[i++];
        }
        else
        {
            nums[k++] = b[j++];
        }
    }
    while (i < n1)
    {
        nums[k++] = a[i++];
    }
    while (j < n2)
    {
        nums[k++] = b[j++];
    }
}
void mergeSort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }
}
void QuickSort(vector<int> &nums, int low, int high)
{
    // partitioning
    if (low >= high)
        return; // base case for ending recursion

    int pivot = nums[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (nums[j] < pivot)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    int pi = i + 1;
    swap(nums[pi], nums[high]);
    QuickSort(nums, low, pi - 1);
    QuickSort(nums, pi + 1, high);
}
int main()
{
    vector<int> v = {8, 21, 9, 12, 10};
    mergeSort(v, 0, v.size() - 1);
}