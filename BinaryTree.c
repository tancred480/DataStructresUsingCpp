#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}
struct Node *insertElement(struct Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data > root->data)
    {
        root->right = insertElement(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = insertElement(root->left, data);
    }
    return root;
}
void preOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("\t %d", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("\t%d", root->data);
    }
}

void InOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        InOrderTraversal(root->left);
        printf("\t%d", root->data);
        InOrderTraversal(root->right);
    }
}
int main()
{

    /*
            1
           / \
          /   \
         4    6 
        / \  / \
       3   8 9  10
      /       \
     12       32
     preOrder=1 4 3 12 8 6 9 32 10 
     inOrder=12 3 4 8 1 9 32 6 10
     postOrder=12 3 8 4 32 9 10 6 1
*/
    struct Node *root = createNode(1);
    /*struct Node *p1 = createNode(4);
    struct Node *p2 = createNode(6);
    root->left = p1;
    root->right = p2;

    struct Node *p3 = createNode(3);
    struct Node *p4 = createNode(8);

    p1->left = p3;
    p1->right = p4;

    struct Node *p5 = createNode(9);
    struct Node *p6 = createNode(10);

    p2->left = p5;
    p2->right = p6;

    struct Node *p7 = createNode(12);

    p3->left = p7;

    struct Node *p8 = createNode(32);

    p5->right = p8;*/
    for (int i = 0; i < 10; i++)
    {
        int s = 0;
        printf("\nEnter value for new node: ");
        scanf("%d", &s);
        insertElement(root, s);
    }

    printf("\nPre Order Traversal .\n");
    preOrderTraversal(root);

    printf("\nIn Order Traversal .\n");
    InOrderTraversal(root);

    printf("\nPost Order Traversal .\n");
    postOrderTraversal(root);
    return 0;
}