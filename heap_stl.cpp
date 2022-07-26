#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* HEAP

if parent = i
then left-child = (2*i +1)
then right-child = (2*i +2)

if given child i
the parent = ceil(i/2 -1)->will give parent index

if height = h
then max nodes only at height h = 2^h
and max nodes in the entire tree = 2 ^(h+1) -1;

--in a complete binary tree --
*Range of leaves = (N/2 +1) to N
*Range of internal nodes = (1 to N/2).
-heap is a complete binary tree

--important points--
>max-heap=>Root node should be greater than all left and right
subtree nodes and it is recursively for all subtree
A leaf node always follows the min/max heap property
therefor we have only 1 node.

>ith node needs to be re-arranged to maintain heap property.
NOTE: Except ith node, Entire tree is a heap.
->Re-arranged recursively

>HEAPIFY-The process of re-arranging the HEAP by comparing
each parent with its children recursively is known as heapify.

**Heaps are already implemented in stl in the priority queue**
1)MAXHEAP
priority-queue<int,vector<int>>

2)MINHEAP
priority-queue<int,vector<int>,greater<int>>

*/
int main()
{
    // simple max-heap using STL
    priority_queue<int, vector<int>> maxheap;
    maxheap.push(2);
    maxheap.push(4);
    maxheap.push(5);
    maxheap.push(8);
    cout << maxheap.top() << endl;
    maxheap.pop();
    cout << maxheap.top() << endl
         << endl;

    // Simple minHeap using STL
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(1);
    minheap.push(-4);
    minheap.push(3);
    minheap.push(2);
    minheap.push(0);
    cout << minheap.top() << endl;
    minheap.pop();
    cout << minheap.top() << endl;
    //------------------------------
    vector<int> v1 = {20, 30, 40, 25, 51, 32};
    make_heap(v1.begin(), v1.end());
    cout << v1.front() << endl;

    // pushing new element in to heap
    v1.push_back(232);
    push_heap(v1.begin(), v1.end());
    cout << v1.front() << endl;

    // poping out front heap
    pop_heap(v1.begin(), v1.end());
    v1.pop_back();
    cout << v1.front() << endl;

    sort_heap(v1.begin(), v1.end());
    for (auto &el : v1)
        cout << el << " ";
    cout << endl;
    // sort_heap ->After calling this function the container is
    // no longer a heap
    sort_heap(v1.begin(), v1.end());
    for (auto &el : v1)
        cout << el << " ";
    cout << endl;

    /*
    is_heap() : This function is used to check whether the container
    is heap or not Generally,in most implementations, the reverse sorted container
    is considered as heap.Returns true if container is heap else return false.

    is_heap_until() : This function returns the iterator to the position
    till the container is the heap.Generally, in most implementations, the
    reverse sorted container is considered as heap.
    */
    cout << is_heap(v1.begin(), v1.end()) << endl;
    auto it = is_heap_until(v1.begin(), v1.end());
    // Displaying heap range elements.
    for (auto it1 = v1.begin(); it1 != it; it++)
    {
        cout << *it1 << " ";
    }
    return 0;
}