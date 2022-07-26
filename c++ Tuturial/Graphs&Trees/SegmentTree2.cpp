#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Segment Tree is always be 4*n max
arr[] ={8,2,5,1,4,5,3,9,6,10};
*/
const int N = 1e9 + 7;
class SGTree
{
public:
    vector<int> segmentTree;
    SGTree(int n)
    {
        segmentTree.resize(4 * n + 1);
    }

public:
    int build(int index, vector<int> &arr, int low, int high)
    {
        if (low == high)
        {
            segmentTree[index] = arr[low];
        }
        int mid = (low + high) / 2;
        int left = build(2 * index + 1, arr, low, mid);
        int right = build(2 * index + 2, arr, mid + 1, high);
        return segmentTree[index] = min(left, right);
    }
    int queryMinInRange(int index, int low, int high, int l, int r)
    {
        if (low >= l && high <= r) // 2>=2 && 3<=5 i.e 2-3 completely lies in range of 2-5 that why return seg val at that index
        {                          // completely falls in the range so this will definitely store the max in that range
            return segmentTree[index];
        }
        if (r < low or high < l) // 5<0 or 9<2 skip then else if the case is like
        {                        // does not lie in the range
                                 // 6-9 //5<6 or 9<2
            return INT_MAX;
        }
        // if overlaps then call for both left and right child of segment tree
        int mid = (low + high) / 2;
        int left = queryMinInRange(2 * index + 1, low, mid, l, r);       // left child
        int right = queryMinInRange(2 * index + 2, mid + 1, high, l, r); // right child
        return min(left, right);
    }
    void pointUpdate(int index, int low, int high, int i, int val)
    {
        if (low == high) // it means we reached the leaf node who stores value of arr[i]
        {
            segmentTree[index] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (mid >= i)
        {
            pointUpdate(2 * index + 1, low, mid, i, val);
        }
        else
        {
            pointUpdate(2 * index + 2, mid + 1, high, i, val);
        }
        segmentTree[index] = min(segmentTree[2 * index + 1], segmentTree[2 * index + 2]); // going up and updating segment tree
    }
};

/*
1)Completely lies
2)if does not lies
3)Overlaps
suppose [0-9] we want to get min in range of 2-5
*/

int main()
{
    vector<int> v = {8, 2, 5, 1, 4, 5, 3, 9, 6, 10};
    int n = v.size();
    SGTree obj1(n);
    obj1.build(0, v, 0, n - 1);
    return 0;
}

/*
Range Sum Mutable LeetCode Question
Link - https://leetcode.com/problems/range-sum-query-mutable/discuss/2326511/Range-Sum-Query-Mutable-cpp-Solution-using-segment-Trees
class NumArray {
public:
    vector<int> seg;
    int n;
    void build(int index,vector<int>& nums,int l,int r){
        if(l==r){
            seg[index] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*index+1,nums,l,mid);
        build(2*index+2,nums,mid+1,r);
        seg[index] = seg[2*index+1]+seg[2*index+2];
    }
    int getSum(int index,int sl,int sr,int l,int r){
        if(sr<l or sl>r) return 0;//no over-lap
-        if(sl>=l and sr<=r) return seg[index];//completly overlap
        //partial overlap
        int mid = (sl+sr)/2;
        int left = getSum(2*index+1,sl,mid,l,r);
        int right = getSum(2*index+2,mid+1,sr,l,r);
        return left+right;
    }
    void updateQuery(int index,int sl,int sr,int cidx,int val){
        if(sr==sl){
            seg[index] =  val;
            return;
        }
        int mid = (sr+sl)/2;
        if(cidx<=mid){//go left side
            updateQuery(2*index+1,sl,mid,cidx,val);
        }else{
            updateQuery(2*index+2,mid+1,sr,cidx,val);
        }
        seg[index] = seg[2*index+1]+seg[2*index+2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(n*4);
        build(0,nums,0,n-1);
    }
    void update(int index, int val) {
        updateQuery(0,0,n-1,index,val);
    }
    int sumRange(int left, int right) {
        return getSum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
