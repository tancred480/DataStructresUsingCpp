#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*Binary Heap can be visualized as array as complete
binary tree
Arr[0] elements will be treated as root
length(A) - size of array
heapSize(A) - size of heap
Generally used when we are dealing with minimum
and maximum elements
for ith node

 MIN_HEAP => here root node will always be less than the child nodes of it
 MAX_HEAP => here root node will always be greater than the child nodes of it.

formula for finding the parent of node of a node at ith position
also its left and right child node of that particular ith node
VERY IMPORTANT formula do remember it

 -------------------------
 | (i-1)/2   | Parent     |
 -------------------------
 | (2*i)+1   | Left child |
 -------------------------
 | (2*i)+2   | Right child|
 --------------------------

 **Advantages
 :can be of two types :min heap && max heap
 :Min heap keeps smallest and max heap keep largest
 element at top
 :O(1) for dealing with min or max elements

 **DisAdvantages
 :Random access not possible
 :Only min or max elements is available for  accessibility

*/
int c, heapsize;

void max_heapify(int a[], int i)
{
    int l, r, largest, temp;
    l = 2 * i;
    r = 2 * i + 1;
    if (l <= heapsize && a[l] > a[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if (r <= heapsize && a[r] > a[largest])
    {
        largest = r;
    }
    if (largest != l)
    {
        temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        max_heapify(a, largest);
    }
}
void build_max_heap(int a[])
{
    int i;
    for (i = c / 2; i >= 1; i--)
    {
        max_heapify(a, i);
    }
}

int extract_max(int a[])
{
    int max, temp;
    max = a[1];
    temp = a[1];
    a[1] = a[heapsize];
    a[heapsize] = temp;
    heapsize--;
    max_heapify(a, 1);
    return max;
}
int main()
{
    int a[11] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    heapsize = c = 10;
    for (int i = 1; i <= c; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n---\n");
    build_max_heap(a);
    printf("%d", a[1]);

    return 0;
}