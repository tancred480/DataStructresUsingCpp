#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    //1D Dynamic Array
    int *array, n;
    printf("\nEnter array size : ");
    scanf("%d", &n);
    printf("\nEnter array elements :\n");
    array = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }

    //2D Dynamic Array
    int r, c;
    printf("Enter no of rows and colmns");
    scanf("%d %d", &r, &c);

    int *arr[r]; //array of pointers at each row head
    for (int i = 0; i < r; i++)
    {
        arr[i] = (int *)malloc(sizeof(int)); //allocating space to each individual array at each row
    }

    //Note that arr[i][j] is same as *(*(arr+i)+j)
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++2)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
*/
    //2D Array using pointer to pointer concept
    int row = 3, col = 4, len = 0;
    int *ptr, **arr;
    int count = 0, i, j;

    len = sizeof(int *) * row + sizeof(int) * col * row;
    arr = (int **)malloc(len);
    ptr = (int *)(arr + row);

    for (i = 0; i < row; i++)
        arr[i] = (ptr + col * i);

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            arr[i][j] = count++;
        }
    }
    printf("\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}