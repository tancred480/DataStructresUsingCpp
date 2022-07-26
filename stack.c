#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        printf("\nstack is Empty");
        return 1;
    }else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size -1){
        printf("stack is Full");
        return 1;
    }else{
        return 0;
    }
}

void push(struct stack *ptr,int data){
    if(!isFull(ptr)){
        ptr->arr[ptr->top+1]=data;
        ptr->top++;
    }
}
int pop(struct stack *ptr){
    if(!isEmpty(ptr)){
        int a=ptr->arr[ptr->top];
        ptr->arr[ptr->top]=0;
        ptr->top--;
        return a;
    }
}
int peek(struct stack *ptr){
    if(!isEmpty(ptr)){
        int a=ptr->arr[ptr->top];
        return a;
    }
}

int main(){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=5;
    s->arr=(int *)malloc(s->size*sizeof(int));

    push(s,9);
    push(s,3);
    push(s,5);
    push(s,0);
    push(s,10);
    for(int i=0;i<s->size;i++){
        printf("\nvalue at %d is %d",i,s->arr[i]);
    }
        printf("\nvalue at top : %d",peek(s));
    return 0;
}