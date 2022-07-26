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

void InsertNewBST(struct Node *root, int data)
{
    struct Node *prev = NULL;
    // to store the previous(parent) node so as to check the condition
    //  i.e (wheather the newnode data is greater than the parent data so as
    //  to insert the new node at left or right)
    while (root != NULL)
    {
        prev = root;
        if (root->data == data)
        {
            printf("Already in the tree");
            return;
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *newNode = createNode(data);
    if (root == NULL)
    {
        if (data < prev->data)
        {
            prev->left = newNode;
        }
        else if (data > prev->data)
        {
            prev->right = newNode;
        }
    }
}
struct Node *DeleteNodeBST(struct Node *root, int data)
{
    struct Node *p = root;
    struct Node *parent = NULL;
    while (p->data != data)
    {

        if (data == p->data)
        {
            break;
        }
        if (data < p->data)
        {
            parent = p;
            p = p->left;
        }
        else
        {
            parent = p;
            p = p->right;
        }
    }
    if (p->left == NULL)
    {
        p = p->right;
    }
    else if (p->left != NULL)
    {
        struct Node *ptr = p->left;
        p->data = p->right->data;
        p->right = p->right->right;
        p->left = p->left->left;
        while (p->left != NULL)
        {

            p = p->left;
        }

        p->left = ptr;
    }
    return root;
}
int main()
{
    struct Node *root = createNode(45);

    InsertNewBST(root, 10);
    InsertNewBST(root, 50);

    InsertNewBST(root, 55);
    InsertNewBST(root, 4);
    InsertNewBST(root, 7);

    InOrderTraversal(root);

    root = DeleteNodeBST(root, 55);
    printf("\nAfter deletion\n");
    InOrderTraversal(root);
    return 0;
}