#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// bhai isko sahi kr galat hai
struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};
//---------BFS-Traversal---
void BFS(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}
//-----------------------------------------
//---------------DFS-Traversal ------------
// 1st --Inorder -DFS
void InOrder(TreeNode *root)
{
    if (!root)
        return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}
// Iterative inorder
vector<int> InOrder2(TreeNode *root)
{
    stack<TreeNode *> st;
    TreeNode *curr = root;
    vector<int> order_in;
    while (true)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                break;
            curr = st.top();
            st.pop();
            order_in.push_back(curr->val);
            curr = curr->right;
        }
    }
    return order_in;
}
// 2nd --preOrder -DFS
void preOrder(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// pre-order iterative
void preOrder2(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        auto node = st.top();
        cout << node->val << " ";
        st.pop();
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
}
// 3rd --postOrder -DFS
void postOrder(TreeNode *root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}
//-----------------------------------
// Lowest Common Ancestor in a Binary Tree----------
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root; // founded the answer
}
// lowest common ancestor in a BST----------
TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *ans = root;
    TreeNode *curr1 = root;
    TreeNode *curr2 = root;
    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1 == curr2)
        {
            ans = curr1;
        }
        if (p->val > curr1->val)
            curr1 = curr1->right;
        else if (p->val < curr1->val)
            curr1 = curr1->left;
        else
            break;
        if (q->val > curr2->val)
            curr2 = curr2->right;
        else if (q->val < curr2->val)
            curr2 = curr2->left;
        else
            break;
    }
    return ans;
}
//-------------------------------------------------
//---insertion in bst through Iterative approach---
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
        return new TreeNode(val);
    TreeNode *curr = root;
    while (1)
    {
        if (curr->val > val)
        {
            if (curr->left != NULL)
                curr = curr->left;
            else
                curr->left = new TreeNode(val);
            break;
        }
        else if (curr->val < val)
        {
            if (curr->right != NULL)
                curr = curr->right;
            else
                curr->right = new TreeNode(val);
            break;
        }
    }
    return root;
}

// Searching in a Binary Search Tree
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->val == val)
        return root;

    if (root->val < val)
    {
        return searchBST(root->right, val);
    }

    return searchBST(root->left, val);
}

/*
//Iterative Approach
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL){
            if(root->val==val) return root;
            else if(root->val<val) root = root->right;
            else root = root->left;
        }
        return root;
    }
};
*/
void Vertical_Traverse(TreeNode *root, int mark, map<int, vector<int>> &hm)
{
    if (root == NULL)
        return;
    if (hm.find(mark) != hm.end())
    {
        hm[mark].push_back(root->val);
    }
    else
    {
        hm.insert({mark, {root->val}});
    }
    Vertical_Traverse(root->left, mark - 1, hm);
    Vertical_Traverse(root->right, mark + 1, hm);
}
void BottomViewBT(TreeNode *root)
{
    map<int, int> mp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0}); // BFS
    while (!q.empty())
    {
        auto node = q.front().first;
        int mark = q.front().second;
        mp[mark] = node->val;
        q.pop();
        if (node->left)
            q.push({node->left, mark - 1});
        if (node->right)
            q.push({node->right, mark + 1});
    }
    vector<int> bottomView;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        bottomView.push_back(it->second);
    }
}
//--------Invert Binary Tree----------
void Invert(TreeNode *root)
{
    if (root == NULL)
        return;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    Invert(root->left);
    Invert(root->right);
}
TreeNode *invertTree(TreeNode *root)
{
    Invert(root);
    return root;
}
//--------------------------------------
//-------Width of a binary Tree---------
#define ll long long
int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode *, long long>> q;
    int width = 0;
    q.push({root, 0}); // node and index since root has index 0 and their child i.e left = 2*0+1 & right 2*0+2;
    while (!q.empty())
    {
        int n = q.size();
        int start = q.front().second, end = q.back().second;
        width = max(width, end - start + 1);
        for (int i = 0; i < n; i++)
        {
            auto node = q.front().first;
            int index = q.front().second;
            q.pop();
            if (node->left)
                q.push({node->left, (1ll * 2 * index + 1)});
            if (node->right)
                q.push({node->right, (1ll * 2 * index + 2)});
        }
    }
    return width;
}
int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(0);
    root->left->left = new TreeNode(5);

    map<int, vector<int>> hm;
    Vertical_Traverse(root, 0, hm);
    for (auto &el : hm)
    {
        cout << el.first << ": ";
        for (auto &child : el.second)
        {
            cout << child << " ";
        }
        cout << endl;
    }
    // InOrder2(root);
    // cout << endl;
    // preOrder(root);

    // BFS(root);
    return 0;
}