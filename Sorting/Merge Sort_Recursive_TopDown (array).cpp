/**
The top-down merge sort approach is the methodology which uses recursion mechanism. It starts at the Top and proceeds downwards.

Time:
The list of size N is divided into a max of (log N) parts
and the merging of all sublists into a single list takes O(N) time.
Worst case: O(N log N)

Space:
O(N)
(it can be done using O(1) space complexity but modifying _merge function. keep 2 values in 1 index of array, so don't need temp[] array)

Stable
(If duplicate values are given as input, output will maintain given input order)
Not Adaptive
(A sorting algorithm falls into the adaptive sort family if it takes advantage of existing order in its input)


Resources:
https://www.interviewbit.com/tutorial/merge-sort-algorithm/

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

void _mergeSort(int ar[], int low, int high)
{
    if(low < high)    // it means there are more than 1 elements
    {
        int mid = low+(high-low)/2;

        _mergeSort(ar, low, mid);
        _mergeSort(ar, mid+1, high);

        _merge(ar, low, mid, high);
    }
}

int main()
{
    int ar[MX],sz;
    cout<<"Give size of the array: ";
    cin>>sz;
    cout<<"Give elements of array: ";
    for(int i=0;i<sz;i++) cin>>ar[i];

    _mergeSort(ar, 0, sz-1);
    cout<<"after sorting: ";
    for(int i=0;i<sz;i++) cout<<ar[i]<<" ";
    cout<<endl;
}

/*
5
1 2 -5 4 3
*/
