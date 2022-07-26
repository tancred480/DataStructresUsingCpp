#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Searching in a rotated sorted Array
// it will return index at where its present else -1 if not present
int search(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        // check if left array is sorted or not
        if (nums[low] <= nums[high])
        {
            // check if the value exists in this range or not;
            if (nums[low] <= target && target <= nums[mid])
            { // if its present
                high = mid - 1;
            }
            else
            { // get the pointer to the remaining half of the array;
                low = mid + 1;
            }
        }
        else
        { // right must be sorted then
            // check if the value exists in this range or not;
            if (nums[mid] <= target && target <= nums[high])
            { // if its present
                low = mid + 1;
            }
            else
            { // get the pointer to the remaining half of the array;
                high = mid - 1;
            }
        }
    }
    // if value not found
    return -1;
}

// This binary sEarch Returns the elements index who is most closest/equal to the target x.
int binarySearch(vector<int> &arr, int low, int high, int target)
{
    if (low > high)
    {
        return high;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (target < arr[mid])
        return binarySearch(arr, low, mid - 1, target);
    return binarySearch(arr, mid + 1, high, target);
}
/*
1 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7
L M H

*/
int main()
{
    int n;
    cout << "enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "\nenter all elements of the array in sorted order:";
    for (auto &el : arr)
        cin >> el;
    int x;
    cout << "\nenter element to be searched : ";
    cin >> x;
    int idx = binarySearch(arr, 0, n - 1, x);
    cout << "index: " << idx << ", value: " << arr[idx];
    return 0;
}