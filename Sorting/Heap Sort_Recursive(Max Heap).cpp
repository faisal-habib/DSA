/**
Time:
O(N log N)

Space:
O(1) / In-place

Not Stable
(If duplicate values are given as input, output will maintain given input order)
Adaptive
(A sorting algorithm falls into the adaptive sort family if it takes advantage of existing order in its input)

Resources:
https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/tutorial/
*/

#include<bits/stdc++.h>
using namespace std;

#define MX 50

int leftChild(int n)
{
    return (n<<1);  // n*(2^1)
}
int rightChild(int n)
{
    return (n<<1)+1;  // n*(2^1)+1
}

void maxHeapify(int heap[],int sz,int pos)  // log N
{
    int largestValInd=pos;
    int l=leftChild(pos);
    int r=rightChild(pos);

    if(l<=sz && heap[l]>heap[largestValInd]) largestValInd=l;
    if(r<=sz && heap[r]>heap[largestValInd]) largestValInd=r;

    if(largestValInd!=pos)
    {
        int tmp=heap[pos];
        heap[pos]=heap[largestValInd];
        heap[largestValInd]=tmp;
        // right now value of largestValInd = value of pos, our target is to place this value in right place. So call maxHeapify from largestValInd again
        maxHeapify(heap,sz,largestValInd);
    }
}

void buildMaxHeap(int heap[],int sz)
{
    /* Elements from heap[sz/2+1] to heap[sz] are leaf nodes and each node is 1 element heap.
       We'll use maxHeapify function in a bottom up manner on remaining nodes, so that we can cover each node of tree.*/
    for(int i=sz/2;i>=1;i--)    // traversing N/2 times ~ N times
    {
        maxHeapify(heap,sz,i);
    }
}

void printIncreasingOrder(int heap[], int sz)
{
    cout<<"Increasing order: ";
    for(int i=1;i<=sz;i++) cout<<heap[i]<<" ";
    cout<<endl;
}

void printDecreasingOrder(int heap[], int sz)
{
    cout<<"Decreasing order: ";
    for(int i=sz;i>=1;i--) cout<<heap[i]<<" ";
    cout<<endl;
}

void heapSort(int heap[],int sz)
{
    int N = sz;
    buildMaxHeap(heap,sz);

    while(sz>1)
    {
        swap(heap[1], heap[sz]);
        sz--;
        maxHeapify(heap,sz,1);
    }
}

int main()
{
    int ar[MX],sz;
    cout<<"Give size of the array: ";
    cin>>sz;
    cout<<"Give elements of array: ";
    for(int i=1;i<=sz;i++) cin>>ar[i];

    heapSort(ar,sz);

    printIncreasingOrder(ar, sz);
    printDecreasingOrder(ar, sz);
}
/*
8
0 90 85 80 70 60 55 50

5
1 2 -5 4 3

10
3 6 0 5 1 3 7 3 4 1
*/
