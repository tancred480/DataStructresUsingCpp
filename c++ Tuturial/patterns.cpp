#include <iostream>6
using namespace std;

int fact(int n)
{
    int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
};

int main()
{
    /* int row, col;
    cout << "enter number of rows and columns to print rectangle :" << endl;
    cin >> row >> col;
    //Simple rectangle
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
    //hollow rectangle
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if ((i == 0) || (i == (row - 1)))
            {
                cout << "* ";
            }
            else if ((j == 0) || (j == (col - 1)))
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    //Inverted Half Pyramid;
    cout << "enter number of rows for inverted half pyramid :";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    //Half pyramid after 180deg rotation
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if ((j - i) >= 0)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    //half pyramid using numbers
    int k;
    cout << "Enter Half pyramid using numbers :";
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    //Floyd's Triangle
    int cnt = 1;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << cnt << "  ";
            cnt++;
        }
        cout << endl;
    }

    //Butterfly Pattern
    int b;
    cout << "Enter value for n to print Butterfly pattern :";
    cin >> b;
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        int space = 2 * b - 2 * i;
        for (int j = 1; j <= space; j++)
        {
            cout << "  ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = b; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        int space = 2 * b - 2 * i;
        for (int j = 1; j <= space; j++)
        {
            cout << "  ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    //Inverted Pattern
    int p;
    cout << "Enter n for Inverted Pattern :";
    cin >> p;
    for (int i = p; i >= 1; i--)
    {
        for (int j = 1; i >= j; j++)
        {
            cout << j << "  ";
        }
        cout << endl;
    }
    cout << endl;
    //0-1 Pattern;
    for (int i = 1; i <= p; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    //Rhombus Pattern
    int r, q;
    cout << "Enter value for R to print rhombus : ";
    cin >> r;
    q = 2 * r - 1;
    for (int i = r; i >= 1; i--)
    {
        for (int j = 1; j <= q; j++)
        {
            if (j < i)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
        q--;
    }

    //Number pattern
    int np;
    cout << "Enter value of n for Number Pattern : " << endl;
    cin >> np;

    for (int i = 1; i <= np; i++)
    {

        for (int k = 1; k <= (np - i); k++)
        {
            cout << "  ";
        }
        for (int l = 1; l <= i; l++)
        {
            cout << l << "  ";
        }
        cout << endl;
    }

    //Pallindromic Pattern
    int pp;
    cout << "enter the value of pp for palindromic patter :";
    cin >> pp;
    for (int i = 1; i <= pp; i++)
    {
        for (int j = 1; j <= (pp - i); j++)
        {
            cout << "  ";
        }
        for (int k = i; k >= 1; k--)
        {
            cout << k << " ";
        }
        for (int k = 2; k <= i; k++)
        {
            cout << k << " ";
        }
        cout << endl;
    }

    //printing advance pattern
    int ap;
    cout << "enter value for ap(advance pattern) :";
    cin >> ap;
    for (int i = 1; i <= ap; i++)
    {
        for (int j = 1; j <= (ap - i); j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = ap; i >= 1; i--)
    {
        for (int j = 1; j <= (ap - i); j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
*/
    //pascal Triangle
    int pst;
    cout << "Enter no of rows for pascal traingle Pattern : ";
    cin >> pst;
    for (int i = 0; i <= pst; i++)
    {
        for (int k = pst; k > i; k--)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            int binomialCoeff = fact(i) / (fact(i - j) * fact(j));
            cout << binomialCoeff << " ";
        }
        cout << endl;
    }

    return 0;
}