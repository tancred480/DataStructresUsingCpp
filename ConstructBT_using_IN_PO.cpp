#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Defining the constructor function
typedef struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
} TreeNode;
// void BuildTree(int in[], int is, int ie, int po[], int ps, int pe, map<int, int> mp)
// {
//     if (is > ie || ps > pe)
//         return;
//     int r = mp[po[pe]];
//     cout << "->" << in[r] << "\n";
//     // cout << "Inorder :";
//     // for (int i = is; i <= ie; i++)
//     // {
//     //     cout << in[i] << " ";
//     // }
//     // cout << endl;
//     // cout << "Post-order :";
//     // for (int i = ps; i <= pe; i++)
//     // {
//     //     cout << po[i] << " ";
//     // }
//     cout << endl;
//     // left part
//     cout << in[r] << "left :";
//     BuildTree(in, is, (r - 1), po, ps, (ps + (r - is - 1)), mp);
//     // right part
//     cout << in[r] << "right :";
//     BuildTree(in, (r + 1), ie, po, (pe - (ie - r)), pe - 1, mp);
// }

//-------------------construct BT using inorder and post order---
TreeNode *BuildTree(vector<int> in, int is, int ie, vector<int> po, int ps, int pe, map<int, int> mp)
{
    if (ps > pe || is > ie)
        return NULL;
    TreeNode *root = new TreeNode(po[pe]);

    int r = mp[po[pe]];
    int numsLeft = r - is;
    root->left = BuildTree(in, is, r - 1, po, ps, ps + numsLeft - 1, mp);
    root->right = BuildTree(in, r + 1, ie, po, ps + numsLeft, pe - 1, mp);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() != postorder.size())
        return NULL;
    map<int, int> mp;
    int n = inorder.size();
    for (int i = 0; i < n; i++)
        mp.insert({inorder[i], i});

    return BuildTree(inorder, 0, n - 1, postorder, 0, n - 1, mp);
}
// method -2
TreeNode *helper3(vector<int> inorder, int inStart, int inEnd, vector<int> postorder, int postIndex)
{
    if (postIndex < 0 || inStart > inEnd)
        return NULL;

    TreeNode *root = new TreeNode(postorder[postIndex]);
    int inIndex;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (root->val == inorder[i])
        {
            inIndex = i;
            break;
        }
    }
    root->left = helper3(inorder, inStart, inIndex - 1, postorder, postIndex - (inEnd - inIndex) - 1);
    root->right = helper3(inorder, inIndex + 1, inEnd, postorder, postIndex - 1);

    return root;
}
TreeNode *buildTree3(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() != postorder.size())
        return NULL;

    return helper3(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
}
//----------------------------
// construct BT using pre-order and inorder
TreeNode *helper2(vector<int> inorder, int is, int ie, vector<int> preorder, int preStart)
{
    if (preStart >= preorder.size() || is > ie)
        return NULL;
    TreeNode *root = new TreeNode(preorder[preStart]);
    int inIndex;
    for (int i = is; i <= ie; i++)
        if (root->val == inorder[i])
        {
            inIndex = i;
            break;
        }
    root->left = helper2(inorder, is, inIndex - 1, preorder, preStart + 1);
    root->right = helper2(inorder, inIndex + 1, ie, preorder, preStart + (inIndex - is) + 1);
    return root;
}
TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder)
{

    return helper2(inorder, 0, inorder.size() - 1, preorder, 0);
}
int main()
{
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int po[] = {8, 4, 5, 2, 6, 7, 3, 1};
    map<int, int> mp;
    for (int i = 0; i < 8; i++)
        mp.insert({in[i], i});

    return 0;
}