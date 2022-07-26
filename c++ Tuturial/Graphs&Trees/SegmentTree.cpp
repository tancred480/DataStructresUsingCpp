#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Segment Tree
arr[] ={8,2,5,1,4,5,3,9,6,10};

*/
const int N = 1e9 + 7;
int segmentTree[4 * 10010];
int build(int index, vector<int> &arr, int low, int high)
{
    if (low == high)
    {
        cout << index << ":" << arr[low] << "\n";
        return segmentTree[index] = arr[low];
    }
    int mid = (high + low) / 2; // divide and conquere approach
    int left = build(2 * index + 1, arr, low, mid);
    int right = build(2 * index + 2, arr, mid + 1, high);

    cout << index << ":" << max(left, right) << "\n";
    return segmentTree[index] = max(left, right);
}
/*
1)Completely lies
2)if does not lies
3)Overlaps
*/
int queryMaxInRange(int index, int low, int high, int l, int r)
{
    if (low >= l && high <= r)
    { // completely falls in the range so this will definitely store the max in that range
        return segmentTree[index];
    }
    if (low < l && high > r)
    { // does not lie in the range
        return INT_MIN;
    }
    // if overlaps then call for both left and right child of segment tree
    int mid = (low + high) / 2;
    int left = queryMaxInRange(2 * index + 1, low, mid, l, r);       // left child
    int right = queryMaxInRange(2 * index + 2, mid + 1, high, l, r); // right child
    return max(left, right);
}
int main()
{
    vector<int> v = {8, 2, 5, 1, 4, 5, 3, 9, 6, 10};
    build(0, v, 0, v.size() - 1);
    return 0;
}

/*
Range Sum LeetCode Question using segment Tree
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
        if(sl>=l and sr<=r) return seg[index];//completly overlap
        //partial overlap
        int mid = (sl+sr)/2;
        int left = getSum(2*index+1,sl,mid,l,r);
        int right = getSum(2*index+2,mid+1,sr,l,r);
        return left+right;
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(n*4);
        build(0,nums,0,n-1);
    }
    void update(int index, int val) {

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
