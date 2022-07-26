#include <iostream>

using namespace std;

int add(int a, int b)
{
    int xr = 0, carry;
    xr = a ^ b;
    carry = a & b;
    if (carry == 0)
    {
        return xr;
    }
    else
    {
        return add(xr, carry << 1);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, res = 0;
        //cout << "Enter value for n : ";
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            // cout << "enter i = " << i << endl;
            cin >> arr[i];
        }
        for (int j = 0; j < n; j++)
        {

            res = add(arr[j], res);
        }
        cout << res << endl;
    }
    return 0;
}
