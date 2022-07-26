#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct ArrayADT
{
    int total_size;
    int used_size;
    int *arr; //pointing to the 1st element of the array
};

//pointer expects an address to be given to it;

void createArray(struct ArrayADT *a, int tSize, int uSize)
{
    // (*a).total_size=iSize its used for assigning value
    //* is used to access the value where as & is used to access the address store in that pointer vairable
    a->total_size = tSize;
    a->used_size = uSize;

    a->arr = (int *)malloc(tSize * sizeof(int)); //dynamically allocating the memory to the array;
}
struct ArrayADT *setValue(struct ArrayADT *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("\nEnter element at  %d index :", i);
        //scanf("%d",&(a->arr)[i]);
        scanf("%d", &a->arr[i]);
    }

    return a;
}
void showValues(struct ArrayADT *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n ", (a->arr)[i]);
    }
}
int main()
{
    struct ArrayADT marks;

    createArray(&marks, 10, 5); //we are passing the address here NOT the actual value
    setValue(&marks);
    showValues(&marks);
    free(&marks);
    return 0;
}

/*
struct ArrayADT{
     int total_size;
     int use_size;
     struct ArrayADT *arr;
};
int main(){
     int n=0,i=0;
     printf("\nEnter the size of array :\n");
     scanf("%d",&n);
    int * arr=(int *)malloc(n*sizeof(int));
    
     while(i<n){
         printf("\nEnter %d element of Array :",i);
         scanf("%d",&arr[i]);
         i++;
     }
    i=0;
    while(i<n){
        printf("\nElement at %d index is %d",i,arr[i]);
        i++;
    }
     return 0;

}
*/
