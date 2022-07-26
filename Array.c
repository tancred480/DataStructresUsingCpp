#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void display(int a[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("\t%d", a[i]);
    }
    printf("\n");
}
void insertAtIndex(int a[], int data, int index, int size)
{
    int temp = 0;
    for (int i = 0; i < size + 1; i++)
    {
        if (i == index)
        {
            temp = a[index]; //[1,2,3,4,5,6,7]
            a[i] = data;
        }
        else if (i > index)
        {
            int ref = a[i];
            a[i] = temp;
            temp = ref;
        }
    }
};
//shifting elements from last elements
void insertInBetween(int a[], int data, int index, int size)
{
    for (int i = size - 1; i >= index; i--)
    {
        a[i + 1] = a[i];
    }
    a[index] = data;
}
//deleting element and then shifting all the elements (here we are just over writting the values);
int *deleteAtIndex(int a[], int index, int size)
{
    for (int i = index; i < size; i++)
    {
        a[i] = a[i + 1];
    }
    return a;
}
int main()
{
    int arr[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9;

    printf("\nAfter insertion \n");

    insertAtIndex(arr, 13, 4, size);
    size++;
    display(arr, size);

    insertAtIndex(arr, 98, 5, size);
    size++;
    display(arr, size);

    insertInBetween(arr, 45, 4, size);
    size++;
    display(arr, size);

    printf("\nAfter Deletion");
    deleteAtIndex(arr, 2, size);
    size--;
    display(arr, size);
    return 0;
}