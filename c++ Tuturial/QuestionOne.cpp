#include <iostream>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int evenSumK(int arr[], int N, int K)
{
    if (K > N)
    {
        return -1;
    }
    int maxSum = 0;
    vector<int> Even;
    vector<int> Odd;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] % 2)
        {
            Odd.push_back(arr[i]);
        }
        else
        {
            Even.push_back(arr[i]);
        }
    }
    sort(Odd.begin(), Odd.end());
    sort(Even.begin(), Even.end());

    int i = Even.size() - 1;
    int j = Odd.size() - 1;
    while (K--)
    {
        if (K % 2 == 1)
        {
            if (i >= 0)
            {
                maxSum += Even[i];
                i--;
            }
            else
            {
                return -1;
            }
        }
        else if (i >= 1 && j >= 1)
        {
            if (Even[i] + Even[i - 1] <= Odd[j] + Odd[j - 1])
            {
                maxSum += Odd[j] + Odd[j - 1];
                j -= 2;
            }
            else
            {
                maxSum += Even[i] + Even[i - 1];
                i -= 2;
            }
            K -= 2;
        }
        else if (j >= 1)
        {
            maxSum += Odd[j] + Odd[j - 1];
            j -= 2;
            K -= 2;
        }
    }
    return maxSum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int result = evenSumK(arr, n, k);
        cout << result << endl;
    }
    return 0;
}