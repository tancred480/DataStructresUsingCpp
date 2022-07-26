#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node * next;
};

void LinkedListTraversal(struct Node * head){
    struct Node * p=head;

    do{
        printf("\n%d",p->data);
        p=p->next;
    }while(p!=head);
        printf("\n%d",p->data);
        p=p->next;
        printf("\n%d",p->data);
}
//This is different
struct Node * InsertAtFirst(struct Node *head,int data){
    struct Node *p=head;
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
//setting the last node to point to the newNode as this is our new head;
while(p->next!=head){
    p=p->next;
}
    p->next=newNode;

//changing the pointer of head to newNode    
    newNode->next=head;
    head=newNode;

    return head;
}

struct Node * InsertAtIndex(struct Node *head,int data,int index){
    int i=0;
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    struct Node * p=head;
    
    while(i!=index-1){
        p=p->next;
        i++;
    }
    newNode->next=p->next;
    p->next=newNode;
    return head;

}

struct Node * InsertFromTail(struct Node *head,int data){
    struct Node * newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;

    struct Node *p=head;
    
    while(p->next!=head){
        p=p->next;
    }
    p->next=newNode;
    newNode->next=head;

    return head;
}


//This is also different
struct Node * DeleteFromHead(struct Node *head){
    struct Node *p=head;
    struct Node *q=head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=p->next->next;
    head=head->next;
    free(q);

    return head;
}

struct Node * DeleteFromTail(struct Node *head){
    struct Node *p=head;
    struct Node *q=p->next;
    while(q->next!=head){ //or we can check (p->next->next!=head)
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    //p->next=p->next->next;
    free(q);

    return head;
}
int main(){ 
    struct Node * head=(struct Node *)malloc(sizeof(struct Node));

    struct Node * second=(struct Node *)malloc(sizeof(struct Node));

    struct Node * third=(struct Node *)malloc(sizeof(struct Node));

    struct Node * fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=head;

    printf("All Elements of Linked List ");
    printf("\nBefore Insertion\n");
    LinkedListTraversal(head);

    head=InsertAtFirst(head,19);
    printf("\nAfter Insertion\n");
    LinkedListTraversal(head);

    printf("\nBefore Insertion\n");
    LinkedListTraversal(head);

    head=InsertFromTail(head,24);
    printf("\nAfter Insertion\n");
    LinkedListTraversal(head);

    printf("\nAfter Deletion From head \n");
    head=DeleteFromHead(head);
    LinkedListTraversal(head);

    
    printf("\nAfter Deletion From Tail\n");
    head=DeleteFromTail(head);
    LinkedListTraversal(head);

    
    return 0;

}