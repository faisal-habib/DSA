/**
The Bottom-Up merge sort approach uses iterative methodology. It starts with the “single-element” array,
and combines two adjacent elements and also sorting the two at the same time. The combined-sorted arrays
are again combined and sorted with each other until one single unit of sorted array is achieved.

Time:
The list of size N is divided into a max of (log N) parts
and the merging of all sublists into a single list takes O(N) time.
Worst case: O(N log N)

Space:
O(N)

Stable
(If duplicate values are given as input, output will maintain given input order)
Not Adaptive
(A sorting algorithm falls into the adaptive sort family if it takes advantage of existing order in its input)

* advantage of using iterative merge sort is to avoid recursion stack overflow

Resources:
https://www.youtube.com/watch?v=6pV2IF0fgKY
https://www.youtube.com/watch?v=Eid6JEHZ7nw
https://www.happycoders.eu/algorithms/merge-sort/#Natural_Mergesort_-_Example
*/

#include<bits/stdc++.h>
using namespace std;

#define MX 50

void _merge(int ar[], int low, int mid, int high)
{
    int leftInd=low, rightInd=mid+1, temp[high-low+1], tempInd = 0;

    while(leftInd<=mid && rightInd<=high)
    {
        if(ar[leftInd] <= ar[rightInd]) temp[tempInd++] = ar[leftInd++];
        else temp[tempInd++] = ar[rightInd++];
    }

    while(leftInd <= mid) temp[tempInd++] = ar[leftInd++];

    while(rightInd<=high) temp[tempInd++] = ar[rightInd++];

    for(int i=0; i<tempInd; i++) ar[low++] = temp[i];
}

void _mergeSort(int ar[], int sz)
{
    int subArrSz, low, high, i, mid;
    for(subArrSz=2; subArrSz<=sz; subArrSz*=2)
    {
        /* here i means starting point of different sub array */
        /* if sub array size is 2, first i=0, that means we'll compare and merge values in position 0 & 1.
        Then i will be 2, so we'll compare and merge values in position 2 & 3 and so on... */
        for(i=0; i+subArrSz-1<sz; i+=subArrSz)
        {
            low = i, high = i+subArrSz-1, mid = (low+high)/2;
            _merge(ar, low, mid, high);
        }
    }
    if(subArrSz/2<sz) _merge(ar, 0, subArrSz/2-1, sz-1);    // if array size is not power of 2, then some elements will be left over
}

int main()
{
    int ar[MX],sz;
    cout<<"Give size of the array: ";
    cin>>sz;
    cout<<"Give elements of array: ";
    for(int i=0;i<sz;i++) cin>>ar[i];

    _mergeSort(ar,sz);
    cout<<"after sorting: ";
    for(int i=0;i<sz;i++) cout<<ar[i]<<" ";
    cout<<endl;
}

/*
5
1 2 -5 4 3

10
3 6 0 5 1 3 7 3 4 1
*/
