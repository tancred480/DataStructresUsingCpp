#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int val;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *createNode(int value)
{
    treenode *result = malloc(sizeof(treenode));
    if (result != NULL)
    {
        result->left = NULL;
        result->right = NULL;
    }
    result->val = value;
    return result;
}

void printRecTree(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d \n", root->val);
    printRecTree(root->left);
    printRecTree(root->right);
}

int size_of_tree(treenode *root, int cnt)
{
    if (root == NULL)
        return cnt;
    size_of_tree(root->left, cnt = cnt + 1);
    size_of_tree(root->right, cnt = cnt + 1);
}

int main()
{
    treenode *n1 = createNode(10);
    treenode *n2 = createNode(11);
    treenode *n3 = createNode(12);
    treenode *n4 = createNode(13);
    treenode *n5 = createNode(14);
    treenode *n6 = createNode(15);

    n1->left = n2;
    n1->right = n3;

    n2->left = n6;

    n3->left = n4;
    n3->right = n5;

    printRecTree(n1);
    int size = size_of_tree(n1, 0);
    return 0;
}