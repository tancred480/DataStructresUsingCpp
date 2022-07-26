#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int *setValue(int a[], int size)
{
    int i = 0;
    while (i < size)
    {
        printf("\nEnter the value at %d index :", i);
        scanf("%d", &a[i]);
        i++;
    }
    return a;
}

int linearSearch(int a[], int size, int data)
{
    int i = 0;
    while (a[i] != data && i < size)
    {
        i++;
    }
    if (i <= size - 1)
    {
        printf("\nValue found at index %d ", i);
        return i;
    }
    else
    {
        printf("\nValue not found in the list");
        return -1;
    }
}

int *SelectionSort(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (a[index] > a[j])
            {
                index = j;
            }
        }
        if (index != i)
        {
            printf("\nchanging getting done at index %d", i);
            int temp = a[i];
            a[i] = a[index];
            a[index] = temp;
        }
    }
    return a;
}

void display(int a[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("\t %d", a[i]);
    }
}

int *BubbleSort(int a[], int size)
{
    for (int i = 0; i < size + 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return a;
}

int BinarySearch(int a[], int size, int data)
{
    int low, mid, high;
    low = 0;
    high = size - 1; //because we are dealing with index

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == data)
        {
            printf("\nValue found at index :%d", mid);
            return mid;
        }
        if (a[mid] > data)
        {
            high = mid - 1; //[11,13,20,34,35,39,40]
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("\nValue not found in list .");
    return -1;
}
//Recursive Approach
int BinarySearch2(int a[], int data, int low, int high)
{
    int mid = (low + high) / 2;
    if (low > high)
    {
        printf("\nValue not found in list .");
        return -1;
    }
    if (a[mid] == data)
    {
        printf("\nValue found at index :%d", mid);
        return a[mid];
    }
    if (a[mid] > data)
    {
        high = mid - 1;
        BinarySearch2(a, data, low, high);
    }
    else
    {
        low = mid + 1;
        BinarySearch2(a, data, low, high);
    }
}

int main()
{
    /*  int n;
    printf("\nEnter the size of the Array :");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));

    setValue(arr, n);
    linearSearch(arr, n, 3);

    SelectionSort(arr, n);
    //   BubbleSort(arr,n);

    display(arr, n);

    int element = 0;
    printf("\nEnter value to be searched in list :");
    scanf("%d", &element);
    BinarySearch(arr, n, element);
*/
    printf("\nBinary Search Version 2 \n");
    int a[7] = {11, 13, 20, 34, 35, 39, 40};

    int data = BinarySearch2(a, 35, 0, 7 - 1);
    printf("\n %d", data);
    return 0;
}