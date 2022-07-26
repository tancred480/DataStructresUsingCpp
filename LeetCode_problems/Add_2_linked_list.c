#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *head){
    struct Node *p=head;
    while(p->next!=NULL){
        printf("\t%d",p->data);
        p=p->next;
    }
        printf("\t%d",p->data);
}

struct Node * InsertFromHead(struct Node *head,int data){
    struct Node *newNode =(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=head;

    head=newNode;

    return head;
}

struct Node * InsertInBetween(struct Node *head,int data,int index){
    int i=0;
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));

    newNode->data=data;

    struct Node *p=head;
    
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
    
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newNode;
    newNode->next=NULL;

    return head;
}

//Reverse a given linked list

struct Node* reverseList(struct ListNode* head){
    struct Node* prev=NULL;
    struct Node* curr=head;
    while(curr!=NULL){
        struct Node* tempNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=tempNode;
    }
    head=prev;
    return head;
}
struct Node * DeleteFromHead(struct Node *head){
    struct Node *p=head;

    head=p->next;
    free(p);

    return head;

}

struct Node * DeleteInBetween(struct Node *head,int index){
    int i=0;
    struct Node *p=head;
    struct Node *q=p->next;
    while(i!=index-1 && q->next!=NULL){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct Node * DeleteInBetweenV2(struct Node *head,int index){
    int i=0;
    struct Node *p=head;

    while(i!=(index-1)){
        p=p->next;
        i++;
    }
    p=p->next->next;

    return head;
}

struct Node * DeleteFromTail(struct Node *head){
    struct Node *p=head;
    while(p->next->next!=NULL){
        p=p->next;
    }
    free(p->next);
    p->next=NULL;

    return head;
}

struct Node * UpdateInBetween(struct Node *head,int data,int index){
    int i=0;
    struct Node *p=head;

    while(i!=index && p->next!=NULL){
        p=p->next;
        i++;
    }
     if(i==index){
         p->data=data;
     }
     return head;

}

long ReverseNumber(int n,struct Node *head){
    long revNum=0,rem=0;
    while(n!=0){
        rem=n%10;
        revNum=revNum*10 + rem;
        n=n/10;
    }
    if(head->data==0){
        revNum=revNum*10;
    }
    return revNum;
}

struct Node * Add_2_Linked_list(struct Node *l1,struct Node *l2){
    struct Node *p=l1;
    
    struct Node *newLinkedList=(struct Node *)malloc(sizeof(struct Node));
    int c1=0,c2=0;
    while(p!=NULL){
        c1=c1*10 + p->data;
        p=p->next;
    }
    p=l2;
    while(p!=NULL){
        c2=c2*10 + p->data;
        p=p->next; 
    }
    int n1=ReverseNumber(c1,l1);
    int n2=ReverseNumber(c2,l2);
    

    printf("\n%d",n1);
    printf("\n%d",n2);

    int newNumber=n1+n2;

    printf("\nAddition of 2 numbers : %d ",newNumber);
    newLinkedList->data=newNumber%10;
    newLinkedList->next=NULL;
    p=newLinkedList;
    newNumber=newNumber/10;
    while(newNumber!=0){
        struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
        newNode->data=newNumber%10;
        newNode->next=NULL;

        p->next=newNode;
        p=p->next;
        
        newNumber=newNumber/10;
    }
    printf("\nNew Linked List :-");
    LinkedListTraversal(newLinkedList);
    return newLinkedList;
}

int main(){
    struct Node *rl1=(struct Node *)malloc(sizeof(struct Node));
    rl1->data=0;

    struct Node *rl2=(struct Node *)malloc(sizeof(struct Node));
    rl2->data=8;
    rl1->next=rl2;

    rl2->next=NULL;


    struct Node *pl1=(struct Node *)malloc(sizeof(struct Node));
    pl1->data=6;

    struct Node *pl2=(struct Node *)malloc(sizeof(struct Node));
    pl2->data=7;
    pl1->next=pl2;

    pl2->next=NULL;

    
    InsertFromTail(rl1,6);
    InsertFromTail(rl1,5);
    InsertFromTail(rl1,6);
    InsertFromTail(rl1,8);
    InsertFromTail(rl1,3);
    InsertFromTail(rl1,5);
    InsertFromTail(rl1,7);
    LinkedListTraversal(rl1);

    printf("\n");

    InsertFromTail(pl1,8);
    InsertFromTail(pl1,0);
    InsertFromTail(pl1,8);
    InsertFromTail(pl1,5);
    InsertFromTail(pl1,8);
    InsertFromTail(pl1,9);
    InsertFromTail(pl1,7);
    LinkedListTraversal(pl1);

    Add_2_Linked_list(rl1,pl1);
   return 0;

}